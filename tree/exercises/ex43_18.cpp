#include "../threadtree.h"

//在中序线索二叉树T中，求指定节点p在后序下的前驱节点q
BiThrTree InPostPre(BiThrTree t, BiThrTree p) {
	BiThrTree q;
	if(p->RTag == 0) {//若p有右子女，右子女为其后序前驱
		q = p->rchild;
	}else if(p->LTag == 0){//若只有左子女，左子女为其后序前驱
		q = p->lchild;
	}else if(p->lchild == NULL) {//中序遍历的第一个节点，中序和后序均无前驱
		q = NULL;
	}else {	//顺左线索向上找p的祖先，若存在，再找祖先的左子女
		while(p->LTag == 1 && p->lchild != NULL) {
			p= p->lchild;//中序前驱
		}
		if(p->LTag == 0) {
			q = p->lchild;
		}else {
			q = NULL;
		}
	}
	return q;
}

int main() {
	BiThrTree Thrt, T, p, q;
	CreateBiThrTree(T);
	InOrderThreading(Thrt, T);
	// InOrderTraverse_Thr(Thrt);
	p = Thrt->lchild;
	q = InPostPre(Thrt, p);
	if(q != NULL) {		
		printf("%c\n", q->data);
	}else {
		printf("该节点为后序的第一个节点，没有前驱\n");
	}//注意这里不可能发生q==NULL,因为本程序在生成ThreadTree时，将其做成双向的，头结点也是尾节点,都有前驱
}