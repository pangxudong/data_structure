#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50 

typedef int ElemType;

typedef struct {
	ElemType data[MaxSize];
	int top;
}SeqStack, *Stack;

Stack InitStack(Stack s) {
	s=(Stack)malloc(sizeof(SeqStack));//不加此行会segment fault
	s->top = -1;
	return s;
}

int StackEmpty(Stack s) {
	if(s->top == -1) {
		return 1;
	}else {
		return 0;
	}
}

int Push(Stack s, ElemType x) {
	if(s->top == MaxSize - 1) {
		printf("ERROR:\tstack full!\n");
		return 0;
	}
	s->data[++s->top] = x;//指针先加1，再入栈
	return 1;
}

ElemType Pop(Stack s) {
	if(s->top == -1) {
		printf("ERROR:\tstack empty!\n");
		return 0;
	}
	return s->data[s->top--];
}

ElemType GetTop(Stack s) {
	if(s->top == -1) {
		printf("ERROR:\tstack empty!\n");
		return 0;
	}
	return s->data[s->top];
}


// #include "stack.h"

// int main() {
// 	Stack s;
// 	InitStack(s);
// 	if(Push(s, 126) && Push(s, 621) && Pop(s)){
// 		printf("s.top:\t%d", GetTop(s));
// 	}
// }