#include "mainwindow.h"
#include <iostream>
#include "figure.h"
#include "triangle.h"
#include "collection.h"
#include "square.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // тесты
    /*std::cout<<"Hello world!"<<std::endl;
    Square b;
    Square s;
    Triangle h;
    s.setArea(123);
    b.setArea(132);
    h.setArea(321);
    Queue c;
    std::cout << c.getSize() << std::endl;
    c.push(&b);
    std::cout << c.getSize() << std::endl;
    c.push(&s);
    std::cout << c.getSize() << std::endl;
    PrintQueue(&c);

    if (b == s){
        std::cout<<"Equal"<<std::endl;
    } else std::cout<<"Unequal"<<std::endl;*/

    return a.exec();
}
