#include "tree.h"

//检查是否为完全二叉树
int IsComplete(Tree T) {
	Tree queue[100];
	int front = 0, rear = 0;
	Tree p = T;
	queue[rear++] = T;

	int flag = 0;

	while(front != rear) {
		p = queue[front++];
		if(p->lchild) {
			if(flag) return 0;//
			queue[rear++] = p->lchild;
		}else {
			flag = 1;//检查到节点为空，其后若还有非空节点，则不是完全树
		}
		if(p->rchild) {
			if(flag) return 0;
			queue[rear++] = p->rchild;
		}else {
			flag = 1;
		}
	}
	return 1;
}

//王道答案
int IsComplete2(Tree T) {
	Tree queue[100];
	int front = 0, rear = 0;
	Tree p;

	if(!T) {
		return 1;//空树为满二叉树
	}
	queue[rear++] = T;
	while(front != rear) {
		p = queue[front++];
		if(p) {
			queue[rear++] = p->lchild;
			queue[rear++] = p->rchild;
		}else {
			while(front!=rear) {
				p = queue[front++];
				if(p) {
					return 0;
				}
			}
		}
	}
	return 1;
}

int main() {
	Tree T;
	T = CreateBiTree(T);
	if(IsComplete(T)) {
		printf("complete\n");
	}else {
		printf("not complete\n");
	}
}