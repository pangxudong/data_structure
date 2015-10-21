#include "tree.h"

//满二叉树 先序转 后序
void Pre2Post(ElemType pre[], int l1, int h1, ElemType post[], int l2, int h2) {
	int half;
	if(h1>=l1) {
		post[h2] = pre[l1];
		half = (h1-l1)/2;
		Pre2Post(pre, l1+1, l1+half, post, l2, l2+half-1);//左子树
		Pre2Post(pre, l1+half+1, h1, post, l2+half, h2-1);
	}
}

int main() {
	ElemType *pre = "ABCDEFG";
	ElemType post[MAXSIZE];
	Pre2Post(pre, 0, 6, post, 0, 6);
	int i;
	for(i=0; i<7; i++) {
		printf("%c ", post[i]);
	}
}