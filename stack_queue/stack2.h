#include <stdio.h>
#include <stdlib.h>

#define Maxsize 50

typedef int ElemType;

typedef struct {
	ElemType data[Maxsize];
	int top;
} Stack;//此处声明为非引用而非指针

void InitStack(Stack *s) {
	s->top = -1;
}

int isEmpty(Stack *s) {
	return s->top==-1?1:0;
}

int Push(Stack *s, int x) {
	if(s->top == Maxsize -1) {
		return 0;
	}else {
		s->data[++s->top] = x;
	}
	return 1;
}

ElemType Pop(Stack *s) {
	if(s->top==-1) {
		return 0;
	}else {
		return s->data[s->top--];
	}
}

ElemType GetTop(Stack *s) {
	if(s->top == -1) {
		return 0;
	}else {
		return s->data[s->top];
	}
}

// #include "stack2.h"

// int main() {
// 	Stack s;
// 	InitStack(&s);
// 	if(Push(&s, 126)) {
// 		printf("%d\n",Pop(&s));
// 	}
// }