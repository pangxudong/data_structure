#include "tree.h"

//删除元素值为x的节点，并删除以它为根的子树
void DeleteXNode(Tree T) {
	if(T) {
		DeleteXNode(T->lchild);
		DeleteXNode(T->rchild);
		free(T);
	}
}

void SearchX(Tree T, ElemType x) {
	Tree queue[100];
	int front = 0, rear = 0;
	if(T) {
		if(T->data == x) {
			DeleteXNode(T);
		}
		queue[rear++] = T;
		while(front != rear) {
			Tree p = queue[front++];
			if(p->lchild) {
				if(p->lchild->data == x) {
					DeleteXNode(p->lchild);
					p->lchild = NULL;
				}else {
					queue[rear++] = p->lchild;
				}
			}
			if(p->rchild) {
				if(p->rchild->data == x) {
					DeleteXNode(p->rchild);
					p->rchild = NULL;
				}else {
					queue[rear++] = p->rchild;
				}
			}
		}
	}
}

int main() {
	Tree T;
	T = CreateBiTree(T);
	BeautifulPrint(T);
	SearchX(T, 'c');
	printf("after delete...\n");
	BeautifulPrint(T);
}