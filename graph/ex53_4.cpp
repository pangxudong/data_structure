#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

int visited[MaxVertexNum] = {0};

//深度优先搜索 路径
int Exist_Path_DFS(ALGraph G, int i, int j) {
	int p;
	if(i==j) {
		return 1;
	}else {
		visited[i] = 1;
		for(p=FirstNeighbor(G, i); p>=0; p=NextNeighbor(G, i, p)) {
			if(!visited[p] && Exist_Path_DFS(G, p, j)) {
				return 1;
			}
		}
	}
	return 0;
}

int Exist_Path_BFS(ALGraph G, int i, int j) {
	int u, p;
	int queue[MaxVertexNum];
	int front = 0, rear = 0;
	
	for(p=0; p<G.vexnum; p++) {
		visited[p] = 0;
	}

	queue[rear++] = i;
	while(front != rear) {
		u = queue[front++];
		visited[u] = 1;
		for(p=FirstNeighbor(G, u); p>=0; p=NextNeighbor(G, u, p)) {	//p>=0不能不写
			if (p==j) {
				return 1;
			}
			if (!visited[p]) {
				queue[rear++] = p;
			}
		}
	}
	return 0;
}

int main() {
	ALGraph G;
	CreateUDG(G);
	// Display(G);
	// if(Exist_Path_DFS(G, 0, 3)){
	// 	printf("yes\n");
	// }
	if(Exist_Path_BFS(G, 0, 3)){
		printf("yes\n");
	}
}