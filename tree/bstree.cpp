/**
 *二叉排序树，本文件使用了cpp的&特性，除此和c语言不差别
 */

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct BSTNode{
	ElemType data;
	BSTNode *lchild, *rchild;
} *BiTree;

BSTNode *BST_Search(BiTree T, ElemType key, BSTNode *&p) {
	p = NULL;// p指向被查节点的双亲，用于插入和删除操作
	while(T && key != T->data) {
		p = T;
		if(key < T->data) {
			T = T->lchild;
		}else {
			T = T->rchild;
		}
	}
	return T;
}

int BST_Insert(BiTree &T, ElemType k) {
	if(T == NULL) {//原树为空
		T = (BiTree)malloc(sizeof(BSTNode));
		T->data = k;
		T->lchild = NULL;
		T->rchild = NULL;
		return 1;
	}else if(k == T->data) {//树中存在相同关键字节点
		return 0;
	}else if(k < T->data) {
		return BST_Insert(T->lchild, k);
	}else {
		return BST_Insert(T->rchild, k);
	}
}

void Creat_BST(BiTree &T, ElemType str[], int n) {
	T = NULL;
	int i = 0;
	while(i<n) {
		BST_Insert(T, str[i]);
		i++;
	}
}

//二叉查找树的删除，难点
int Delete(BiTree &p) {
	BiTree q, s;
	if (!p->rchild) {//右子树为空，则接它的左子树
		q = p;
		p = p->lchild;
		free(q);
	}else if(!p->lchild) {//接右子树
		q = p;
		p = p->rchild;
		free(q);
	}else {//均不空,用其直接z中序前驱或直接后继代替。
		q = p;
		s = p->lchild;//本程序用前驱代替
		while(s->rchild) {q = s; s = s->rchild;}
		p->data = s->data;//s即为p的前驱
		if(q!=p) {//重接*q的右子树(*q为s双亲节点)
			q->rchild = s->lchild;
		}else {//重接*q的左子树
			q->lchild = s->lchild;
		}
		delete s;
		
		// q = p;
		// s = p->rchild;//用后继节点代替被删节点
		// while(s->lchild) {q = s; s = s->lchild;}
		// p->data = s->data;
		// if(q!=p) {
		// 	q->lchild = s->rchild;
		// }else {
		// 	q->rchild = s->rchild;
		// }
		// delete s;
		
	}
	return 1;
}

int BST_Delete(BiTree &T, ElemType key) {
	if(!T) return 0;
	else {
		if(key == T->data) {
			return Delete(T);
		}else if (key < T->data) {
			return BST_Delete(T->lchild, key);
		}else {
			return BST_Delete(T->rchild, key);
		}
	}
}


void BeautifulPrint(BiTree T) {
	BiTree queue[100];//
	int front = 0, rear = 0;
	queue[rear++] = T;
	BiTree p = T;

	int num = 1, tnum = 0;//num为每一层节点个数,tnum临时变量

	if(T){
		while(num--) {
			p = queue[front++];
			printf("%d ", p->data);
			if(p->lchild) {
				queue[rear++] = p->lchild;
				tnum++;
			}
			if(p->rchild) {
				queue[rear++] = p->rchild;
				tnum++;
			}
			if(num==0) {//当num为0时，要换行，tnum存着下一行的节点个数
				num = tnum;
				tnum = 0;
				printf("\n");
			}
		}
	}else {
		printf("NULL Tree\n");
	}
}


int main() {
	BiTree T;
	ElemType str[8] = {7,6,5,4,3,2,1};
	Creat_BST(T, str, 7);
	BST_Insert(T, 126);
	BeautifulPrint(T);
	printf(" delete...\n");
	BST_Delete(T, 126);
	BeautifulPrint(T);
	// BiTree p;
	// T = BST_Search(T, 1, p);
	// printf("%d\n", T->data); 
}