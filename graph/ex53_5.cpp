#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int path[MaxVertexNum];
int visited[MaxVertexNum] = {0};

void FindPath(ALGraph G, int u, int v, int path[], int d) {	
	int w, i;
	ArcNode *p;

	path[d] = u;
	d++;

	visited[u] = 1;
	if (u == v) {	//if (u == v && d == 3) 可以限制路径长度
		for(i=0; i<d; i++) {
			printf("%c ", G.vertices[path[i]].data);
		}
		printf("\n");
	}
	p = G.vertices[u].firstarc;
	while(p!=NULL) {
		w = p->adjvex;
		if(visited[w] == 0) {
			FindPath(G, w, v, path, d);
		}
		p = p->nextarc;
	}
	visited[u] = 0;
}

int main() {
	ALGraph G;
	CreateUDG(G);
	int d = 0;
	FindPath(G, 0, 3, path, d);
}

/**
请输入图的顶点数、弧数：4 5
输入4个顶点：a b c d
输入第1条弧：a b
输入第2条弧：a c
输入第3条弧：b c
输入第4条弧：c d
输入第5条弧：b d
a b c d
a b d
a c b d
a c d
*/