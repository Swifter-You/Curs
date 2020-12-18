#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "collection.h"
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Queue;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_area_clicked(); // площадь треугольника

    void on_pushButton_perimeter_clicked();

    void on_lineEdit_c_textChanged(const QString &arg1);

    void on_lineEdit_h_textChanged(const QString &arg1);

    void on_lineEdit_b_textChanged(const QString &arg1);

    void on_lineEdit_a_textChanged(const QString &arg1);

    void on_pushButton_2_clicked();

protected slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Queue *coll;
};
#endif // MAINWINDOW_H
