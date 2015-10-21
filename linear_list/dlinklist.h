#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct DNode
{
	ElemType data;
	struct DNode *prior, *next;
}DNode, *DLinkList;

/*


*/

void Init(DlinkList L) {
	L = (DLinkList)malloc(sizeof(DNode));
	if(L) {
		L->next = L;
		L->prior = L;
	}else {
		exit(OVERFLOW);
	}
}

//循环链表，是否对称
int Symmetry(DlinkList L) {
	DNode *p = L->next, *q = L->prior;
	while(p!=q &&q->next!=p) {
		if(p->data == q->data) {
			p = p->next;
			q = q->prior;
		}else {
			return 0;
		}
	}
	return 1;
}

