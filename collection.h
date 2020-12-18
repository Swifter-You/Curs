#ifndef COLLECTION_H
#define COLLECTION_H
#include <figure.h>
#include <string>
#include <iostream>
#include <sstream>

class Queue {
    //friend void output(Collection &value);
    friend class MainWindow;
protected:
    struct Node {
        Node *next{nullptr};
        Figure *d;
        ~Node() {
            if (d){
                delete d;
            }
        };
    };
    Node *first{nullptr};
    Node *last{nullptr};
    int size{0};
public:
    Queue() = default;
    Queue(const Queue &other);
    Queue(Figure* fig);
    ~Queue();
    void push(Figure *value);
    bool compare(const Queue& _other);
    void pop();
    Figure* get_first();
    const Figure* get_first() const;
    Figure* get_last();
    const Figure* get_last() const;
    int getSize() const;
    void pop_all();
    bool empty() const;
    void outputFromFile(const std::string &file_name)const;
    void writeToFile(const std::string& filename);
    Node* back() const;
    Node* front() const;
};

void PrintQueue(Queue* _other);

#endif // COLLECTION_H

