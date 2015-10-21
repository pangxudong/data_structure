#ifndef _CSTREE_H_
#define _CSTREE_H_

typedef VertexType CSElemType;
typedef struct CSNode {
	CSElemType data;
	struct CSNode *lchild, *nextsibling;
}CSNode, *CSTree;

void PreOrderCSTree(CSTree T);
void PrintBiTree(CSTree bt,int n);
void BeautifulPrint(CSTree T);

void PreOrderCSTree(CSTree T) {
	CSTree p;
	p = T;
	if(p) {
		printf("%c ", p->data);
		PreOrderCSTree(p->lchild);
		PreOrderCSTree(p->nextsibling);
	}
}

//直观打印
void PrintBiTree(CSTree bt,int n)
{
	int i;
	if(bt==NULL) return; //递归出口

	PrintBiTree(bt->nextsibling,n+1); //遍历打印右子树

	//访问根节点
	for(i=0;i<n;i++) printf(" ");
	if(n>=0)
	{
		printf("---");
		printf("%c\n",bt->data);
	}

	PrintBiTree(bt->lchild,n+1); //便利打印左子树
}

void CSTreePrint(CSTree T) {
	PrintBiTree(T, 0);
}

#endif