#include "cstree.h"

//返回存储森林的叶子节点个数
int Leaves(CSTree T) {
	if(T == NULL) {
		return 0;
	}
	if(T->fch == NULL) {
		return 1+Leaves(T->nsib);
	}else {
		return Leaves(T->fch) + Leaves(T->nsib);
	}
}

int main() {
	CSTree T;
	T = CreateCSTree(T);//输入：ab#cd#### 返回：2
	BeautifulPrint(T);
	printf("%d\n", Leaves(T));
}