#include <iostream>
#include "..\Library\Queue.h"

int main()
{
	Queue q;
	q.enqueue(4);
	q.enqueue(8);
	q.dequeue();
	q.peek();
	q.size();
	Queue qu;
	qu = q;
	Queue que{ 1,2,3 };

}