#ifndef NODE_H
#define NODE_H

#include <cstddef>

struct Node
{
    size_t element;
    Node* pNext;

    Node(size_t value, Node* next = nullptr);
};

#endif