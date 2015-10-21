#include "stack.h"

int main() {
	int a[] = {1,2,3,3,2,1};
	int len = 6;
	int i = 0;
	Stack s;
	InitStack(s);
	while(i<len/2) {
		Push(s, a[i++]);
	}
	if(len%2==1) {
		i++;
		while(i<len) {
			if(a[i] != Pop(s)) {
				printf("1no!\n");
				break;
			}
			i++;
		}
		if(i==len) {
			printf("1yes!\n");
		}
	}else {
		while(i<len) {
			if(a[i] != Pop(s)) {
				printf("2no!\n");
				break;
			}
			i++;
		}
		if(i==len) {
			printf("2yes\n");
		}
	}
}