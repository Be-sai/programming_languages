#include <stdlib.h>
#include "Queue.h"
#include <iostream>

/**
 * @brief ����������� �� ���������.
 */
Queue::Queue() : front(nullptr), rear(nullptr) {}

/**
 * @brief ����������� �����������.
 * @param other ������ ������ �������.
 */
Queue::Queue(const Queue& other)
{
    Node* temp = other.front;
    while (temp != nullptr)
    {
        enqueue(temp->element);
        temp = temp->pNext;
    }
}

Queue::Queue(Queue&& other) noexcept : front(other.front), rear(other.rear)
{
    other.front = nullptr;
    other.rear = nullptr;
}

/**
 * @brief ����������� � �������������� ������ �������������.
 * @param list ������ �������������.
 */
Queue::Queue(std::initializer_list<size_t> list) : front(nullptr), rear(nullptr) 
{
    for (const auto& temp : list) {
        enqueue(temp);
    }
}

/**
 * @brief ����������.
 */
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

/**
 * @brief ���������� �������� � ����� �������.
 * @param item ������� ��� ����������.
 */
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

/**
 * @brief �������� �������� �� ������ �������.
 */
void Queue::dequeue()
{
    if (front != nullptr)
    {
        Node* temp = front;
        front = front->pNext;
        delete temp;
    }
}

/**
 * @brief ��������� �������� ������� �������� �������.
 * @return �������� ������� �������� �������.
 */
int Queue::peek()
{
    if (front != nullptr) {
        return front->element;
    }
    else {
        throw std::runtime_error("Queue is empty");
    }

}

/**
 * @brief ��������� ������� �������.
 * @return ������ �������.
 */
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

/**
 * @brief ��������, ����� �� �������.
 * @return true, ���� ������� �����, ����� false.
 */
bool Queue::isEmpty() {

    return rear == nullptr && front == nullptr;
}

/**
 * @brief �������� ������������.
 * @param other ������ ������ �������.
 * @return ������ �� ������� ������.
 */
const Queue& Queue::operator=(const Queue& other)
{
    if (this != &other)
    {
        Queue temp(other);

        std::swap(this->front, temp.front);
        std::swap(this->rear, temp.rear);
    }

    return *this;
}

Queue& Queue::operator=(Queue&& other) noexcept
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

        front = other.front;
        rear = other.rear;

        other.front = nullptr;
        other.rear = nullptr;
    }

    return *this;
}

/**
 * @brief �������� ������ � �����.
 * @param os ����� ������.
 * @return ������ �� ����� ������.
 */
std::ostream& Queue::operator<<(std::ostream& os) {
    Node* temp = front;
    while (temp != nullptr)
    {
        os << temp->element << " ";
        temp = temp->pNext;
    }
    return os;
}

/**
 * @brief �������� ����� �� ������.
 * @param is ����� �����.
 * @return ������ �� ����� �����.
 */
std::istream& Queue::operator>>(std::istream& is) {
    size_t value;
    while (is >> value)
    {
        enqueue(value);
    }
    return is;
}