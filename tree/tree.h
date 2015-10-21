#include <stdio.h>
#include <stdlib.h>

#define OVERFLOW -2
#define MAXSIZE 100

typedef char ElemType;
//二叉树的链式表示 binary tree
typedef struct BitNode{//二叉树
	ElemType data;
	struct BitNode *lchild, *rchild;
}BitNode, *Tree;

/*
先序输入 如：ab##c## 代表:
	    a
	   / \
	  b   c
	 / \ / \
    #  # #  #
*/
Tree CreateBiTree(Tree T) {//若不返回指针，则针对实参做改变
	ElemType x;
	scanf("%c", &x);
	if(x=='#') {//char:# int:-1
		T = NULL;
	}else {
		if(!(T=(Tree)malloc(sizeof(BitNode)))) {
			printf("malloc failure!\n");
			exit(OVERFLOW);
		}
		T->data = x;
		T->lchild = CreateBiTree(T->lchild);
		T->rchild = CreateBiTree(T->rchild);
	}
	return T;
}

//二叉树的高度，递归方法
int Depth(Tree T) {
	if(T==NULL) {
		return 0;
	}
	int ldep = Depth(T->lchild);//子树加根节点
	int rdep = Depth(T->rchild);
	if(ldep > rdep) {
		return ldep+1;
	}else {
		return rdep+1;
	}
}

//先序遍历
void PreOrder(Tree T) {
	if(T!=NULL) {
		printf("%c ", T->data);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

void InOrder(Tree T) {
	if(T!=NULL) {
		InOrder(T->lchild);
		printf("%c ", T->data);
		InOrder(T->rchild);
	}
}

void PostOrder(Tree T) {
	if (T!= NULL) {
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		printf("%c ", T->data);
	}
}

//层次遍历
void LevelOrder(Tree T) {
	Tree queue[MAXSIZE];//辅助队列
	int front = 0;
	int rear = 0;//初始化 front=rear=0
	Tree p = T;
	queue[rear++] = T;

	while(front!=rear) {
		p = queue[front++];//出栈
		printf("%c ", p->data);
		if(p->lchild!=NULL) {
			queue[rear++] = p->lchild;
		}
		if(p->rchild!=NULL) {
			queue[rear++] = p->rchild;
		}
	}
}


//二叉树先 序遍历的非递归算法，需要一个辅助栈
void PreOrder2(Tree T) {
	Tree stack[MAXSIZE];
	int top = -1;
	Tree p = T;

	while(p || top!=-1) {
		if(p) {
			stack[++top] = p;
			printf("%c ", p->data);
			p = p->lchild;
		}else {
			p = stack[top--];
			p = p->rchild;
		}
	}
}

//二叉树中序遍历的非递归算法，需要一个辅助栈
void InOrder2(Tree T) {
	Tree stack[MAXSIZE];
	int top = -1;
	Tree p = T;

	while(p || top!=-1) {
		if(p) {
			stack[++top] = p;
			p = p->lchild;
		}else {
			p = stack[top--];
			printf("%c ", p->data);
			p = p->rchild;
		}
	}
}

//二叉树后序遍历的非递归算法，需要一个辅助栈
void PostOrder2(Tree T) {
	Tree stack[MAXSIZE];
	int top = -1;

	Tree p = T;
	Tree lastvisit = NULL;
	Tree temp = T;

	while(p || top != -1) {
		while(p) {
			stack[++top] = p;
			// printf("push %c\n", p->data);
			p = p->lchild;
		}
		temp = stack[top];
		//若栈顶元素的右子树为空或已访问过，就访问该元素，否则就访问它的右子树
		if(temp->rchild == NULL || temp->rchild == lastvisit) {
			printf("%c ", temp->data);
			lastvisit = stack[top--];
			// printf("pop %c\n", lastvisit->data);
		}else {
			p = temp->rchild;
		}
	}
}

//直观打印
void PrintBiTree(Tree bt,int n)
{
	int i;
	if(bt==NULL) return; //递归出口

	PrintBiTree(bt->rchild,n+1); //遍历打印右子树

	//访问根节点
	for(i=0;i<n;i++) printf("\t");
	if(n>=0)
	{
		printf("---");
		printf("%c\n",bt->data);
	}

	PrintBiTree(bt->lchild,n+1); //便利打印左子树
}

void BeautifulPrint(Tree T) {
	PrintBiTree(T, 0);
}


// #include "tree.h"

// int main() {
// 	Tree T = NULL;
// 	printf("Create tree: NULL('#'):\n");
// 	T = CreateBiTree(T);
// 	PreOrder(T);
// 	printf("\n");
// 	InOrder(T);
// 	printf("\n");
// 	PostOrder(T);
// 	printf("\n");
// 	LevelOrder(T);
// 	printf("\n");
// 	PostOrder2(T);
// }