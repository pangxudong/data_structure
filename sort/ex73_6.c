#include <stdio.h>

typedef enum{RED, WHITE, BLUE} color;

void Flag_arrange(color a[], int n) {
	int i=0, j=0, k=n-1;
	while(j<=k) {
		switch(a[j]) {
			case RED: Swap(a, i, j); i++; j++; break;
			case WHITE: j++; break;
			case BLUE: Swap(a, j, k); k--;
		}
	}
}

void Swap(color a[], int i, int j) {
	color c;
	c = a[i];
	a[i] = a[j];
	a[j] = c;
}

void Print_color(color a[], int n) {
	int i;
	for (i=0; i<n; i++) {
		switch(a[i]) {
			case RED: printf("RED ");break;
			case WHITE: printf("WHITE "); break;
			case BLUE: printf("BLUE "); break;
		}
	}
}

int main() {
	int i;
	color a[] = {RED, BLUE, BLUE, WHITE, WHITE, RED, RED};
	Flag_arrange(a, 7);
	Print_color(a, 7);
}