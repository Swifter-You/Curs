#ifndef FIGURE_H
#define FIGURE_H
#include "string"


class Figure
{
public:
    Figure();

    double getPerimeter();
    double getArea();
    void setPerimeter(double perimeter);
    void setArea(double area);
    void setPoint(double x,double y);;

    virtual std::string get_class();

private:
    double perimeter_;
    double area_;

    struct point{
        double x_;
        double y_;
    };

    point arrayPoints[4];


};

#endif // FIGURE_H
