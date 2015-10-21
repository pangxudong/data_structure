/**
 *哈夫曼树和哈夫曼编码的存储表示
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define ERROR -1
typedef int Status;


typedef struct {
	unsigned int weight;
	unsigned int parent, lchild, rchild;
}HTNode, *HuffmanTree;//动态分配哈夫曼树

typedef char ** HuffmanCode;//动态分配数组存储哈夫曼编码表

void PrintHuffmanTree(HuffmanTree HT, int n);
void PrintHuffmanCode(HuffmanCode HC, HuffmanTree HT, int n);
void Select(HuffmanTree HT, int n, int &s1, int &s2);
void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int n);
void max(HuffmanTree HT, int &s1, int &s2, int n);


void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int n) {
	int m, i, s1, s2, start, current, further;
	HuffmanTree p;
	char *cd;
	s1 = 0, s2 = 0;
	if(n<= 1) return ;
	m = 2 * n -1;
	HT = (HuffmanTree)malloc((m+1)*sizeof(HTNode));	//0单元未用
	for(p=HT+1, i=1; i<=n; ++i, ++p, ++w) {	//初始化前n个结点，并将n个权值依次赋给它们
		(*p).weight = *w;
		(*p).parent = 0;
		(*p).lchild = 0;
		(*p).rchild = 0;
	}
	for(; i<=m; ++i, ++p) {		//初始化剩余的结点
		(*p).weight = 0;
		(*p).parent = 0;
		(*p).lchild = 0;
		(*p).rchild = 0;
	}
	for(i=n+1; i<=m; ++i) {		//建哈夫曼树
		s1 = 0;
		s2 = 0;
		Select(HT, i-1, s1, s2);	//找到权最小的两个根结点, 且s1的权小于s2
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}

	/* 从叶子到根逆向求每个字符的赫夫曼编码 */
	HC = (HuffmanCode)malloc((n+1)*sizeof(char *));	//分配n个字符编码的头指针向量，0单元未用
	cd = (char *)malloc(sizeof(char));
	cd[n-1] = '\0';
	for(i=0; i<=n; i++) {
		start = n-1;
		for(current = i, further = HT[i].parent; further!=0; current=further, further = HT[further].parent)  {
			if(current == HT[further].lchild) {
				cd[--start] = '0';
			}else {
				cd[--start] = '1';
			}
		}
		HC[i] = (char *)malloc((n-start)*sizeof(char)); //为第i个字符编码分配空间
		strcpy(HC[i], &cd[start]);
	}
	free(cd);
	cd = NULL;
}


/**
 * 在数组HT[1...n]中选择parent为0且weight最小的两个结点，其序号分别为s1,s2, 并且s1的权小于s2的权
 */
void Select(HuffmanTree HT, int n, int &s1, int &s2)
{
	int i;
	for (i=1; i<=n; i++) {		//遂个查找权值最小的两个结点
		if (0 == HT[i].parent) {	//在parent为0的结点中寻找
			 if (0 == s1)
				s1 = i;
			 else if (0 == s2)
				s2 = i;
			 else
				 max(HT, s1, s2, i);

		}
	}
	if (s1 > s2) {
		i = s1;
		s1 = s2;
		s2 = i;
	}
}

/**
 * s1, s2返回HT的s1, s2, n序中权值最小的两个
 */
void max(HuffmanTree HT, int &s1, int &s2, int n)
{
	if (HT[s1].weight <= HT[s2].weight) {
		if (HT[n].weight < HT[s2].weight)
			s2 = n;
	} else {
		if (HT[n].weight < HT[s1].weight)
			s1 = n;
	}
}

void PrintHuffmanTree(HuffmanTree HT, int n) {
	int i;
	printf("HuffmanTree:\nNO.\tweight\tparent\tlchild\trchild\n");
	for(i=1; i<=n; i++) {
		printf("%d\t%d\t%d\t%d\t%d\t\n", i, HT[i].weight, HT[i].parent, HT[i].lchild, HT[i].rchild);
	}
}

void PrintHuffmanCode(HuffmanCode HC, HuffmanTree HT, int n) {
	int i;
	printf("HuffmanCode(不唯一):\nWeight\tCode\n");
	for(i=1; i<=n; i++) {
		printf("%d\t%s\n", HT[i].weight, HC[i]);
	}
}


int main() {
	HuffmanTree HT;
	HuffmanCode HC;
	// int n = 4;
	// int w[] = {7, 5, 4, 2};
	int n = 5;
	int w[] = {3, 5, 6, 9, 12};

	HuffmanCoding(HT, HC, w, n);
	PrintHuffmanTree(HT, 2*n-1);
	PrintHuffmanCode(HC, HT, n);
}