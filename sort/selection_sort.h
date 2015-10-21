#include "head.h"

void Swap(Elems A, int i, int j) {
	A[0] = A[i];
	A[i] = A[j];
	A[j] = A[0];
}

//简单选择排序
void SelectionSort(Elems A, int n) {
	int i, j, min;
	for (i=1; i<n; i++) {
		min = i;
		for(j=i+1; j<=n; j++) {
			if (A[j].key <= A[min].key) {
				min = j;
			}
		}
		if(min!=i) {
			Swap(A, i, min);
		}
	}
}

//堆排序
void HeapSort(Elems A, int n) {
	int i;
	BuildMaxHeap(A, n);//初始建堆
	for(i=n; i>1; i--) {
		Swap(A, i, 1);//输出堆顶元素(和堆底元素交换)
		AdjustDown(A, 1, i-1);//把剩余i-1个元素整理成堆
	}
}

void BuildMaxHeap(Elems A, int n) {
	int i;
	for(i=n/2; i>0; i--) {//自下而上逐步调整为大根堆
		AdjustDown(A, i, n);//将元素i向下进行调整
	}
}

void AdjustDown(Elems A, int k, int n) {
	int i, j;
	A[0] = A[k];
	for(i=2*k; i<=n; i*=2) {//沿key较大者向下筛选
		if(i<n && A[i].key<A[i+1].key) {
			i++;
		}
		if(A[0].key >= A[i].key) break;
		else {
			A[k] = A[i];
			k = i;
		}
	}
	A[k] = A[0];
}

//大根堆，插入元素时用，先把元素加至堆底,向上调整
void AdjustUp(Elems A, int k) {
	A[0] = A[k];
	int i = k/2;
	while(i>0 && A[i].key < A[0].key) {
		A[k] = A[i];
		k = i;
		i = k/2;
	}
	A[k] = A[0];
}