#include "collection.h"
#include <fstream>
#include "rectangle.h"
#include "square.h"
#include "triangle.h"
#include "iostream"
#include "string.h"

Queue::Queue(const Queue &other)
{
    Node *tmp = other.first;
    for (int i=0;i<other.size;++i) {
        push(tmp->d);
        tmp = tmp->next;
    }
    size = other.size;
}

Queue::Queue(Figure* fig){
    this->push(fig);
}

Queue::~Queue()
{
    pop_all();
}

void Queue::push(Figure *value)
{
    if (size == 0) {
        auto tmp = new Node;
        first = last = tmp;
        if (value->get_class() == "Square"){
            tmp->d = new Square(*(Square*)value);
        } else if (value->get_class()== "Triangle") {
            tmp->d = new Triangle(*(Triangle*)value);
        }
            else
            tmp->d = new Rectangle(*(Rectangle*)value);
    } else {
        auto tmp = new Node;
        if (value->get_class() == "Square"){
            tmp->d = new Square(*(Square*)value);
        } else if (value->get_class()== "Triangle") {
            tmp->d = new Triangle(*(Triangle*)value);
        }
            else
            tmp->d = new Rectangle(*(Rectangle*)value);
        last->next = tmp;
        last = tmp;
    }
    ++size;
}

void Queue::pop()
{
    if (size != 0) {
        auto tmp = first;
        first = first->next;
        delete tmp;
        --size;
        if (size == 0){
            last = nullptr;
        }
    }
}

Figure* Queue::get_first()
{
    return first->d;
}

const Figure* Queue::get_first() const
{
    return first->d;
}

Figure* Queue::get_last()
{
    return last->d;
}

const Figure* Queue::get_last() const
{
    return last->d;
}

int Queue::getSize() const
{
    return size;
}

void Queue::pop_all()
{
    int a = size;
    for (int i=0;i<a;i++) {
        pop();
    }
}

void Queue::outputFromFile(const std::string &file_name)const
{

}

bool Queue::compare(const Queue &_other) {
    if (empty() && _other.empty()){
        return 1;
    }
    else if (getSize()==_other.getSize()){
        Node* tmp1=front();
        Node* tmp2=_other.front();
        while (tmp1 && tmp2){
            if (tmp1->d->getArea()!=tmp2->d->getArea() || tmp1->d->getPerimeter()!=tmp2->d->getPerimeter()){
                return 0;
            }
            tmp1=tmp1->next;
            tmp2=tmp2->next;
        }
        return 1;
    } else return 0;
}

//void Queue::writeToFile(const std::string &filename) {
//    std::ofstream out;
//    int count=1;
//    out.open(filename+"txt");
//    if (out.is_open()){
//        Node* tmp=front();
//        while(tmp){
//            fout << "#" << count << std::endl;
//            fout << tmp->d->get_class() << std::endl;
//            if (tmp->d->getArea()==0)
//                fout << "Perim: " << tmp->d->getPerimeter() << std::endl;
//            else if (tmp->d->getPerimeter()==0)
//                fout << "Area: " << tmp->d->getArea() << std::endl;
//            else {
//                fout << "Area: " << tmp->d->getArea() << std::endl;
//                fout << "Perim: " << tmp->d->getPerimeter() << std::endl;
//            }
//            count++;
//            tmp=tmp->next;
//        }
//    }
//    out.close();
//}

Queue::Node* Queue::back() const {
    if (!this->empty()){
        Node* tmp=this->first;
        while (tmp->next)
            tmp=tmp->next;
        return tmp;
    }
    exit(1);
}

Queue::Node* Queue::front() const {
    if (!this->empty())
        return this->first;
    return nullptr;
}


bool Queue::empty() const {
    return (!this->first);
}

void PrintQueue(Queue* _other) {
    auto tmp = _other->front();
    int cnt = 1;
    std::cout <<"\n";
    while (tmp) {
        std::cout << "#" << cnt << std::endl;
        std::cout << tmp->d->get_class() << std::endl;
        std::cout << tmp->d->getArea() << std::endl;
        cnt++;
        tmp=tmp->next;

   }
}

