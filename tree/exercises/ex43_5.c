#include "tree.h"

//非递归算法，求二叉树高度。个人独创层次遍历方法(圆旭)
int Level(Tree T) {
	int num = 1, tnum = 0;
	int level = 1;
	Tree queue[100];
	int front = 0, rear = 0;
	queue[rear++] = T;
	Tree p = T;

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
			tnum = 0;
			level++;
		}
	}
	return level-1;
}

//王道的答案，非递归
int Btdepth(Tree T) {
	if(!T) {
		return 0;
	}
	int front = -1, rear = -1;
	int last = 0, level = 0;//last指向下层第一个位置
	Tree q[100];//maxsize = 100 队列
	q[++rear] = T;
	Tree p;
	while(front < rear) {
		p = q[++front];
		if(p->lchild) {
			q[++rear] = p->lchild;
		}
		if(p->rchild) {
			q[++rear] = p->rchild;
		}
		if(front == last) {
			level++;
			last = rear;//last 指向下层
		}
	}
	return level;
}

//递归方法
int Btdepth2(Tree T) {
	if(T==NULL) {
		return 0;
	}
	int ldep = Btdepth2(T->lchild);//子树加根节点
	int rdep = Btdepth2(T->rchild);
	if(ldep > rdep) {
		return ldep+1;
	}else {
		return rdep+1;
	}
}

int main() {
	Tree T;
	T = CreateBiTree(T);
	printf("%d\n", Level(T));
	printf("%d\n", Btdepth(T));
	printf("%d\n", Btdepth2(T));
}