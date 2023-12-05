#include <iostream>
#include "..\Library\Header.h"

int main() 
{
	Queue q;
	q.enqueue(4);
	q.enqueue(8);
	q.dequeue();
	q.peek();
	q.size();
	q.print_Queue();
	Queue qu;
	qu = q;
	qu.print_Queue();
	Queue que{ 1,2,3 };
	que.print_Queue();

}