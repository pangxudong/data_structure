#include "tree.h"

//返回二叉树中有双分支的节点个数,递归方法
int Count2SonNodes(Tree T) {
	if(T==NULL) {
		return 0;
	}else if(T->lchild!=NULL && T->rchild != NULL) {
		return Count2SonNodes(T->lchild) + Count2SonNodes(T->rchild) + 1;
	}else {
		return Count2SonNodes(T->lchild) + Count2SonNodes(T->rchild);
	}
}

int main() {
	Tree T;
	T = CreateBiTree(T);
	printf("count %d\n", Count2SonNodes(T));
}