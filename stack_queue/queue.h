#include <stdio.h>
#include <stdlib.h>

#define Maxsize 50

typedef int ElemType;

typedef struct {
	ElemType data[Maxsize];
	int front, rear;
}CQueue, *Queue;

//循环队列 
void InitQueue(Queue q) {
	q->rear = q->front = 0;
}

int isEmpty(Queue q) {
	if(q->rear==q->front) {
		return 1;
	}else {
		return 0;
	}
}

int EnQueue(Queue q, int x) {
	if ((q->rear+1)%Maxsize == q->front) {
		return 0;
	}
	q->data[q->rear] = x;
	q->rear = (q->rear + 1) % Maxsize;
	return 1;
}

int DeQueue(Queue q) {
	if (q->rear == q->front) {
		return 0;
	}
	int x = q->data[q->front];
	q->front = (q->front+1) % Maxsize;
	return x;
}

// #include "queue.h"

// int main() {
// 	Queue q;
// 	InitQueue(q);
// 	if(EnQueue(q, 126)){
// 		printf("q.front:\t%d", DeQueue(q));
// 	}
// }