#include <stdlib.h>
#include "Queue.h"
#include <iostream>

/**
 * @brief Конструктор по умолчанию.
 */
Queue::Queue() : front(nullptr), rear(nullptr) {}

/**
 * @brief Конструктор копирования.
 * @param other Другой объект очереди.
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
 * @brief Конструктор с использованием списка инициализации.
 * @param list Список инициализации.
 */
Queue::Queue(std::initializer_list<size_t> list) : front(nullptr), rear(nullptr) 
{
    for (const auto& temp : list) {
        enqueue(temp);
    }
}

/**
 * @brief Деструктор.
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
 * @brief Добавление элемента в конец очереди.
 * @param item Элемент для добавления.
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
 * @brief Удаление элемента из начала очереди.
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
 * @brief Получение значения первого элемента очереди.
 * @return Значение первого элемента очереди.
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
 * @brief Получение размера очереди.
 * @return Размер очереди.
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
 * @brief Проверка, пуста ли очередь.
 * @return true, если очередь пуста, иначе false.
 */
bool Queue::isEmpty() {

    return rear == nullptr && front == nullptr;
}

/**
 * @brief Оператор присваивания.
 * @param other Другой объект очереди.
 * @return Ссылка на текущий объект.
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
 * @brief Оператор вывода в поток.
 * @param os Поток вывода.
 * @return Ссылка на поток вывода.
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
 * @brief Оператор ввода из потока.
 * @param is Поток ввода.
 * @return Ссылка на поток ввода.
 */
std::istream& Queue::operator>>(std::istream& is) {
    size_t value;
    while (is >> value)
    {
        enqueue(value);
    }
    return is;
}