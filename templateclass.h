#ifndef TEMPLATECLASS_H
#define TEMPLATECLASS_H
#include <figure.h>

template <typename T>
class TemplateClass : public Figure
{
public:
    TemplateClass() = default;

    T getA(){return a_;};
    T getB(){return b_;};
    T getC(){return c_;};
    T getH(){return h_;};

    bool operator [] (int index) const{
        if (index < 0 || index >=2) throw "error";
        return arr[index];
    };

    bool operator == (const TemplateClass& a){
        bool flag = true;
        if (this->a_ != a.a_) flag = false;
        if (this->b_ != a.b_) flag = false;
        if (this->c_ != a.c_) flag = false;
        if (this->d_ != a.d_) flag = false;
        return flag;
    };

private:
    T a_;
    T b_;
    T c_;
    T h_;

    T arr[10];
};

#endif // TEMPLATECLASS_H
