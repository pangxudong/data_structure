/*
单链表：头插，尾插，归并，逆置，排序，交集
author: 圆旭
*/
#include <stdlib.h>
#include <stdio.h>

typedef int ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

//头插法建表,倒序
LinkList Creat_front(LinkList L) {
	int x;
	LNode *p;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	scanf("%d",&x);
	while(x!=9999) {
		p = (LNode *)malloc(sizeof(LNode));
		p->data = x;
		p->next = L->next;
		L->next = p;
		scanf("%d",&x);
	}
	return L;
}

//尾插法建表，正序
LinkList Creat_end(LinkList L) {
	int i,x;
	L = (LinkList)malloc(sizeof(LNode));
	LNode *p, *s;
	s = L;
	scanf("%d", &x);
	while(x!=9999) {
		p = (LNode *)malloc(sizeof(LNode));
		p->data = x;
		s->next = p;
		s = p;
		scanf("%d", &x);
	}
	s->next = NULL;
	return L;
}

//逆置链表,原地逆置（头插）
void Reverse(LinkList L) {
	LNode *p,*s;
	p = L->next;
	L->next = NULL;
	s = L;
	while(p) {
		s = p->next;
		p->next = L->next;
		L->next = p;
		p = s;
	}
}

//链表排序，插入排序
void Sort(LinkList L) {
	LNode *p = L->next, *pre;
	LNode *r = p->next;
	p->next = NULL;//????
	p=r;
	while(p!=NULL) {
		r = p->next;
		pre = L;
		while(pre->next!=NULL && pre->next->data < p->data)
			pre = pre->next;
		p->next = pre->next;
		pre->next = p;
		p = r;
	}
}

//链表升序排序,冒泡排序
void Sort1(LinkList L) {
	int t;
	LNode *p, *s;
	p = L->next;
	while(p) {
		s = p->next;
		while(s) {
			if(s->data < p->data) {
				t = p->data;
				p->data = s->data;
				s->data = t;
			}
			s = s->next;
		}
		p = p->next;
	}
}


//两升序链表交集，同时出现在两集合中的元素，结果仅保留一个
LinkList Union(LinkList La, LinkList Lb) {
	LNode *pa, *pb, *pc;
	pa = La->next;
	pb = Lb->next;
	pc = La;

	while(pa && pb) {
		if(pa->data==pb->data) {
			pc->next = pa;
			pa = pa->next;
			pb = pb->next;
			pc = pc->next;
		}else if(pa->data < pb->data) {
			pa = pa->next;
		}else {
			pb = pb->next;
		}
	}
	pc->next = NULL;
	return La;
}


//B是否是A的子链表,Lb（data序列）是La的一部分
int Pattern(LinkList La, LinkList Lb) {
	LNode *p = La->next;
	LNode *pre = p;
	LNode *q = Lb->next;

	while(p&&q) {
		if (p->data == q->data) {
			p = p->next;
			q = q->next;
		}else {
			pre = pre->next;
			p = pre;
			q = Lb->next;
		}
	}
	if(q==NULL) {
		return 1;
	}else {
		return 0;
	}
}

/*
//找链表公共节点
LinkList Search_1st_common(LinkList &L1, LinkList &L2) {}

//拆分链表A，奇数节点为A，偶数节点为B
LinkList Dis_create(LinkList &A) {
	return B;
}

//去掉链表中数据重复的节点
void Del_same(LinkList &L) {}

//双指针法:使用两个相同方向或者相反方向的指针进行扫描,游标

*/


//合并两个升序链表,为一个新的降序链表(头插)
LinkList Merge(LinkList La, LinkList Lb) {
	LNode *r, *pa = La->next, *pb = Lb->next;
	La->next = NULL;

	while(pa && pb) {
		if(pa->data <= pb->data) {
			r = pa->next;
			pa->next = La->next;
			La->next = pa;
			pa = r;
		}else {
			r = pb->next;
			pb->next = La->next;
			La->next = pb;
			pb = r;
		}
	}
	if(pa) {
		pb = pa;
	}
	while(pb) {
		r = pb->next;
		pb->next = La->next;
		La->next = pb;
		pb = r;
	}

	return La;
}



//查询链表倒数第k个节点的值
int Search_last_k(LinkList L, int k) {
	LNode *p = L->next;
	LNode *q = L->next;
	int count = 0;
	while(p!=NULL) {
		if (count<k) {
			count++;
		}
		else {
			q = q->next;
		}
		p = p->next;
	}
	if(count < k) {
		return 0;
	}else {
		printf("the last %d is: %d\n", k, q->data);
	}
}

void Print(LinkList L) {
	LNode *p=L->next;
	while(p) {
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}


/*
#include "linklist.h"
int main() {
	LinkList L1, L2;
	printf("input L1(input 9999 to stop): ");
	L1 = Creat_front(L1);
	printf("input L2(input 9999 to stop): ");
	L2 = Creat_end(L2);

	Sort(L2);
	Print(L2);
}*/