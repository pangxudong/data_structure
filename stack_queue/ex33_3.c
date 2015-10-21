#include <stdio.h>

int P[1000];
int top;

void GetPn(int x, int n) {
	P[0] = 1;
	P[1] = 2 * x;
	int f1 = P[0];
	int f2 = P[1];

	top = 1;
	while(top < n) {
		++top;
		P[top] = 2 * x * f2 - 2*(top-1)*f1;
		f1 = f2;
		f2 = P[top];
	}
}

int main() {
	int x = 1;
	int n = 3;
	GetPn(x, n);
	printf("Pn=%d\n",P[top]);
}
