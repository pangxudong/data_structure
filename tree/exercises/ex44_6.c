#include "../cstree.h"

#define maxsize 15

//层次序列e[],节点的度degree[],n树的节点数
CSTree CreateCSTree_Degree(ElemType e[], int degree[], int n) {
	CSNode * pointer[maxsize];//存储新建树的各个节点的地址
	int i, d, j, k = 0;

	for(i=0; i<n; i++) {//初始化
		pointer[i] = (CSNode *)malloc(sizeof(CSNode));
		pointer[i]->data = e[i];
		pointer[i]->fch = NULL;
		pointer[i]->nsib = NULL;
	}
	for(i=0; i<n; i++) {
		int d = degree[i];
		if(d) {
			k++;//k为子女节点序号
			pointer[i]->fch = pointer[k];//建立i与子女k的链接
			for(j=2, k--; j<=d; j++) {	//mark 王道答案错了
				pointer[k+j-1]->nsib = pointer[k+j];
			}
			k+=d;
		}
	}
	return pointer[0];
}

int main() {
	CSTree T;
	ElemType e[] = "abcdefg";
	int degree[] = {2,2,2,0,0,0,0};
	int n = 7;
	T = CreateCSTree_Degree(e, degree, n);
	BeautifulPrint(T);
}