#include "square.h"

Square::Square()
{

}

Square::Square(double a)
{
    setA(a);
}

bool Square::operator ==(const Square &a){
    bool flag = true;
    if (this->a_ != a.a_) flag = false;
    if (this->d_ != a.d_) flag = false;
    return flag;
}

bool Square::operator <(const Square &a){
    bool flag = false;
    if (a.a_ < 0) flag = true;
    if (a.d_ < 0) flag = true;
    return flag;
}

void Square::setA(double a)
{
    a_=a;
}

void Square::setD(double d)
{
    d_=d;
}

double Square::getA(){return a_;}

double Square::getD(){return d_;}

double Square::findAreaA(){return a_*a_;}

double Square::findAreaD(){return d_*d_/2;}

double Square::findPerimeterA(){return a_*4;}

std::string Square::get_class() {return "Square";}
