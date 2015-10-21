#include "tree.h"

//寻找节点p和q的最近公共祖先,(后序遍历)
Tree Ancestor(Tree T, Tree n1, Tree n2) {
	Tree s[100], s1[100];//s1为辅助栈
	int top = -1, top1, i, j;

	Tree p = T;
	Tree temp = NULL;
	Tree lastVisit = NULL;

	while(p || top != -1) {
		if(p) {
			s[++top] = p;
			if (p == n1) {//假设n1在n2左侧,会被先遍历到
				for(i=0; i<top; i++) {//记录p的路径到辅助栈
					s1[i] = s[i];
				}
				top1 = top;
			}
			if (p == n2) {//找到n2后 匹配
				for(i = top; i>=0; i--) {
					for (j= top1; j>=0; j--) {//j=top1,妙
						if(s1[j] == s[i]) {
							return s[i];
						}
					}
				}
			}
			p = p->lchild;
		}
		temp = s[top];
		if(temp->rchild == NULL || temp->rchild == lastVisit) {
			lastVisit = s[top--];
		}else {
			p = temp->rchild;
		}
	}
}

int main() {
	Tree T;
	T = CreateBiTree(T);//测试输入：ab#c### 返回: b
	Tree n1 = T->lchild;
	Tree n2 = n1->rchild;
	printf("%c\n", Ancestor1(T, n1, n2)->data);
}

/*
//王道答案
typedef struct {
	Tree t;
	int tag;
}stack;
stack s[], s1[];

Tree Ancestor1(Tree root, Tree p, Tree q) {
	int top = 0, top1, i, j;
	Tree bt = root;
	while(bt || top > 0) {
		while(bt && bt!=p && bt!=q) {
			while(bt) {
				s[++top].t = bt;
				s[top].tag = 0;
				bt = bt->lchild;
			}
			while(top!=0 && s[top].tag == 1) {
				if(s[top].t == p) {
					for(i=1; i<=top; i++) {
						s1[i] = s[i];
					}
					top1 = top;
				}
				if(s[top].t == q) {
					for(i=top; i>0; i--) {
						for(j=top1; j>0; j--) {
							if(s1[j].t == s[i].t) {
								return s[i].t;
							}
						}
					}
					top--;
				}
				if(top != 0) {
					s[top].tag = 1;
					bt=s[top].t->rchild;
				}
			}
		}
	}
	return NULL;
}
*/