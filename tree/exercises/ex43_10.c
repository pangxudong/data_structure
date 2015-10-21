#include "tree.h"

//求先序遍历中第k个节点的值
ElemType queue[100];
int rear = 0;

void PreOrder3(Tree T) {
	if(T) {
		queue[rear++] = T->data;
		PreOrder3(T->lchild);
		PreOrder3(T->rchild);
	}
}

ElemType KthPreOrder(Tree T, int k) {
	PreOrder3(T);
	return queue[k-1];
}

//王道答案
int i=1;//递归序号，全局变量
ElemType PreNode(Tree T, int k) {
	if(!T) {
		return '#';
	}
	if(i==k) {
		return T->data;
	}
	i++;
	ElemType ch = PreNode(T->lchild, k);
	if(ch != '#') {
		return ch;
	}
	ch = PreNode(T->rchild, k);
	if(ch != '#') {
		return ch;
	}
}

int main() {
	Tree T;
	int k = 2;
	T = CreateBiTree(T);
	// printf("the %dth in preorder : %c\n", k, KthPreOrder(T, k));
	printf("the %dth in preorder : %c\n", k, PreNode(T, k));
}