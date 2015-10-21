#include "../tree.h"
#include <string.h>

//根据二叉树的先序遍历和中序遍历重新创建这棵树
//l1,h1为先序的第一和最后一个节点下标,l2,h2为中序的第一和最后一个节点下标
Tree PreInCreat(ElemType *A, ElemType *B, int l1, int h1, int l2, int h2) {
	int i, llen, rlen;
	Tree root;

	root = (Tree)malloc(sizeof(BitNode));
	root->data = A[l1];//NLR,LNR，递归，每次识别出一个子树的根节点
	for(i=l2; B[i]!=root->data; i++);
	llen = i - l2;
	rlen = h2 - i;
	if(llen) {
		root->lchild = PreInCreat(A, B, l1+1, l1+llen, l2, l2+llen-1);
	}else {
		root->lchild = NULL;
	}
	if(rlen) {
		root->rchild = PreInCreat(A, B, h1-rlen+1, h1, h2-rlen+1, h2);
	}else {
		root->rchild = NULL;
	}
	return root;
}

Tree Renew(ElemType *A, ElemType *B) {
	return PreInCreat(A, B, 0, strlen(A)-1, 0, strlen(B)-1);
}

int main() {
	Tree T = NULL;
	ElemType A[100] = "abcdefghi";//先序遍历, 序列千万不能写错，否则什么也运行不出来
	ElemType B[100] = "bcaedghfi";//中序遍历
	// printf("strlen(A)%d A[0]%c A[len-1]%c\n", strlen(A), A[0], A[strlen(A)-1]);
	T = Renew(A, B);
	BeautifulPrint(T);
}