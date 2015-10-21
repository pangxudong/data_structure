//Merge-find-set并查集

#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
#define OK 1
typedef char TElemType;

/* 树的双亲表示法，P135*/
#define MAX_TREE_SIZE 100
typedef struct PTNode {	//结点结构
	TElemType data;
	int parent;	//双亲位置
}PTNode;
typedef struct {	//树结构
	PTNode nodes[MAX_TREE_SIZE];	
	int r, n;	//根的位置和结点数
}PTree;

typedef PTree MFSet;

int find_mfset(MFSet S, int i);
int merge_mfset(MFSet S, int i, int j);
int mix_mfset(MFSet S, int i, int j);
int fix_mfset(MFSet &S, int i);

/**
 * 算法6.8，找集合S中i所在子集的根
 */
int find_mfset(MFSet S, int i)
{
	int j;
	if (i<1 || i>S.n)
		return ERROR;
	for (j=i; S.nodes[j].parent>0; j=S.nodes[j].parent)
		;
	return j;
}

/**
 * 算法6.9，S.nodes[i]和S.nodes[j]分别为S的互不相交的两个子集Si和Sj的根结点，
 * 求并集SiUSj
 */
int merge_mfset(MFSet &S, int i, int j) {
	if(i<1 || i>S.n || j<1 || j>S.n) {
		return ERROR;
	}
	S.nodes[i].parent = j;
	return OK;
}
/** 
 * 算法6.10，改进的求并集的算法，根结点的parent域中存储子集中所含元素的负值
 */
int mix_mfset(MFSet S, int i, int j) {
	if(i<1 || i>S.n || j<1 || j>S.n) {
		return ERROR;
	}
	if(S.nodes[i].parent > S.nodes[j].parent) {	// Si所含成员数比Sj中少
		S.nodes[j].parent += S.nodes[i].parent;
		S.nodes[i].parent = j;
	} else {
		S.nodes[i].parent += S.nodes[j].parent;
		S.nodes[j].parent = i;
	}
	return OK;
}

/**
 * 算法6.11，算法6.8的改进，增加压缩路径，
 * 确定i所在子集，并将从i至根路径上所有结点都变成根的孩子结点
 */
int fix_mfset(MFSet &S, int i) {
	int j, k, t;

	if(i<1 || i>S.n) {
		return ERROR;
	}
	for(j=i; S.nodes[j].parent>0; j=S.nodes[j].parent)	//循环结束后 j 就是根结点
		;
	for (k=i; k!=j; k=t) {
		t = S.nodes[k].parent;
		S.nodes[k].parent = j;
	}
	return j;	//返回i所在子集的根结点
}

int main() {
	MFSet S;
}