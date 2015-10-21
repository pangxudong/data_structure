#include "tree.h"

int Similar(Tree T1, Tree T2) {
	int l, r;
	if(!T1 && !T2) {
		return 1;
	}else if(!T1 || !T2){
		return 0;
	}else {
		int l = Similar(T1->lchild, T2->lchild);
		int r = Similar(T1->rchild, T2->rchild);
		return  l&&r ;
	}
}

int main() {
	Tree T1, T2;
	T1 = CreateBiTree(T1);
	// T2 = CreateBiTree(T2);
	T2 = T1->lchild;
	if(Similar(T1, T2)) {
		printf("is similar!\n");
	}else {
		printf("not similar!\n");
	}
}