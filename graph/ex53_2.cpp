#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

typedef ALGraph Graph;

bool isTree(Graph G);
void DFS(Graph &G, int v, int &Vnum, int &Enum, bool visited[]);

bool visited[MaxVertexNum];
int count=0;

bool isTree(Graph G) {
	int i;
	for(i=1; i<=G.vexnum; i++) {
		visited[i] = false;
	}
	int Vnum=0, Enum=0;
	DFS(G, 1, Vnum, Enum, visited);//DFS(G, v, Vnum, Enum, visited); v=(0...vexnum-1)
	if(Vnum==G.vexnum && Enum==2*(G.vexnum-1)) {
		return true;
	}else {
		return false;
	}
}

void DFS(Graph &G, int v, int &Vnum, int &Enum, bool visited[]) {
	visited[v] = true;
	Vnum++;
	int w = FirstNeighbor(G, v);
	while(w!=-1) {
		Enum++;
		if(!visited[w]) {
			DFS(G, w, Vnum, Enum, visited);
		}
		w = NextNeighbor(G, v, w);
	}
}

int main() {
	Graph G;
	CreateUDG(G);
	if(isTree(G)) {
		printf("yes\n");
	}
}