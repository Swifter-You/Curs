#ifndef SQUARE_H
#define SQUARE_H
#include "figure.h"

class Square: public Figure
{
public:
    Square();
    Square(double a);

    bool operator == (const Square& a);
    // flag false, если все числа больше нуля
    bool operator < (const Square& a);

    void setA(double a);
    void setD(double d);

    double getA();
    double getD();

    double findAreaA();
    double findAreaD();

    double findPerimeterA();

    // шаблонная функция
    template <typename T>
    T findPerimeter(){
        return a_*4;
    }

    // шаблонная функция
    template <typename T>
    T findArea(){
        return a_*a_;
    }

    virtual std::string get_class() override;

private:
    double a_;
    double d_;
};

#endif // SQUARE_H
