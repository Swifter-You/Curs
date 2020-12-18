#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "figure.h"

class Rectangle : public Figure
{
public:
    Rectangle();
    Rectangle(double a, double b);;

    void setA(double a);
    void setB(double b);

    bool operator == (const Rectangle& a);
    // flag false, если все числа больше нуля
    bool operator < (const Rectangle& a);

    double findAreaAB();

    double findPerimeterAB();

    // шаблонная функция
    template <typename T>
    T findPerimeter(){
        return a_+b_;
    }

    // шаблонная функция
    template <typename T>
    T findArea(){
        return a_*b_;
    }


    double getA();
    double getB();

    virtual std::string get_class() override;

private:
    double a_;
    double b_;
};

#endif // RECTANGLE_H
