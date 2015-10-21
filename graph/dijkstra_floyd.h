/**
 *最短路径算法，Dijkstra， Floyd
 */
#ifndef _DIJKSTRA_FLOYD_H_
#define _DIJKSTRA_FLOYD_H_

#include "graph.h"

typedef bool PathMatrix[MaxVertexNum][MaxVertexNum];
typedef int ShortPathTable[MaxVertexNum];
typedef bool PathMatrix1[MaxVertexNum][MaxVertexNum][MaxVertexNum];
typedef int DistanceMatrix[MaxVertexNum][MaxVertexNum];

void Dijkstra(MGraph G, int v0, PathMatrix &P, ShortPathTable &D);
void CopyPath(PathMatrix &P, int w, int v);
void DisplayShorstPath_DIJ(MGraph G, int v0, PathMatrix P, ShortPathTable D);
void Floyd(MGraph G, PathMatrix1 &P, DistanceMatrix &D);
void DisplayShorstPath_FLOYD(MGraph G, PathMatrix1 P, DistanceMatrix D);
/**
 * 算法7.15，最短路径算法，Dijkstra算法
 * 返回有向网G的v0顶点到其余顶点v的最短路径P[v], 及其带权长度为D[v]
 * P[v][w]==true,则w是v0从v到当前求得最短路径上的顶点
 * final[v]==true当且仅当v属于S，即已经求得从v0到v的最短路径
 */
void Dijkstra(MGraph G, int v0, PathMatrix &P, ShortPathTable &D) {
	int v, w, i, min;
	bool final[MaxVertexNum];

	for(v=0; v<G.vexnum; v++) {//初始化
		final[v] = false;
		D[v] = G.Edge[v0][v];
		for(w=0; w<G.vexnum; w++) {
			P[v][w] = false;
		}
		if(D[v] <INFINITY) {//v与v0直接相连
			P[v][v0] = true;
			P[v][v] = true;
		}
	}
	D[v0] = 0;
	final[v0] = true;		//v0属于S集, 初始化

	// 开始主循环，每次求得v0到某个顶点的最短路径，并加入v到S集
	for(i=1; i<G.vexnum; i++) {
		min = INFINITY;
		for(w=0; w<G.vexnum; w++) {		
			if(!final[w]) {				//w在V-S中
				if(D[w] < min) {		//w离v0更近
					v = w;
					min = D[w];
				}
			}
		}
		final[v] = true;		//V-S中离v0最近的v点加入S
		for(w=0; w<G.vexnum; w++) {	//更新V-S中顶点当前最短路径及距离
			if(!final[w] && (min+G.Edge[v][w] < D[w])) {
				D[w] = min + G.Edge[v][w];
				CopyPath(P, w, v);
				P[w][w] = true;
			}
		}
	}
}

void CopyPath(PathMatrix &P, int w, int v) {
//复制最短路径算法顶点v的路径到顶点w
	int i;
	for (i = 0; i < MaxVertexNum; i++) {
		P[w][i] = P[v][i];
	}
}

void DisplayShorstPath_DIJ(MGraph G, int v0, PathMatrix P, ShortPathTable D)
{
	int i ,j;
	printf("从顶点%c出发到其余各顶点的最短路径如下：\n", G.Vex[v0]);
	for (i = 0; i < G.vexnum; i++) {
		if (i != v0) {
			if (INFINITY == D[i]) {
				printf("顶点%c不可到达！", G.Vex[i]);
			} else {
				printf("顶点%c(距离%d)：", G.Vex[i], D[i]);
				for (j = 0; j < G.vexnum; j++) {
					if (true == P[i][j]) {
						printf("%c ", G.Vex[j]);
					}
				}	
			}
			printf("\n");
		}
	}
}

/**
 * 算法7.16, 用Floyd算法求有向网G中各对顶点v和w之间的最短路径P[v][w]及其带权长度D[v][w],
 * 若P[v][w][u]为true则u是从v到w当前求得最短路径上的顶点
 */
void Floyd(MGraph G, PathMatrix1 &P, DistanceMatrix &D) {
	int v, w, u, i;
	for(v=0; v<G.vexnum; v++) {
		for(w=0; w<G.vexnum; w++) {
			D[v][w] = G.Edge[v][w];
			for(u=0; u<G.vexnum; u++) {
				P[v][w][u] = false;
			}
			if(D[v][w] < INFINITY) {	//v到w有直接路径
				P[v][w][v] = true;
				P[v][w][w] = true;
			}
		}
	}

	for(u=0; u<G.vexnum; u++) {
		for(v=0; v<G.vexnum; v++) {
			for(w=0; w<G.vexnum; w++) {
				if(D[v][u] != INFINITY && D[u][w] != INFINITY && D[v][u] + D[u][w] < D[v][w]) {
					D[v][w] = D[v][u] + D[u][w];	//从v经u到w的一条路径更短
					for(i=0; i<G.vexnum; i++) {	//更新路径
						P[v][w][i] = P[v][u][i] || P[u][w][i];
					}
				}
			}
		}
	}

}

void DisplayShorstPath_FLOYD(MGraph G, PathMatrix1 P, DistanceMatrix D) {
	int i, j, k;
	for (i = 0; i < G.vexnum; i++) {
		for (j = 0; j < G.vexnum; j++) {
			if (i != j) {
				if (INFINITY == D[i][j]) {
					printf("节点%c到%c不可到达！\n", G.Vex[i], G.Vex[j]);
				} else {
					printf("节点%c%c之间(最短距离%d)：", G.Vex[i], G.Vex[j], D[i][j]);
					for (k = 0; k < G.vexnum; k++) {
						if (true == P[i][j][k]) {
							printf("%c", G.Vex[k]);
						}
					}
					printf("\n");
				}
			}
		}
	}
}


#endif


// int main() {
// 	int i, j;
// 	PathMatrix P;
// 	ShortPathTable D;

// 	MGraph G;
// 	CreateUDN(G);
// 	Display(G);
// 	Dijkstra(G, 0, P, D);
// 	DisplayShorstPath_DIJ(G, 0, P, D);
// }

// #include <stdio.h>
// #include <stdlib.h>

// #include "graph.h"
// #include "dijkstra_floyd.h"

// int main() {
// 	int i, j;
// 	PathMatrix1 P;
// 	DistanceMatrix D;

// 	MGraph G;
// 	CreateUDN(G);
// 	Display(G);
// 	Floyd(G, P, D);
// 	DisplayShorstPath_FLOYD(G, P, D);
// }