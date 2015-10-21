#include "selection_sort.h"

int main() {
	int i, n;
	Elems A;
	n = Init(A);
	HeapSort(A, n);
	Print(A,n);
}