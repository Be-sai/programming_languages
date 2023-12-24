#ifndef Queue_H
#define Queue_H

#include <initializer_list>
#include <iostream>

#include "Node.h"

/**
 * @brief Класс для реализации очереди.
 */
class Queue
{
private:
    Node* front;    ///< Указатель на начало очереди.
    Node* rear; ///< Указатель на конец очереди.
public:
    /**
     * @brief Конструктор по умолчанию.
     */
    Queue();

    /**
     * @brief Конструктор копирования.
     * @param other Другой объект очереди.
     */
    Queue(const Queue& other);

    /**
     * @brief Конструктор перемещения.
     * @param other Другой объект очереди для перемещения.
     */
    Queue(Queue&& other) noexcept;


    /**
     * @brief Конструктор с использованием списка инициализации.
     * @param list Список инициализации.
     */
    Queue(std::initializer_list<size_t> list);
    
    /**
     * @brief Деструктор.
     */
    ~Queue();

    /**
     * @brief Удаление элемента из начала очереди.
     */
    void dequeue();

    /**
     * @brief Добавление элемента в конец очереди.
     * @param item Элемент для добавления.
     */
    void enqueue(size_t item);

    /**
     * @brief Получение значения первого элемента очереди.
     * @return Значение первого элемента очереди.
     */
    int peek();

    /**
     * @brief Получение размера очереди.
     * @return Размер очереди.
     */
    int size();

    /**
     * @brief Проверка, пуста ли очередь.
     * @return true, если очередь пуста, иначе false.
     */
    bool isEmpty();

    /**
     * @brief Оператор присваивания.
     * @param other Другой объект очереди.
     * @return Ссылка на текущий объект.
     */
    const Queue& operator=(const Queue& other);

    /**
     * @brief Оператор присваивания перемещением.
     * @param other Другой объект очереди для присваивания.
     * @return Ссылка на текущий объект.
     */
    Queue& operator=(Queue&& other) noexcept;

    /**
     * @brief Оператор вывода в поток.
     * @param os Поток вывода.
     * @return Ссылка на поток вывода.
     */
    std::ostream& operator<<(std::ostream& os);

    /**
     * @brief Оператор ввода из потока.
     * @param is Поток ввода.
     * @return Ссылка на поток ввода.
     */
    std::istream& operator>>(std::istream& is);

};

#endif