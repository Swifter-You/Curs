#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <string>
#include <iostream>
#include <string>
#include <cmath>
#include <QGraphicsView>
#include <QMessageBox>
#include "windows.h"
#include "collection.h"
#include "figure.h"
#include "triangle.h"
#include "square.h"
#include "rectangle.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    coll = new Queue();
    ui->setupUi(this);

    setWindowTitle("Калькулятор геометрических фигур");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_comboBox_activated(const QString &arg1)
{ // выбор фигуры в комбобоксе и включение определенных полей для ввода данных
    if (arg1 == "Треугольник"){
        ui->lineEdit_a->setEnabled(true);
        ui->lineEdit_b->setEnabled(true);
        ui->lineEdit_c->setEnabled(true);
        ui->lineEdit_h->setEnabled(true);
        ui->label_2->setText("h:");


        ui->textEdit_output->setText("Для поиска площади треугольника введите только: \n - основание и высоту (a, h); \n - три стороны (a, b, c);\nДля поиска периметра треугольника введите только: \n - три стороны (a, b, c);");
    }
    if (arg1 == "Квадрат"){
        ui->lineEdit_a->setEnabled(true);
        ui->lineEdit_b->setEnabled(false);
        ui->lineEdit_c->setEnabled(false);
        ui->label_2->setText("d:");
        ui->lineEdit_h->setEnabled(true);


        ui->textEdit_output->setText("Для поиска площади квадрата введите только:\n - сторону квадрата (a);\n - диагональ квадрата (d); \nДля поиска периметра квадрата введите только:\n - сторону квадрата (a);");
    }

    if (arg1 == "Прямоугольник"){
        ui->lineEdit_a->setEnabled(true);
        ui->lineEdit_b->setEnabled(true);
        ui->lineEdit_c->setEnabled(false);
        ui->lineEdit_h->setEnabled(false);
        ui->label_2->setText("h:");


        ui->textEdit_output->setText("Для поиска площади или периметра прямоугольника введите только:\n - две стороны прямоугольника (a, b);");
    }

    if (arg1 == "Выберите фигуру"){
        ui->lineEdit_a->setEnabled(false);
        ui->lineEdit_b->setEnabled(false);
        ui->lineEdit_c->setEnabled(false);
        ui->lineEdit_h->setEnabled(false);
        ui->label_2->setText("h:");

        ui->textEdit_output->clear();
    }

}

