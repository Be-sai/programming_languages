#ifndef NODE_H
#define NODE_H

#include <cstddef>

/**
 * @brief Структура узла для использования в очереди.
 */
struct Node
{
    size_t element; ///< Элемент узла.
    Node* pNext;    ///< Указатель на следующий узел.

    /**
     * @brief Конструктор узла.
     * @param value Значение узла.
     * @param next Указатель на следующий узел (по умолчанию nullptr).
     */
    Node(size_t value, Node* next = nullptr);
};

#endif