#ifndef Queue_H
#define Queue_H

#include <initializer_list>
#include <iostream>

#include "Node.h"

/**
 * @brief ����� ��� ���������� �������.
 */
class Queue
{
private:
    Node* front;    ///< ��������� �� ������ �������.
    Node* rear; ///< ��������� �� ����� �������.
public:
    /**
     * @brief ����������� �� ���������.
     */
    Queue();

    /**
     * @brief ����������� �����������.
     * @param other ������ ������ �������.
     */
    Queue(const Queue& other);

    /**
     * @brief ����������� � �������������� ������ �������������.
     * @param list ������ �������������.
     */
    Queue(std::initializer_list<size_t> list);
    
    /**
     * @brief ����������.
     */
    ~Queue();

    /**
     * @brief �������� �������� �� ������ �������.
     */
    void dequeue();

    /**
     * @brief ���������� �������� � ����� �������.
     * @param item ������� ��� ����������.
     */
    void enqueue(size_t item);

    /**
     * @brief ��������� �������� ������� �������� �������.
     * @return �������� ������� �������� �������.
     */
    int peek();

    /**
     * @brief ��������� ������� �������.
     * @return ������ �������.
     */
    int size();

    /**
     * @brief ��������, ����� �� �������.
     * @return true, ���� ������� �����, ����� false.
     */
    bool isEmpty();

    /**
     * @brief �������� ������������.
     * @param other ������ ������ �������.
     * @return ������ �� ������� ������.
     */
    const Queue& operator=(const Queue& other);

    /**
     * @brief �������� ������ � �����.
     * @param os ����� ������.
     * @return ������ �� ����� ������.
     */
    std::ostream& operator<<(std::ostream& os);

    /**
     * @brief �������� ����� �� ������.
     * @param is ����� �����.
     * @return ������ �� ����� �����.
     */
    std::istream& operator>>(std::istream& is);

};

#endif