#include <stdlib.h>
#include "Queue.h"
#include <iostream>

Queue::Queue()
{
    front = nullptr;
    rear = nullptr;
}

Queue::Queue(const Queue& other)
{
    Node* temp = other.front;
    while (temp != nullptr)
    {
        enqueue(temp->element);
        temp = temp->pNext;
    }
}

Queue::Queue(std::initializer_list<size_t> list) {
    front = nullptr;
    rear = nullptr;
    for (const auto& temp : list) {
        enqueue(temp);
    }
}

Queue::~Queue()
{
    Node* temp = front;
    while (temp != nullptr)
    {
        temp = front->pNext;
        delete front;
        front = temp;
    }
}

void Queue::enqueue(size_t item)
{
    Node* temp = new Node(item);

    if (front != nullptr)
    {
        rear->pNext = temp;
        rear = temp;
    }
    else
    {
        front = temp;
        rear = temp;
    }
}

void Queue::dequeue()
{
    if (front != nullptr)
    {
        Node* temp = front;
        front = front->pNext;
        delete temp;
    }
}

int Queue::peek()
{
    if (front != nullptr) {
        front->element;
    }
    else {
        throw std::runtime_error("Queue is empty");
    }

}

int Queue::size()
{
    int i = 0;
    Node* temp = front;
    while (temp != nullptr){
        temp = temp->pNext;
        i++;
    }
    return i;

}

bool Queue::isEmpty() {

    return rear == nullptr && front == nullptr;
}

const Queue& Queue::operator=(const Queue& other)
{
    if (this != &other)
    {
        Node* temp = front;
        while (temp != nullptr)
        {
            front = front->pNext;
            delete temp;
            temp = front;
        }

        temp = other.front;
        while (temp != nullptr)
        {
            enqueue(temp->element);
            temp = temp->pNext;
        }
    }

    return *this;
}

std::ostream& Queue::operator<<(std::ostream& os) {
    Node* temp = front;
    while (temp != nullptr)
    {
        os << temp->element << " ";
        temp = temp->pNext;
    }
    return os;
}

std::istream& Queue::operator>>(std::istream& is) {
    size_t value;
    while (is >> value)
    {
        enqueue(value);
    }
    return is;
}