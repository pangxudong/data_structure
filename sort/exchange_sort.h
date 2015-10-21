#include "head.h"

void BubbleSort(Elems A, int n) {
	int i, j, flag;
	for(i=1; i<n; i++) {
		flag = 1;
		for(j=n; j>i; j--) {
			if(A[j-1].key > A[j].key) {
				A[0] = A[j];
				A[j] = A[j-1];
				A[j-1] = A[0];
			}
			flag = 0;
		}
		if(flag) {
			return ;
		}
	}
}

//快速排序
void QuickSort(Elems A, int low, int high) {
	if(low<high) {
		int pivotpos = Partition(A, low, high);
		QuickSort(A, low, pivotpos-1);
		QuickSort(A, pivotpos+1, high);
	}
}

int Partition(Elems A, int low, int high) {
	A[0] = A[low];
	while(low<high) {
		while(low<high && A[high].key>=A[0].key) {
			--high;
		}
		A[low] = A[high];
		while(low<high && A[low].key <= A[0].key) {
			++low;
		}
		A[high] = A[low];
	}
	A[low] = A[0];
	return low;
}

//枢轴值随机
void QuickSort1(Elems A, int low, int high) {
	if(low<high) {
		int pivotpos = Partion1(A, low, high);
		QuickSort(A, low, pivotpos-1);
		QuickSort(A, pivotpos+1, high);
	}
}

//枢轴值随机
int Partion1(Elems A, int low, int high) {
	int r = rand()%(high-low+1)+low;
	A[0] = A[r];
	A[r] = A[low];
	A[low] = A[0];
	while(low<high) {
		while(low<high && A[high].key>=A[0].key) --high;
		A[low] = A[high];
		while(low<high && A[low].key<=A[0].key) ++low;
		A[high] = A[low];
	}
	A[low] = A[0];
	return low;
}