#include "tree.h"

//非递归 后序遍历二叉树
void PostOrder3(Tree T) {
	Tree p = T;
	Tree lastVisit = NULL;
	Tree temp = T;
	Tree stack[100];
	int top = -1;

	while(p || top != -1) {
		while(p) {
			stack[++top] = p;
			p = p->lchild;
		}
		temp = stack[top];

		if(temp->rchild == NULL || temp->rchild == lastVisit) {
			printf("%c ", temp->data);
			lastVisit = stack[top--];
		}else {
			p = temp->rchild;
		}
	}
}


int main() {
	Tree T = NULL;
	printf("create BiTree NULL(#)\n");
	T = CreateBiTree(T);
	PostOrder3(T);
}