void MainWindow::on_pushButton_area_clicked()
{

    if (ui->comboBox->currentIndex() == 1){ // выбран треугольник

        Triangle tr;

        // сохраняем а
        QString text = ui->lineEdit_a->text();
        double a = text.toDouble();
        tr.setA(a);
        std::cout<<"a: "<<a<<std::endl;
        // сохраняем b
        text = ui->lineEdit_b->text();
        double b = text.toDouble();
        tr.setB(b);
        std::cout<<"b: "<<b<<std::endl;
        // сохраняем b
        text = ui->lineEdit_c->text();
        double c = text.toDouble();
        tr.setC(c);
        std::cout<<"c: "<<c<<std::endl;
        // сохраняем h
        text = ui->lineEdit_h->text();
        double h = text.toDouble();
        tr.setH(h);
        std::cout<<"h: "<<h<<std::endl;

        // поиск площади
        if ((a>0)&&(h>0)){
            tr.setArea(tr.findAreaAH());
            coll->push(&tr);
        } else if ((a>0)&&(b>0)&&(c>0)){
            tr.setArea(tr.findAreaABC());
            coll->push(&tr);
        }

        if ((tr.getArea() <= 0) || !(tr.check())) {
            ui->lineEdit_area->clear();
            QMessageBox msgBox;
            msgBox.setText("Проверьте данные на корректность!");
            msgBox.exec();
        } else {
            std::cout<<tr.getArea()<<std::endl;

            std::string str = std::to_string(tr.getArea());
            text = QString::fromStdString(str);

            ui->lineEdit_area->setText(text);

            QString item = QString("# Треугольник")
                        +QString("\n")
                        +QString("Площадь: ")
                        +QString(std::to_string(tr.getArea()).c_str())
                        +QString("\n");
            ui->textEdit_history->append(item);
        }

    } else if (ui->comboBox->currentIndex() == 2){ // выбран квадрат

        Square sq;

        // сохраняем а
        QString text = ui->lineEdit_a->text();
        double a = text.toDouble();
        sq.setA(a);
        std::cout<<"a: "<<a<<std::endl;

        // сохраняем d
        text = ui->lineEdit_h->text();
        double d = text.toDouble();
        sq.setD(d);
        std::cout<<"d: "<<d<<std::endl;

        // поиск площади
        if (sq.getA() > 0){
            sq.setArea((sq.findAreaA()));
            coll->push(&sq);


            std::string str = std::to_string(sq.getArea());
            text = QString::fromStdString(str);

            ui->lineEdit_area->setText(text);

            QString item = QString("# Квадрат")
                        +QString("\n")
                        +QString("Площадь: ")
                        +QString(std::to_string(sq.getArea()).c_str())
                        +QString("\n");
            ui->textEdit_history->append(item);

        } else if (sq.getD()>0){
            sq.setArea((sq.findAreaD()));
            coll->push(&sq);

            std::string str = std::to_string(sq.getArea());
            text = QString::fromStdString(str);

            ui->lineEdit_area->setText(text);

            QString item2 = QString("# Квадрат")
                        +QString("\n")
                        +QString("Площадь: ")
                        +QString(std::to_string(sq.getArea()).c_str())
                        +QString("\n");
            ui->textEdit_history->append(item2);
        }
        else {
            ui->lineEdit_area->clear();
            QMessageBox msgBox;
            msgBox.setText("Проверьте данные на корректность!");
            msgBox.exec();
        }

    } else if (ui->comboBox->currentIndex() == 3){ // выбран прямоугольник

        class Rectangle rg;

        // сохраняем а
        QString text = ui->lineEdit_a->text();
        double a = text.toDouble();
        rg.setA(a);
        std::cout<<"a: "<<a<<std::endl;

        // сохраняем b
        text = ui->lineEdit_b->text();
        double b = text.toDouble();
        rg.setB(b);
        std::cout<<"b: "<<b<<std::endl;

        // поиск площади
        if ((rg.getB() > 0) && (rg.getA() > 0)){
            rg.setArea((rg.findAreaAB()));
            coll->push(&rg);

            std::string str = std::to_string(rg.getArea());
            text = QString::fromStdString(str);
            ui->lineEdit_area->setText(text);

            QString item = QString("# Прямоугольник")
                        +QString("\n")
                        +QString("Площадь: ")
                        +QString(std::to_string(rg.getArea()).c_str())
                        +QString("\n");
            ui->textEdit_history->append(item);
        } else {
            ui->lineEdit_area->clear();
            QMessageBox msgBox;
            msgBox.setText("Проверьте данные на корректность!");
            msgBox.exec();
        }
    }

}

void MainWindow::on_pushButton_clicked() {
    ui->textEdit_history->clear();

   /* auto tmp = coll->first;

    for(int i=0;i<coll->getSize();++i) {
        if (tmp->d->get_class() == "Square"){

            Square *obj = new Square;
            obj = dynamic_cast<Square*>(tmp->d);

            QString item = QString("#")
                        +QString(std::to_string(i+1).c_str())
                        +QString("\n")
                        +QString("Square")
                        +QString("\n")
                        +QString(std::to_string(obj->getArea()).c_str())
                        +QString("\n")
                        +QString(std::to_string(obj->getPerimeter()).c_str())
                        +QString("\n");
            ui->textEdit_history->append(item);



        } else {
            if (tmp->d->get_class() == "Triangle"){

                Triangle *obj = new Triangle;
                obj = dynamic_cast<Triangle*>(tmp->d);

                QString item = QString("#")
                            +QString(std::to_string(i+1).c_str())
                            +QString("\n")
                            +QString("Triangle")
                            +QString("\n")
                            +QString(std::to_string(obj->getArea()).c_str())
                            +QString("\n")
                            +QString(std::to_string(obj->getPerimeter()).c_str())
                            +QString("\n");
                ui->textEdit_history->append(item);


            }
            else {
                class Rectangle *obj = new class Rectangle;
                obj = dynamic_cast<class Rectangle*>(tmp->d);

                QString item = QString("#")
                            +QString(std::to_string(i+1).c_str())
                            +QString("\n")
                            +QString("Rectangle")
                            +QString("\n")
                           +QString(std::to_string(obj->getArea()).c_str())
                            +QString("\n")
                            +QString(std::to_string(obj->getPerimeter()).c_str())
                            +QString("\n");
                ui->textEdit_history->append(item);
            }
        }
        tmp = tmp->next;
    }*/

}

