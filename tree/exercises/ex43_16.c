#include "tree.h"

//把叶子节点接起来
Tree head, pre = NULL;
//先序 中序 后序都可以 NLR LNR LRN
Tree LinkLeaves(Tree T) {
	if(T) {
		if(T->lchild == NULL && T->rchild == NULL) {
			if(pre == NULL) {
				head = T;
				pre = T;
			}else {
				pre->rchild = T;
				pre = T;
			}
		}
		LinkLeaves(T->lchild);
		LinkLeaves(T->rchild);
		pre->rchild = NULL;
	}
	return head;
}

int main() {
	Tree T;
	T = CreateBiTree(T);
	Tree p = LinkLeaves(T);
	while(p) {
		printf("%c ", p->data);
		p=p->rchild;
	}
}