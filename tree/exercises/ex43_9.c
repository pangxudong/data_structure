#include "tree.h"
//交换左右子节点
void Reverse(Tree T) {
	Tree temp = NULL;
	if(T) {
		temp = T->lchild;
		T->lchild = T->rchild;
		T->rchild = temp;
		Reverse(T->lchild);
		Reverse(T->rchild);
	}
}

int main() {
	Tree T;
	T = CreateBiTree(T);
	Reverse(T);
	BeautifulPrint(T);
}