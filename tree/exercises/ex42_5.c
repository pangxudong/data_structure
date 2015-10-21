//顺序表存储二叉树

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

//节点i和节点j的公共祖先
ElemType CommAncestor(ElemType T[], int i, int j) {
	if (T[i] != '#' && T[j] != '#') {
		while(i != j) {
			if(i>j) {
				i = i/2;
			}else {
				j = j/2;
			}
		}
		return T[i];
	}
}

int main() {
	/*这种存储结构显然要从数组下标 1 开始存储
	         (1) 
	        /   \   
	      (2)    (3)
	         \	    \
	         (4)    (5)
	        /
	       (6) 
	*/

	ElemType tree[] = {0,1,2,3,0,4,0,5,0,0,6,0};
	printf("%d\n", CommAncestor(tree, 4, 5));
}