#include "stack.h"

Stack q1, q2;

int EnQueue(int x) {
	if(Push(q1, x)) {
		printf("EnQueue success!\n");
		return 1;
	}
	return 0;
}

int DeQueue() {
	int x;
	if(!StackEmpty(q2)) {
		x = Pop(q2);
		return x;
	}else if(!StackEmpty(q1)) {
		while(!StackEmpty(q1)) {
			Push(q2, Pop(q1));
		}
		return Pop(q2);
	}else {
		return 0;
	}
}

int QueueEmpty() {
	if(StackEmpty(q1) && StackEmpty(q2)) {
		return 1;
	}else {
		return 0;
	}
}

int main() {
	InitStack(q1);
	InitStack(q2);
	if(QueueEmpty()) {
		printf("es");
	}
	// if(EnQueue(126)) {
	// 	printf("DeQueue: %d\n", DeQueue());
	// }
}