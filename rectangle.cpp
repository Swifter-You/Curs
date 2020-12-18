#include "rectangle.h"

Rectangle::Rectangle()
{

}

Rectangle::Rectangle(double a, double b){
    setA(a);
    setB(b);
}

void Rectangle::setA(double a){a_=a;}

void Rectangle::setB(double b){b_=b;}

bool Rectangle::operator ==(const Rectangle &a){
    bool flag = true;
    if (this->a_ != a.a_) flag = false;
    if (this->b_ != a.b_) flag = false;
    return flag;
}

bool Rectangle::operator <(const Rectangle &a){
    bool flag = false;
    if (a.a_ < 0) flag = true;
    if (a.b_ < 0) flag = true;
    return flag;
}

double Rectangle::findAreaAB(){
    return a_*b_;
}

double Rectangle::findPerimeterAB(){
    return 2*(a_+b_);
}

double Rectangle::getA(){return a_;}

double Rectangle::getB(){return b_;}

std::string Rectangle::get_class() {return "Rectangle";}