//void MainWindow::on_pushbutton_clicked() {          КНОПКА ОТЧИСТИТЬ
//    ui->textEdit_history->clear()
//}

void MainWindow::on_pushButton_perimeter_clicked()
{
    if (ui->comboBox->currentIndex() == 1){ // выбран треугольник

        Triangle tr;

        // сохраняем а
        QString text = ui->lineEdit_a->text();
        double a = text.toDouble();
        tr.setA(a);
        std::cout<<"a: "<<a<<std::endl;
        // сохраняем b
        text = ui->lineEdit_b->text();
        double b = text.toDouble();
        tr.setB(b);
        std::cout<<"b: "<<b<<std::endl;
        // сохраняем b
        text = ui->lineEdit_c->text();
        double c = text.toDouble();
        tr.setC(c);
        std::cout<<"c: "<<c<<std::endl;
        // сохраняем h
        text = ui->lineEdit_h->text();
        double h = text.toDouble();
        tr.setH(h);
        std::cout<<"h: "<<h<<std::endl;

        // поиск периметра
        if ((a>0) && (b>0) && (c>0)){
            tr.setPerimeter(tr.findPerimeterABC());
            coll->push(&tr);

            std::string str = std::to_string(tr.getPerimeter());
            text = QString::fromStdString(str);

            ui->lineEdit_perimeter->setText(text);

            QString item = QString("# Треугольник")
                        +QString("\n")
                        +QString("Периметр: ")
                        +QString(std::to_string(tr.getPerimeter()).c_str())
                        +QString("\n");
            ui->textEdit_history->append(item);
        } else {
                QMessageBox msgBox;
                msgBox.setText("Проверьте данные на корректность!");
                msgBox.exec();
        }

        if (!(tr.check())){
            ui->lineEdit_perimeter->clear();
            QMessageBox msgBox;
            msgBox.setText("Проверьте данные на корректность!");
            msgBox.exec();
        }
    }else if (ui->comboBox->currentIndex() == 2){ // выбран квадрат

        Square sq;

        // сохраняем а
        QString text = ui->lineEdit_a->text();
        double a = text.toDouble();
        sq.setA(a);
        std::cout<<"a: "<<a<<std::endl;

        // поиск периметра
        if (sq.getA() > 0){
            sq.setPerimeter((sq.findPerimeterA()));
            coll->push(&sq);

            std::string str = std::to_string(sq.getPerimeter());
            text = QString::fromStdString(str);

            ui->lineEdit_perimeter->setText(text);

            QString item = QString("# Квадрат")
                        +QString("\n")
                        +QString("Периметр: ")
                        +QString(std::to_string(sq.getPerimeter()).c_str())
                        +QString("\n");
            ui->textEdit_history->append(item);
        } else {
            ui->lineEdit_perimeter->clear();
            QMessageBox msgBox;
            msgBox.setText("Проверьте данные на корректность!");
            msgBox.exec();
        }

    }else if (ui->comboBox->currentIndex() == 3){ // выбран прямоугольник

        class Rectangle rg;

        // сохраняем а
        QString text = ui->lineEdit_a->text();
        double a = text.toDouble();
        rg.setA(a);
        std::cout<<"a: "<<a<<std::endl;

        // сохраняем b
        text = ui->lineEdit_b->text();
        double b = text.toDouble();
        rg.setB(b);
        std::cout<<"b: "<<b<<std::endl;

        // поиск периметра
        if ((rg.getB() > 0) && (rg.getA() > 0)){
            rg.setPerimeter((rg.findPerimeterAB()));
            coll->push(&rg);
            std::string str = std::to_string(rg.getPerimeter());
            text = QString::fromStdString(str);

            ui->lineEdit_perimeter->setText(text);

            QString item = QString("# Прямоугольник")
                        +QString("\n")
                        +QString("Периметр: ")
                        +QString(std::to_string(rg.getPerimeter()).c_str())
                        +QString("\n");
            ui->textEdit_history->append(item);
        } else {
            ui->lineEdit_perimeter->clear();
            QMessageBox msgBox;
            msgBox.setText("Проверьте данные на корректность!");
            msgBox.exec();
        }

    }

}

