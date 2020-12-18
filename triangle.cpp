#include "triangle.h"

Triangle::Triangle()
{

}

bool Triangle::check()
{
    bool flag = true;

    if ((a_ > 0) && (b_ > 0) && (c_ > 0)){
        if (a_>b_+c_){
            flag = false;
        }
        if (b_>a_+c_){
            flag = false;
        }
        if (c_>a_+b_){
            flag = false;
        }
    }
    return flag;
}

bool Triangle::operator ==(const Triangle &a){
    bool flag = true;
    if (this->a_ != a.a_) flag = false;
    if (this->b_ != a.b_) flag = false;
    if (this->c_ != a.c_) flag = false;
    if (this->h_ != a.h_) flag = false;
    return flag;
}

bool Triangle::operator <(const Triangle &a){
    bool flag = false;
    if (a.a_ < 0) flag = true;
    if (a.b_ < 0) flag = true;
    return flag;
}

void Triangle::setA(double a){a_ = a;}

void Triangle::setB(double b){b_ = b;}

void Triangle::setC(double c){c_ = c;}

void Triangle::setH(double h){h_ = h;}

double Triangle::findAreaAH(){return a_*h_/2;}

double Triangle::findAreaABC(){
    double p = (a_+b_+c_)/2;
    double s = sqrt(p*(p-a_)*(p-b_)*(p-c_));
    std::cout<<s<<std::endl;
    return s;
}

double Triangle::findPerimeterABC()
{
    return a_+b_+c_;
}

std::string Triangle::get_class() {return "Triangle";}

