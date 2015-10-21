#include "head.h"

//奇数调到偶数前边
void MySort(Elems A, int n) {
	int low = 1, high = n;
	while(low<high) {
		while(low<high && A[low].key%2==1) ++low;
		while(low<high && A[high].key%2==0) --high;
		if(low<high) {
			A[0] = A[low];
			A[low] = A[high];
			A[high] = A[0];
			++low;
			--high;
		}
	}
}

int main() {
	int i, n;
	Elems A;
	n = Init(A);
	MySort(A, n);
	Print(A,n);
}