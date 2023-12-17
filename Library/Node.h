#ifndef NODE_H
#define NODE_H

#include <cstddef>

/**
 * @brief ��������� ���� ��� ������������� � �������.
 */
struct Node
{
    size_t element; ///< ������� ����.
    Node* pNext;    ///< ��������� �� ��������� ����.

    /**
     * @brief ����������� ����.
     * @param value �������� ����.
     * @param next ��������� �� ��������� ���� (�� ��������� nullptr).
     */
    Node(size_t value, Node* next = nullptr);
};

#endif