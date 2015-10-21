/**
 * 加上线索的二叉树称之为 线索二叉树
 */
#ifndef _TREADTREE_H_
#define _TREADTREE_H_

#include <stdio.h>
#include <stdlib.h>

#define Link 0
#define Thread 1
#define ERROR -1
#define OK 1

typedef char TElemType;
typedef struct BiThrNode{
	TElemType data;
	struct BiThrNode *lchild, *rchild;
	int LTag, RTag;
} *BiThrTree;

int CreateBiThrTree(BiThrTree &T);
int InOrderTraverse_Thr(BiThrTree Thrt);
int InOrderThreading(BiThrTree &Thrt, BiThrTree T);
void InThreading(BiThrTree p);
int visit(BiThrTree e);
/**
 * 按先序顺序构造二叉树
 */
int CreateBiThrTree(BiThrTree &T) {
	char ch;
	scanf("%c", &ch);
	if ('#' == ch) {
		T = NULL;
	}else {
		T = (BiThrTree)malloc(sizeof(BiThrNode));
		if(!T) {
			return ERROR; 
		}
		T->data = ch;
		T->LTag = Link;
		T->RTag = Link;
		CreateBiThrTree(T->lchild);
		CreateBiThrTree(T->rchild);
	}
	return OK;
}

/**
 * 算法6.5，Thrt指向头结点，头结点的左链lchild指向根结点，
 * 右链指向遍历的最后一个结点,这样既从第一个节点顺后继遍历，也可以从最后一个节点顺前驱遍历。
 * 中序遍历二叉线索树的非递归算法，对每个数据元素调用函数visit
 */
 int InOrderTraverse_Thr(BiThrTree Thrt) {
 	BiThrTree p;
 	p = Thrt->lchild;		//p指向根节点
 	while(p != Thrt) {		//空树或遍历结束p==T
 		while(Link == p->LTag) {
 			p = p->lchild;	//走到左子树尽头,找到中序的第一个节点。剩下的就按线索访问。
 		}
 		if (ERROR == visit(p)) {	//访问其左子树为空的节点
 			return ERROR;
 		}
 		while(Thread == p->RTag && p->rchild != Thrt) {
 			p = p->rchild;	//访问后继节点
 			if (ERROR == visit(p)) {
 				return ERROR;
 			}
 		}
 		p = p->rchild;
 	}
 	return OK;
 }
 BiThrTree pre;
 /**
 * 算法6.6，中序遍历二叉树T，并将其中序线索化，Thrt指向头结点
 */
 int InOrderThreading(BiThrTree &Thrt, BiThrTree T) {
 	if(!(Thrt = (BiThrTree)malloc(sizeof(BiThrNode)))) {
 		return ERROR;
 	}
 	Thrt->LTag = Link;		//创建头结点
 	Thrt->RTag = Thread;
 	Thrt->rchild = Thrt;	//右指针回指
 	if(!T) {
 		Thrt->lchild = Thrt;
 	}else {
 		Thrt->lchild = T;
 		pre = Thrt;
 		InThreading(T);		//中序遍历进行线索化
 		pre->rchild = Thrt;		//最后一个结点线索化，最后一个结点的右链指向头结点
 		pre->RTag = Thread;
 		Thrt->rchild = pre;		//头结点的右链指向最后一个遍历的结点
 	}
 	return OK;
 }

 void InThreading(BiThrTree p) {
 	if (p) {
 		InThreading(p->lchild);	//左子树线索化
 		if (!p->lchild) {		//左链为空时，前继线索
 			p->LTag = Thread;
 			p->lchild = pre;	//pre为中序遍历访问的前一个结点
 		}
 		if (!pre->rchild) {		//前一个结点的右链为空时，后继线索*
 			pre->RTag = Thread;
 			pre->rchild = p;
 		}
 		pre = p;
 		InThreading(p->rchild);	//右子树线索化
 	}
 }

 int visit(BiThrTree e) {
 	if( e==NULL) {	
 		printf("visit return error\n");
 		return ERROR;
 	}
 	printf("%c ", e->data);
 	return OK;
 }

 #endif


 // int main() {	//main.cpp
 // 	BiThrTree Thrt, T;
 // 	CreateBiThrTree(T);
 // 	printf("CreateBiThrTree(T) yes\n");
 // 	InOrderThreading(Thrt, T);
 // 	printf("InOrderThreading(Thrt, T) yes\n");
 // 	printf("InOrderTraverse_Thr(Thrt): ");
 // 	InOrderTraverse_Thr(Thrt);
 // }