#include "linkqueue.h"

int main() {
	LQueue q;
	q = InitQueue(q);
	EnQueue(q, 126);
	printf("%d\n", DeQueue(q));
	// printf("q->front->data: %d\n", q->front->next->data);
}