#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct {
	ElemType data;
	struct LinkNode *next;
}LinkNode;
typedef struct {
	LinkNode *front, *rear;
} *LQueue;

LQueue InitQueue(LQueue Q) {
	Q->front = (LinkNode *)malloc(sizeof(LinkNode));
	Q->rear = Q->front;
	Q->front->next = NULL;
	return Q;
}

int IsEmpty(LQueue Q) {
	if(Q->front == Q->rear) {
		return 1;
	}else {
		return 0;
	}
}

void EnQueue(LQueue Q, ElemType x) {
	LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	Q->rear->next = s;
	Q->rear = s;
}

ElemType DeQueue(LQueue Q) {
	if(Q->front == Q->rear) {
		return 0;
	}
	LinkNode *p;
	p = Q->front->next;
	ElemType x = p->data;
	Q->front->next = p->next;
	Q->front = p;
	if(Q->rear == p) {
		Q->rear = Q->front;
	}
	return x;
}