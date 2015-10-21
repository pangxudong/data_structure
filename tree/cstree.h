#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

//左孩子右兄弟,存储的是森林
typedef char ElemType;

typedef struct CSNode {
	ElemType data;
	struct CSNode *fch, *nsib;//firstchild nextsibling
}CSNode, *CSTree;

CSTree CreateCSTree(CSTree T) {//若不返回指针，则针对实参做改变
	ElemType x;
	scanf("%c", &x);
	if(x=='#') {//char:# int:-1
		T = NULL;
	}else {
		if(!(T=(CSTree)malloc(sizeof(CSNode)))) {
			printf("malloc failure!\n");
			exit(-2);
		}
		T->data = x;
		T->fch = CreateCSTree(T->fch);
		T->nsib = CreateCSTree(T->nsib);
	}
	return T;
}

//直观打印,层次遍历。高度
void BeautifulPrint(CSTree T) {
	CSTree queue[MAXSIZE];//
	int front = 0, rear = 0;
	queue[rear++] = T;
	CSTree p = T;

	int num = 1, tnum = 0;//num为每一层节点个数,tnum临时变量

	if(T){
		while(num--) {
			p = queue[front++];
			printf("%c ", p->data);
			if(p->fch) {
				queue[rear++] = p->fch;
				tnum++;
			}
			if(p->nsib) {
				queue[rear++] = p->nsib;
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