void MainWindow::on_lineEdit_c_textChanged(const QString &arg1)
{
    if (ui->comboBox->currentIndex()==1) {
        ui->lineEdit_h->setDisabled(true);
        ui->lineEdit_h->setText("");
    }
    if ((ui->comboBox->currentIndex()==1)&&(arg1 == "")) {
            ui->lineEdit_h->setEnabled(true);
        }
    ui->lineEdit_area->setText("");
    ui->lineEdit_perimeter->setText("");
}

void MainWindow::on_lineEdit_h_textChanged(const QString &arg1)
{
    if (ui->comboBox->currentIndex()==1) {
        ui->lineEdit_b->setDisabled(true);
        ui->lineEdit_c->setDisabled(true);
        ui->lineEdit_b->setText("");
        ui->lineEdit_c->setText("");

        ui->pushButton_perimeter->setDisabled(true);
    }
    if ((ui->comboBox->currentIndex()==1)&&(arg1 == "")) {
            ui->lineEdit_b->setEnabled(true);
            ui->lineEdit_c->setEnabled(true);
            ui->pushButton_perimeter->setEnabled(true);
        }
    ui->lineEdit_area->setText("");
    ui->lineEdit_perimeter->setText("");

    if (ui->comboBox->currentIndex()==2){
        ui->lineEdit_a->setDisabled(true);
        ui->pushButton_perimeter->setDisabled(true);
    }
    if (arg1==""){
        ui->lineEdit_a->setEnabled(true);
        ui->pushButton_perimeter->setEnabled(true);
    }
}

void MainWindow::on_lineEdit_b_textChanged(const QString &arg1)
{
    ui->lineEdit_area->setText("");
    ui->lineEdit_perimeter->setText("");
}

void MainWindow::on_lineEdit_a_textChanged(const QString &arg1)
{
    ui->lineEdit_area->setText("");
    ui->lineEdit_perimeter->setText("");

    if (ui->comboBox->currentIndex()==2){
        ui->lineEdit_h->setDisabled(true);
    }
    if (arg1==""){
        ui->lineEdit_h->setEnabled(true);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->lineEdit_a->clear();
    ui->lineEdit_b->clear();
    ui->lineEdit_c->clear();
    ui->lineEdit_h->clear();
    ui->lineEdit_area->clear();
    ui->lineEdit_perimeter->clear();

    if (ui->comboBox->currentIndex() == 1){
        ui->lineEdit_a->setEnabled(true);
        ui->lineEdit_b->setEnabled(true);
        ui->lineEdit_c->setEnabled(true);
        ui->lineEdit_h->setEnabled(true);
        ui->label_2->setText("h:");


        ui->textEdit_output->setText("Для поиска площади треугольника введите только: \n - основание и высоту (a, h); \n - три стороны (a, b, c);\nДля поиска периметра треугольника введите только: \n - три стороны (a, b, c);");
    }
    if (ui->comboBox->currentIndex() == 2){
        ui->lineEdit_a->setEnabled(true);
        ui->lineEdit_b->setEnabled(false);
        ui->lineEdit_c->setEnabled(false);
        ui->label_2->setText("d:");
        ui->lineEdit_h->setEnabled(true);

        ui->textEdit_output->setText("Для поиска площади квадрата введите только:\n - сторону квадрата (a);\n - диагональ квадрата (d); \nДля поиска периметра квадрата введите только:\n - сторону квадрата (a);");
    }

    if (ui->comboBox->currentIndex() == 3){
        ui->lineEdit_a->setEnabled(true);
        ui->lineEdit_b->setEnabled(true);
        ui->lineEdit_c->setEnabled(false);
        ui->lineEdit_h->setEnabled(false);
        ui->label_2->setText("h:");


        ui->textEdit_output->setText("Для поиска площади или периметра прямоугольника введите только:\n - две стороны прямоугольника (a, b);");
    }

    if (ui->comboBox->currentIndex() == 0){
        ui->lineEdit_a->setEnabled(false);
        ui->lineEdit_b->setEnabled(false);
        ui->lineEdit_c->setEnabled(false);
        ui->lineEdit_h->setEnabled(false);
        ui->label_2->setText("h:");

        ui->textEdit_output->clear();
    }
}
