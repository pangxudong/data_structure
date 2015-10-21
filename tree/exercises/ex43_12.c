#include "tree.h"

//寻找元素值为x的节点的路径,(非递归后序遍历)
void AncestorX(Tree T, int x) {
	Tree stack[100];
	int top = -1;

	Tree p = T;
	Tree temp = NULL;
	Tree lastVisit = NULL;

	while(p || top != -1) {
		while(p) {
			stack[++top] = p;
			if(p->data == x) {
				while(top!=-1) {
					printf("%c ", stack[top--]->data);
				}
				return ;
			}
			p = p->lchild;
		}
		temp = stack[top];
		if(temp->rchild == NULL || temp->rchild == lastVisit) {
			lastVisit = stack[top--];
		}else {
			p = temp->rchild;
		}
	}
}

int main() {
	Tree T;
	T = CreateBiTree(T);
	int x = 'c';
	AncestorX(T, x);
}