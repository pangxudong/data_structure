#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int elem[1000];
	int len;
} List;

List Init() {//void Init(List * L)的话,下边要用L->len...
	int x;
	List L;
	L.len = 1;//数组从A[1]开始
	printf("input A(input 9999 to stop): ");
	scanf("%d", &x);
	while(x!=9999) {
		L.elem[L.len++] = x;
		scanf("%d", &x);
	}
	L.len -= 1;
	return L;
}

void Print(List L) {
	int i;
	for(i=1; i<=L.len; i++) {
		printf("%d ", L.elem[i]);
	}
}