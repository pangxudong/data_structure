#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

bool visited[MaxVertexNum];
int finishTime[MaxVertexNum];
int time;

void DFSTraverse(ALGraph G);
void DFS(ALGraph G, int v);

void DFSTraverse(ALGraph G) {
	int v;
	for(v=0; v<G.vexnum; v++) {
		visited[v] = false;
	}
	time = 0;
	for(v=0; v<G.vexnum; v++) {
		if(!visited[v]) {
			DFS(G, v);
		}
	}
}

void DFS(ALGraph G, int v) {
	int w;
	visited[v] = true;
	for(w=FirstNeighbor(G, v); w>=0; w = NextNeighbor(G, v, w)) {
		if(!visited[w]) {
			DFS(G, w);
		}
	}
	time = time + 1;
	finishTime[v] = time;
}

int main() {
	int i;
	ALGraph G;
	CreateDG(G);//有向图
	// Display(G);
	DFSTraverse(G);
	for(i=0; i<G.vexnum; i++) {
		printf("%c:%d\t", G.vertices[i].data, finishTime[i]);
	}
}