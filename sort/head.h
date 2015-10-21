#include <stdio.h>
#include <stdlib.h>

typedef struct ElemType {
	int key;
	char value;
} *Elems;

int Init(Elems A) {
	int x, len=1;//数组从A[1]开始
	printf("input A(input 9999 to stop): ");
	scanf("%d", &x);
	while(x!=9999) {
		A[len++].key = x;
		scanf("%d", &x);
	}
	return len-1;//数组长度
}

void Print(Elems A, int n) {
	int i;
	for(i=1; i<=n; i++) {
		printf("%d ", A[i].key);
	}
	printf("\n");
}