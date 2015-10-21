/**
 *平衡二叉树
 */


#include <stdio.h>
#include <stdlib.h>

#define LH +1 //左高
#define EH 0  //等高
#define RH -1 //右高

typedef int ElemType;

typedef struct BSTNode{
	ElemType data;
	int bf;
	BSTNode *lchild, *rchild;
} *BSTree;

void R_Rotate(BSTree &p) {//LL型,在根节点的左孩子的左子树插入新节点
	BSTree lc;
	lc = p->lchild;//lc指向*p的左子树根节点
	p->lchild = lc->rchild;
	lc->rchild = p;
	p = lc;//p指向新的根节点
}

void L_Rotate(BSTree &p) {//RR型
	BSTree rc;
	rc = p->rchild;
	p->rchild = rc->lchild;
	rc->lchild = p;
	p = rc;
}

void LeftBalance(BSTree &T) {//LR型,结合课本看
	BSTree lc, rd;
	lc = T->lchild;
	switch(lc->bf) {
		case LH://新插入节点在*T左孩子的左子树上，需要单右旋
			T->bf = EH;
			lc->bf = EH;
			R_Rotate(T);
			break;
		case RH://新节点插入在*T左孩子的右子树上，要做双旋处理
			rd = lc->rchild;
			switch(rd->bf) {
				case LH: 
					T->bf = RH;
					lc->bf = EH;
					break;
				case EH:
					T->bf = EH;
					lc->bf = EH;
					break;
				case RH:
					T->bf = EH;
					lc->bf = LH;
					break;
			}
			rd->bf = EH;
			L_Rotate(T->lchild);
			R_Rotate(T);
	}
}


void RightBalance(BSTree &T) {//RL型
	BSTree rc, ld;
	rc = T->rchild;
	switch (rc->bf) {
	case RH:
		T->bf = EH;
		rc->bf = EH;
		L_Rotate(T);
		break;
	case LH:
		ld = rc->lchild;
		switch (ld->bf) {
		case LH:
			T->bf = EH;
			rc->bf = RH;
			break;
		case EH:
			T->bf =EH;
			rc->bf = EH;
			break;
		case RH:
			T->bf = LH;
			rc->bf = EH;
			break;
		}
		ld->bf = EH;
		R_Rotate(T->rchild);
		L_Rotate(T);
	}
}





int InsertAVL(BSTree &T, ElemType e, bool &taller) {
	if(!T) {//插入新节点，树长高，taller为true
		T = (BSTree)malloc(sizeof(BSTNode));
		T->data = e;
		T->lchild = NULL;
		T->rchild = NULL;
		T->bf = EH;
		taller = true;
	}else {
		if(e == T->data) {//存在相同关键字，不插入
			taller = false;
			return 0;
		}
		if(e < T->data) {//继续在左子树中搜索
			if(!InsertAVL(T->lchild, e, taller)) return 0;//未插入
			if(taller) {//已插入*T的左子树中，且左子树长高
				switch (T->bf) {//检查*T的平衡因子
					case LH://左子树比右子树高
						LeftBalance(T);//左平衡
						taller = false;
						break;
					case EH://原本等高，现左子树+1
						T->bf = LH;
						taller = true;
						break;
					case RH://原本右子树高，现等高
						T->bf = EH;
						taller = false;
						break;
				}
			}//if
		}
		else {//应在*T右子树搜索
			if(!InsertAVL(T->rchild, e, taller)) return 0;
			if(taller) {
				switch(T->bf) {
					case LH:
						T->bf = EH;
						taller = false;
						break;
					case EH:
						T->bf = RH;
						taller = true;
						break;
					case RH:
						RightBalance(T);
						taller = false;
						break;
				}
			}
		}//else
	}
	return 1;
}

void Print(BSTree T) {
	if(T) {
		printf("%d ", T->data);
		Print(T->lchild);
		Print(T->rchild);
	}
}

int main() {
	BSTree T = NULL;
	bool taller = true;
	InsertAVL(T, 12, taller);
	InsertAVL(T, 1, taller);
	InsertAVL(T, 126, taller);
	Print(T);
}