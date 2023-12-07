#include <stdlib.h>
#include "Header.h"
#include <iostream>
#include <initializer_list>

Queue::Queue()
{
    front = nullptr;
    rear = nullptr;
}

Queue::Queue(const Queue& other)
{
    Node* temp = other.front;
    while (temp)
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

void Queue::enqueue(size_t x)
{
    Node* temp = new Node;
    temp->element = x;
    temp->pNext = nullptr;

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

void Queue::print_Queue()
{
    Node* temp = front;
    while (temp != nullptr)
    {
        std::cout << temp->element << " ";
        temp = temp->pNext;
    }
    std::cout << " ";
}

int Queue::peek()
{
    if (front != nullptr) {
        front->element;
    }
    else {
        throw;
    }

}

int Queue::size()
{
    int i = 0;
    Node* temp = front;
    if (temp != nullptr)
    {
        while (temp != nullptr)
        {
            temp = temp->pNext;
            i++;
        }
        return i;
    }
    else
        return 0;
}

bool Queue::isEmpty() {

    return rear == nullptr && front == nullptr;
}

const Queue& Queue::operator=(const Queue& other)
{
    if (this != &other)
    {
        Node* temp = front;
        while (temp)
        {
            front = front->pNext;
            delete temp;
            temp = front;
        }

        temp = other.front;
        while (temp)
        {
            enqueue(temp->element);
            temp = temp->pNext;
        }
    }

    return *this;
}