#include "Node.h"

/**
 * @brief ����������� ����.
 * @param value �������� ����.
 * @param next ��������� �� ��������� ���� (�� ��������� nullptr).
 */
Node::Node(size_t value, Node* next) : element(value), pNext(next) {}