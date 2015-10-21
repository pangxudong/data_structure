#include "tree.h"

int Width(Tree T) {
	Tree queue[100];
	int front = 0, rear = 0;

	Tree p;
	int num = 1, tnum=0, max = 1;

	queue[rear++] = T;
	while(num--) {
		p = queue[front++];
		if(p->lchild) {
			queue[rear++] = p->lchild;
			tnum++;
		}
		if(p->rchild) {
			queue[rear++] = p->rchild;
			tnum++;
		}
		if(num==0) {
			num = tnum;
			max = max > num ? max : num;
			tnum = 0;
		}
	}
	return max;
}

int main() {
	Tree T;
	T = CreateBiTree(T);//测试: abc##d##ef##g## 返回：4
	printf("%d\n", Width(T));
}