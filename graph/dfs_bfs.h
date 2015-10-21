/**
 * DFS, BFS, 
 * DFSForest：建立无向图G的深度优先生成森林的孩子兄弟链表
 */

#ifndef _DFS_BFS_H_
#define _DFS_BFS_H_

#include "graph.h"
#include "cstree.h"

bool visited[MaxVertexNum];
typedef ALGraph Graph;

/* 函数声明 */
void BFSTraverse(Graph G);//广度优先搜索遍历
void BFS(Graph G, int v);
void BFS_MIN_Distance(Graph G, int u);//无向图，单源最短路径，d(u,i)
void DFSTraverse(Graph G);//深度优先搜索遍历
void DFS(Graph G, int v);
void DFSForest(Graph G, CSTree &T);//建立无向图G的深度优先生成森林的孩子兄弟链表
void DFSTree(Graph G, int v, CSTree T);//从第v个顶点出发深度优先遍历图G，建立以T为根的生成树

/* 函数实现 */
int queue[MaxVertexNum];//广度优先搜索需要一个辅助队列
int front, rear;
void BFSTraverse(Graph G) {
	int i;

	for(i=0; i<G.vexnum; i++) {//init visited[]
		visited[i] = false;
	}
	front = 0; rear = 0; //init queue
	for(i=0; i<G.vexnum; i++) {
		if(!visited[i]) {
			BFS(G, i);
		}
	}
}

void BFS(Graph G, int v) {
	int w;
	printf("%c ", G.vertices[v].data);
	visited[v] = true;
	queue[rear++] = v;//EnQueue(Q, v)
	while(front != rear) {
		v = queue[front++];
		for (w = FirstNeighbor(G, v); w>=0; w=NextNeighbor(G, v, w)) {
			if(!visited[w]) {
				printf("%c ", G.vertices[w].data);
				visited[w] = true;
				queue[rear++] = w;
			}
		}
	}
}

int d[MaxVertexNum];
void BFS_MIN_Distance(Graph G, int u) {
	int i;
	int w;

	front = 0, rear = 0;		//InitQueue
	for(i=0; i<G.vexnum; i++) {
		d[i] = INFINITY;
	}
	visited[u] = true;
	d[u] = 0;
	queue[rear++] = u;			//EnQueue
	while(front != rear) {
		u = queue[front++];
		for(w=FirstNeighbor(G, u); w>=0; w=NextNeighbor(G, u, w)) {
			if(!visited[w]) {
				visited[w] = true;
				d[w] = d[u] + 1;
				queue[rear++] = w;	//EnQueue
			}
		}
	}
}

void DFSTraverse(Graph G) {
	int v;
	for(v=0; v<G.vexnum; v++) {
		visited[v] = false;
	}
	for(v=0; v<G.vexnum; v++) {
		if(!visited[v]) {
			DFS(G, v);
		}
	}
}

void DFS(Graph G, int v) {
	int w;

	printf("%c ", G.vertices[v].data);
	visited[v] = true;
	for(w=FirstNeighbor(G, v); w>=0; w=NextNeighbor(G, v, w)) {
		if(!visited[w]) {
			DFS(G, w);
		}
	}
}

//深度优先搜索的非递归算法
void DFS_Non_RC(ALGraph G, int v) {
	int w, i, k;
	int stack[MaxVertexNum];
	int top = -1;
	for(i=0; i<G.vexnum; i++) {
		visited[i] = false;
	}
	stack[++top] = v;
	visited[v] = true;
	while(top != -1) {
		k = stack[top--];
		printf("%c ", G.vertices[k].data);
		for(w=FirstNeighbor(G, k); w>=0; w=NextNeighbor(G, k, w)) {
			if(!visited[w]) {
				stack[++top] = w;
				visited[w] = true;
			}
		}
	}
}

void DFSForest(Graph G, CSTree &T) {
	int v;
	CSTree p, q;
	T = NULL;
	for(v=0; v<G.vexnum; v++) {
		visited[v] = false;
	}
	for(v=0; v<G.vexnum; v++) {
		if(!visited[v]) {
			p = (CSTree)malloc(sizeof(CSNode));
			if(!p) {
				return ;
			}
			p->data = G.vertices[v].data;
			p->lchild = NULL;
			p->nextsibling = NULL;

			if(!T) {	//第一棵生成树的根
				T = p;
			}else {
				q->nextsibling = p;	//其它树作为前一棵的右子树(nextsibling)
			}
			q = p;//q为当前生成树的根
			DFSTree(G, v, p);
		}
	}
}

void DFSTree(Graph G, int v, CSTree T) {	
//从第v个顶点出发深度优先遍历图G，建立以T为根的生成树
	int w;
	CSTree p, q;
	visited[v] = true;
	bool first = true;
	for(w=FirstNeighbor(G, v); w>=0; w=NextNeighbor(G, v, w)) {
		if(!visited[w]) {
			p = (CSTree)malloc(sizeof(CSNode));
			if(!p) {
				return ;
			}
			p->data = G.vertices[w].data;
			p->lchild = NULL;
			p->nextsibling = NULL;

			if(first) {
				T->lchild = p;
				first = false;
			}else {
				q->nextsibling = p;
			}
			q = p;
			DFSTree(G, w, q);
		}
	}
}


#endif


// #include <stdio.h>
// #include <stdlib.h>

// #include "graph.h"
// #include "dfs_bfs.h"


// int main() {
// 	ALGraph G;
// 	CreateUDG(G);
// 	CSTree T;
// 	// Display(G);
// 	// printf("DFS: ");
// 	// DFSTraverse(G);
// 	DFSForest(G, T);
// 	CSTreePrint(T);
// }