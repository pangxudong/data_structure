#include "head.h"

int Top_k(Elems A, int k, int n) {
	int i, j, flag = 1;
	if(k>n||k<1) {
		return -1;
	}
	for(i=1;i<=k; i++) {
		flag = 1;
		for(j=n; j>i;--j) {
			if(A[j].key<A[j-1].key) {
				A[0] = A[j];
				A[j] = A[j-1];
				A[j-1] = A[0];
				flag = 0;
			}
		}
		if (flag) break;
	}
	return A[k].key;
}

//快排 top_k
int Kth_elem(Elems A, int low, int high, int k) {
	int pivot = A[low].key;
	int low_temp = low;
	int high_temp = high;
	while(low<high) {
		while(low<high && A[high].key>=pivot) --high;
		A[low] = A[high];
		while(low<high && A[low].key<=pivot) ++low;
		A[high] = A[low];
	}
	A[low].key = pivot;

	if(low == k) {
		return A[low].key;
	}else if(low<k) {
		return Kth_elem(A, low+1, high_temp, k);
	}else {
		return Kth_elem(A, low_temp, low-1, k);
	}
}

int main() {
	int i, n;
	Elems A;
	n = Init(A);
	printf("%d\n", Kth_elem(A, 1, n, 3));
}