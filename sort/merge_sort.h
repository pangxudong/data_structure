#include "head.h"

//表A[low...mid]和表A[mid+1...high]各自有序，将它们合并
void Merge(Elems A, int low, int mid, int high) {
	int i, j, k;
	Elems B = (Elems)malloc((high+1)*sizeof(struct ElemType));
	for(k=low; k<=high; k++) {
		B[k] = A[k];
	}
	for(i=low, j=mid+1, k=i; i<=mid && j<=high; k++) {
		if(B[i].key <= B[j].key) {
			A[k] = B[i++];
		}else {
			A[k] = B[j++];
		}
	}
	while(i<=mid) A[k++] = B[i++];
	while(j<=high) A[k++] = B[j++];
}

//2-路归并排序
void MergeSort(Elems A, int low, int high) {
	int mid;
	if(low < high) {
		mid = (low + high) / 2 ;
		MergeSort(A, low, mid);
		MergeSort(A, mid+1, high);
		Merge(A, low, mid, high);
	}
}