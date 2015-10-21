#include "head.h" 
#include <math.h>

//枢轴值随机
void QuickSort1(Elems A, int low, int high) {
	if(low<high) {
		int pivotpos = Partion1(A, low, high);
		QuickSort(A, low, pivotpos-1);
		QuickSort(A, pivotpos+1, high);
	}
}

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

int main() {
	int i, n;
	Elems A;
	n = Init(A);
	QuickSort(A,1,n);
	Print(A,n);
}