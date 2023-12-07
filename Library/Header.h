#ifndef Queue_H
#define Queue_H

#include <initializer_list>

struct Node
{
    size_t element;
    Node* pNext;
};

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
    void enqueue(size_t x);
    void print_Queue();
    int peek();
    int size();
    bool isEmpty();
    const Queue& operator=(const Queue& other);
};

#endif