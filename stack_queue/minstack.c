/*
设计一个栈，使它可以在O(1)时间内实现push, pop, min操作，
min是得到栈中最小的那个值。
*/
#include <stdio.h>
#define Maxsize 100

int stack[Maxsize], minstack[Maxsize];
int top, mintop;

void Init() {
	top = -1;
	mintop = -1;
}

void Push(int x) {
	if(mintop == -1) {
		minstack[++mintop] = x;
	}
	stack[++top] = x;
	if(x<minstack[mintop]) {
		minstack[++mintop] = x;
	}
}

int Pop() {
	int x;
	if(stack[top] == minstack[mintop]) {
		mintop--;
	}
	return stack[top--];
}

int Min() {
	return minstack[mintop];
}

int main() {
	Init();
	Push(126);
	printf("%d\n", Min());
	Push(12);
	Push(1);
	Push(8);
	printf("%d\n", Min());
}