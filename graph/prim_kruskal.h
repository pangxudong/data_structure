/**
 * 连通网的最小生成树，prim算法，kruskal算法
 */
#ifndef _PRIM_KRUSKAL_H_
#define _PRIM_KRUSKAL_H_

#include "graph.h"

typedef struct {	//记录从顶点集U到V-U的代价最小的边的辅助数组
	VertexType adjvex;
	EdgeType lowcost;
}LowEdge, lowedge[MaxVertexNum];//closedge

void Prim(MGraph G, VertexType u);
int minimum(LowEdge *closedge, int len);

void Prim(MGraph G, VertexType u) {
//prim算法从第u个顶点出发构造网G的最小生成树T,输出T的各边
	int i, j, k;
	lowedge closedge;

	k = LocateVex(G, u);
	for(j=0; j<G.vexnum; j++) {//初始化closedge
		if(j!=k) {
			closedge[j].adjvex = u;
			closedge[j].lowcost = G.Edge[k][j];
		}
	}
	closedge[k].lowcost = 0;//把u加入U,初始化完成

	printf("最优树的边： \n");
	for(i=1; i<G.vexnum; i++) {	//选择其余G.vexnum-1个顶点
		k = minimum(closedge, G.vexnum);	//求出T的下一个结点
		printf("%c %c\n", closedge[k].adjvex, G.Vex[k]);
		closedge[k].lowcost = 0;		//第k顶点并入U集
		for(j=0; j<G.vexnum; j++) {	//新节点并入后，修改最小边集合
			if(G.Edge[k][j] < closedge[j].lowcost) {
				closedge[j].adjvex = G.Vex[k];
				closedge[j].lowcost = G.Edge[k][j];
			}
		}
	}
}

int minimum(LowEdge *closedge, int len) {
//求closedge中权值非0的最小的顶点
	int min, i, j;
	min = -1;
	for (i = 0; i < len; i++) {
		if (closedge[i].lowcost != 0) {
			min = i;
			break;
		}
	}

	for (j = i; j < len; j++) {
		if (closedge[j].lowcost != 0 && closedge[min].lowcost > closedge[j].lowcost) {
			min = j;
		}
	}
	return min;
}

#endif

// #include <stdio.h>
// #include <stdlib.h>

// #include "graph.h"
// #include "prim_kruskal.h"

// int main() {
// 	MGraph G;
// 	CreateUDN(G);
// 	Display(G);
// 	Prim(G, 'a');

// }