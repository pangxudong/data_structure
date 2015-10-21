#include "tree.h"
#define Maxsize 100

//自下而上，自右向左 遍历二叉树
void ReverseOrder(Tree T) {
	ElemType stack[Maxsize];
	int top = -1;
	Tree queue[Maxsize];
	int front = 0; 
	int rear = 0;

	Tree p;
	queue[rear++] = T;
	while(front != rear) {
		p = queue[front++];
		stack[++top] = p->data;
		
		if(p->lchild!=NULL) {
			queue[rear++] = p->lchild;
		}if(p->rchild!=NULL) {
			queue[rear++] = p->rchild;
		}
	}
	while(top!=-1) {
		printf("%c ", stack[top--]);
	}
}

int main() {
	Tree T;
	T = CreateBiTree(T);
	printf("yes\n");
	ReverseOrder(T);
}