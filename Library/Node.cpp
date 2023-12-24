#include "Node.h"

/**
 * @brief Конструктор узла.
 * @param value Значение узла.
 * @param next Указатель на следующий узел (по умолчанию nullptr).
 */
Node::Node(size_t value, Node* next) : element(value), pNext(next) {}