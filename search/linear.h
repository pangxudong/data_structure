#include "head.h"

//顺序查找
int SeqSearch(List L, int key) {
	int i;
	L.elem[0] = key;//查找失败返回0
	for(i=L.len; L.elem[i]!=key; --i);
	return i;
}

//折半查找 L为升序表
int BinarySearch(List L, int key) {
	int low=1, high=L.len, mid;
	while(low<=high) {
		mid = (low + high) / 2;
		if(L.elem[mid] == key) {
			return mid;
		}else if(L.elem[mid] > key) {
			high = mid - 1;
		}else {
			low = mid + 1;
		}
	}
	return 0;
}

//ex6.2.5_5 折半查找 递归实现
int BinSearch(List L, int low, int high, int key) {
	int mid;
	while(low<= high) {
		mid = (low+high)/2;
		if(L.elem[mid] == key) {
			return mid;
		}else if(L.elem[mid] > key) {
			return BinSearch(L, low, mid-1, key);
		}else {
			return BinSearch(L, mid+1, high, key);
		}
	}
	return 0;
}

//ex6.2.5_3  k分查找法,3分为例  
int KSearch(List L, int key) {
	int mid1, mid2;
	int low=1, high=L.len;
	while(low<=high) {
		mid1 = low + (high-low)/3;
		mid2 = low + (high-low)*2/3;
		if(L.elem[mid1]==key) {
			return mid1;
		}else if(L.elem[mid1] > key) {
			high = mid1-1;
		}else {
			if(L.elem[mid2] == key) {
				return mid2;
			}else if(L.elem[mid2] > key) {
				low = mid1+1;
				high = mid2-1;
			}else {
				low = mid2+1;
			}
		}
	}
	return 0;
}
