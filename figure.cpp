#include "figure.h"

Figure::Figure()
{

}

double Figure::getPerimeter(){return perimeter_;}

double Figure::getArea(){return area_;}

void Figure::setPerimeter(double perimeter){perimeter_=perimeter;}

void Figure::setArea(double area){area_=area;}

void Figure::setPoint(double x, double y){

}

std::string Figure::get_class() {return "Figure";}


