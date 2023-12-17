#ifndef Queue_H
#define Queue_H

#include <initializer_list>
#include <iostream>

#include "Node.h"

class Queue
{
private:
    Node* front;
    Node* rear;
public:
    Queue();
    Queue(const Queue& other);
    Queue(std::initializer_list<size_t> list);
    ~Queue();
    void dequeue();
    void enqueue(size_t item);
    int peek();
    int size();
    bool isEmpty();
    const Queue& operator=(const Queue& other);
    std::ostream& operator<<(std::ostream& os);
    std::istream& operator>>(std::istream& is);

};

#endif