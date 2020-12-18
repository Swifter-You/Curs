#include "figure.h"
#include <cmath>
#include <iostream>
#ifndef TRIANGLE_H
#define TRIANGLE_H


class Triangle : public Figure
{
public:
    Triangle();
    Triangle(double a, double h);

    bool check(); // проверка на существование треугольника

    bool operator == (const Triangle& a);
    // flag false, если все числа больше нуля
    bool operator < (const Triangle& a);

    void setA(double a);
    void setB(double b);
    void setC(double c);
    void setH(double h);

    double getA() {return a_;};
    double getB() {return b_;};
    double getC() {return c_;};
    double getH() {return h_;};

    double findAreaAH();
    double findAreaABC();

    double findPerimeterABC();

    // шаблонная функция
    template <typename T>
    T findPerimeter(){
        return a_+b_+c_;
    }

    // шаблонная функция
    template <typename T>
    T findArea(){
        T p = (a_+b_+c_)/2;
        T s = sqrt(p*(p-a_)*(p-b_)*(p-c_));
        return s;
    }

    virtual std::string get_class() override;

private:
    double a_;
    double b_;
    double c_;
    double h_;
};

#endif // TRIANGLE_H
