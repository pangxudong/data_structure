#include "cstree.h"

//求森林的高度
int Height(CSTree T) {
	int hc, hs;
	if(T==NULL) {
		return 0;
	}else {
		hc = Height(T->fch);
		hs = Height(T->nsib);
		if(hc+1 >hs) {
			return hc + 1;
		}else {
			return hs;
		}
	}
}

int main() {
	CSTree T;
	T = CreateCSTree(T);//输入：ab##c#d### 返回：2
	BeautifulPrint(T);
	printf("%d\n", Height(T));
}