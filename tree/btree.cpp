#include <stdio.h>
#include <stdlib.h>

#define m 3

typedef int KeyType;

typedef struct BTNode {
	int keynum;
	BTNode * parent;
	KeyType key[m+1];//0号单元未用
	BTNode *ptr[m+1];//子树指针
	// Record *recptr[m+1];
}BTNode, *BTree;

typedef struct {
	BTNode *pt;//指向找到的节点
	int i;//1..m在关键字中的序号
	int tag;//1：成功 0：失败
}Result;

/**
 * 算法9.13，在m阶B-树T上查找关键字K，返回结果（pt, i, tag），若查找成功，
 * 则特征值tag = 1，指针pt所指结点中第i个关键字等于K，否则特征值tag = 0，
 * 等于K的关键字应插入在指针pt所指结点中第i和第i+1个关键字之间。
 */

//找到i，使p->key[i] <= K < p->key[i+1], i: 0..keynum
int Search(BTree p, KeyType k) {
	int i, j;
	if (k < p->key[1]) {
		i = 0;
	}else if (k >= p->key[p->keynum]) {
		i = p->keynum;
	}else {
		for (j = 1; j<= (p->keynum)-1; j++) {
			if (k >= p->key[j] && k < p->key[j+1]) {
				i = j;
				break;
			}
		}
	}
	return i;
}

Result SearchBTree(BTree T, KeyType k) {
	int i = 0;
	Result r;
	BTree p = T, q = NULL;
	bool found = false;

	while(p && !found) {//T=NULL也考虑到了
		i = Search(p, k);
		if(i>0 && k == p->key[i]) {
			found = true;
		}else {
			q = p;
			p = p->ptr[i];
		}
	}
	if (found) {
		r.pt = p;
		r.i = i;
		r.tag = 1;
	}else {
		r.pt = q;
		r.i = i;
		r.tag = 0;
	}
	return r;
}

/**
 * 算法9.14，首先查找m阶B树上是否有关键字K，有则不插入，返回0，否则在m阶B-树插入关键字K
 * 并返回1，若引起结点过大，则沿双亲链进行必要的结点分裂调整，使T仍是m阶B-树。
 */

//将x和ap分别插入到p->key[i+1]和p->ptr[i+1]中
int Insert(BTree p, int i, KeyType x, BTree ap) {
	int j;
	for(j=p->keynum; j>=i+1; j--) {
		p->key[j+1] = p->key[j];
		p->ptr[j+1] = p->ptr[j];
	}
	p->key[i+1] = x;
	p->ptr[i+1] = ap;
	p->keynum++;
	if (ap!= NULL) {
		ap->parent = p;
	}
	return 1;
}

int split(BTree p, int s, BTree &ap) {
	int i, j;
	p->keynum = s - 1;

	ap = (BTree)malloc(sizeof(BTNode));
	for(i = s+1, j=1; i<=m; i++, j++) {
		ap->key[j] = p->key[i];
	}
	for(i=s, j=0; i<=m; i++, j++) {
		ap->ptr[j] = p->ptr[i];
		if(ap->ptr[j] != NULL) {
			ap->ptr[j]->parent = ap;
		}
	}
	ap->keynum = m - s;
	ap->parent = p->parent;

	return 1;
}

int NewRoot(BTree &T, BTree q, KeyType x, BTree ap) {
	BTree root;
	root = (BTree)malloc(sizeof(BTNode));
	root->key[1] = x;
	root->ptr[0] = T;//??传入q有什么用？
	root->ptr[1] = ap;
	root->keynum = 1;
	root->parent = NULL;

	if (T) {
		T->parent = root;
	}
	if (ap != NULL) {
		ap->parent = root;
	}
	T = root;
	return 1;
}


void InsertBTree(BTree &T, KeyType k) {
	KeyType x = k;
	BTree ap = NULL, q;//ap分裂出来的节点
	bool finished = false;
	int i, s;

	Result res = SearchBTree(T, k);
	q = res.pt;
	i = res.i;

	if(res.tag == 1) {
		return ;
	}else {
		while(q && !finished) {
			Insert(q, i, x, ap);
			if(q->keynum < m) {
				finished = true;
			}else {
				s = (m%2==0)? m/2: m/2+1;
				split(q, s, ap);//将q->key[s+1..m],q->ptr[s..m], q->recptr[s+1..m]移入新节点 *ap
				x = q->key[s];
				q = q->parent;
				if(q) {
					i = Search(q, x);
				}
			}
		}
		if (!finished) {//T为空树，或根节点已分裂为*q和*ap
			NewRoot(T, q, x, ap);//生成一个含信息(T, x, ap)的新节点，原T和ap为其子树
		}
	}
}

void CreateBTree(BTree &T, KeyType w[], int n) {
	int i;
	for(i=0; i<n; i++) {
		InsertBTree(T, w[i]);
	}
}

void PrintBTree(BTree T) {
	int i;

	if(T) {
		for (i=0; i<= T->keynum; i++) {
			if(i < T->keynum) {
				PrintBTree(T->ptr[i]);
				printf("%d ", T->key[i+1]);
			}else {
				PrintBTree(T->ptr[i]);
			}
		}
	}
}

int main() {
	// KeyType w[] = {1, 2, 3};
	int w[] = {45, 24, 3, 37, 63, 90, 50, 61, 70, 100, 66, 2};
	BTree T = NULL;
	int n = 12;
	CreateBTree(T, w, n);
	PrintBTree(T);
}