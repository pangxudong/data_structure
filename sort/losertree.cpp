/**
 * 败者树： 外部排序中，用于内部归并的数据结构,参看严版教材 P298页
 */

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define k 5
#define MINKEY 0
#define MAXKEY 100

typedef int LoserTree[k];
typedef int KeyType;

// typedef struct {		//败者树是完全二叉树，且不含叶子，可用顺序存储结构
// 	KeyType key; 
// }ExNode, External[k+1];		//外节点，只存放待归并记录的关键字!!!

KeyType b[k+1];		//外节点，只存放待归并记录的关键字!!!

void K_Merge(LoserTree &ls);
void Adjust(LoserTree &ls, int s);
void CreateLoserTree(LoserTree &ls);
void input(int i);
void output(int q);


void K_Merge(LoserTree &ls) {
	//利用败者树ls将编号从0到k-1个输入归并段中的记录归并到输出归并段
	//b[0]至b[k-1]为败者树上的k个叶子节点，分别存放k个输入归并段中的当前记录的关键字
	int i, q;

	memset(b, 0, sizeof(b));
	printf("从k个输入归并段读入该段当前的第一个记录的关键字到外节点:\n");
	for(i=0; i<k; i++) {	//分别从k个输入归并段读入该段当前的第一个记录的关键字到外节点
		input(i);	//input(b[i]);
	}
	CreateLoserTree(ls);	//建败者树ls，选得最小关键字为b[ls[0]]
	while(b[ls[0]] != MAXKEY) {
		q = ls[0];			//q指示当前最小关键字所在归并段
		output(q);			//将编号为q的归并段中当前的记录写至输出归并段

		input(q);		//从编号为q的输入归并段中读入下一个记录的关键字
		Adjust(ls, q);
	}
	output(ls[0]);
}

void CreateLoserTree(LoserTree &ls) {
//已知b[0]到b[k-1]为完全二叉树ls的叶子节点存有k个关键字，沿从叶子到
//根的k条路径将ls调整成为败者树
	int i;

	b[k] = MINKEY;		//MINKEY为关键字可能的最小值
	for(i=0; i<k; ++i) {
		ls[i] = k;			//设置ls中“败者”的初值
	}
	for(i=k-1; i>=0; --i) {
		Adjust(ls, i);
	}
}

void Adjust(LoserTree &ls, int s) {
	int t;

	t = (s+k)/2;			//ls[t]是b[s]的双亲节点
	while(t>0) {
		if(b[s] > b[ls[t]]) {
			int tt = ls[t];	//s指示新的胜者
			ls[t] = s;
			s = tt;
		}
		t = t/2;
	}
	ls[0] = s;
}

//分别从k个输入归并段读入该段当前的第一个记录的关键字到外节点
void input(int i) {
	printf("输入归并段%d当前记录的关键字(Enter键结束): ", i);
	scanf("%d", &b[i]);
	getchar();
}

//将编号为q的归并段中当前的记录写至输出归并段,本程序简化为用关键字代替整个记录
void output(int q) {
	printf("输出一个归并段，其关键字为: %d\n", b[q]);
}


int main() {
	LoserTree ls;
	K_Merge(ls);
}