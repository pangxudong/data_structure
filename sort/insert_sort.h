#include "head.h"


//直接插入排序
void InsertSort(Elems A, int n) {
	int i,j;
	for (i=2; i<=n; i++) {
		if(A[i].key < A[i-1].key) {
			A[0].key = A[i].key;
			for(j=i-1; A[0].key<A[j].key; --j) {
				A[j+1] = A[j];
			}
			A[j+1] = A[0];
		}
	}
}

//折半插入排序
void InsertSort2(Elems A, int n) {
	int i, j, low, high, mid;
	for(i=2; i<=n; i++) {
		A[0] = A[i];
		low = 1;
		high = i - 1;
		while(low<=high) {
			mid = (low + high) / 2;
			if(A[0].key > A[mid].key) {
				low = mid + 1;
			}else {
				high = mid - 1;
			}
		}
		for(j=i-1; j>high; --j) {
			A[j+1] = A[j];
		}
		A[high+1] = A[0];
	}
}

//希尔排序
void ShellSort(Elems A, int n) {
	int i, j, dk;
	for(dk=n/2; dk>=1; dk=dk/2) {//步长
		for(i=dk+1;i<=n; i++) {
			if(A[i].key < A[i-1].key) {//将A[i]插入有序增量子表
				A[0] = A[i];
				for (j=i-dk; j>0&&A[0].key < A[j].key; j-=dk) {//j>0
					A[j+dk] = A[j];//向后跳移
				}
				A[j+dk] = A[0];
			}
		}
	}
}

