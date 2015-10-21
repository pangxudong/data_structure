

#ifndef _CRITICALPATH_H_
#define _CRITICALPATH_H_

int TopologicalSort(ALGraph G,  int ve[]);
void CriticalPath(ALGraph G);
void FindInDegree(ALGraph G, int indegree[]);
void showTable(ALGraph G);

/**
 * 算法7.13，有向网G采用邻接表存储，求各顶点事件的最早发生时间ve
 * T为拓扑序列顶点栈
 * 若G无回路，则用栈T返回G的一个拓补序列，且函数值为OK，否则为ERROR
 */
 int stackt[MaxVertexNum];	//
 int topt = -1;

 int TopologicalSort(ALGraph G, int ve[]) {
 	int indegree[MaxVertexNum];
 	int count, i, j, k;
 	int arcvalue = 0;
 	ArcNode *p;

 	int stacks[MaxVertexNum];
 	int tops = -1;

 	FindInDegree(G, indegree);
 	for(i=0; i<G.vexnum; i++) {
 		if(0==indegree[i]) {
 			stacks[++tops] = i;
 		}
 	}
 	count = 0;
 	for(i=0; i<G.vexnum; i++) {
 		ve[i] = 0;
 	}
 	while(tops != -1) {
 		j = stacks[tops--];
 		stackt[++topt] = j;
 		++count;
 		for(p=G.vertices[j].firstarc; p; p= p->nextarc) {
 			k = p->adjvex;
 			--indegree[k];
 			if(0 == indegree[k]) {
 				stacks[++tops] = k;
 			}
 			arcvalue = p->weight;
 			if(ve[j] + arcvalue > ve[k]) {	//选择最大的，这一步最关键
 				ve[k] = ve[j] + arcvalue;
 			}
 		}
 	}
 	if(count < G.vexnum) {
 		return ERROR;
 	} else {
 		return OK;
 	}
 }



/**
 * 算法7.14，G为有向网，输出G的各项关键活动
 * 栈T中保存图G的拓补序列，ve数组中为各顶点的最早开始时间
 */

int ve[MaxVertexNum];
int vl[MaxVertexNum];
void CriticalPath(ALGraph G) {
	int i, j, k, dut, ee, el;
	ArcNode *p;
	// int ve[MaxVertexNum];
	// int vl[MaxVertexNum];
	if(ERROR == TopologicalSort(G, ve)) {
		printf("topological sort failure!\n");
		return ;
	}
	for(i=0; i<G.vexnum; i++) {		//初始化顶点的最迟发生时间
		vl[i] = ve[G.vexnum-1];
	}
	while(topt != -1) {				//按拓扑逆序求各顶点的最晚开始时间vl值
		j = stackt[topt--];
		for(p=G.vertices[j].firstarc; p; p=p->nextarc) {
			k = p->adjvex;
			dut = p->weight;		//活动时间
			if(vl[k] - dut < vl[j]) {
				vl[j] = vl[k] - dut;
			}
		}
	}

	printf("关键活动: ");
	for(j=0; j<G.vexnum; j++) {
		for(p=G.vertices[j].firstarc; p; p=p->nextarc) {
			k = p->adjvex;
			dut = p->weight;
			ee = ve[j];		//活动的最早开始时间
			el = vl[k] - dut;	//活动最晚开始时间
			if (ee == el) {
				printf("%c%c ", G.vertices[j].data, G.vertices[k].data);
			}
		}
	}
	printf("\n");

}

//求邻接表表示的有向图G的各顶点的入度，indegree数组中保存各顶点的入度
void FindInDegree(ALGraph G, int indegree[]) {
	int i, j;
	ArcNode *p;
	for(i=0; i<G.vexnum; i++) {
		indegree[i] = 0;
	}
	for(i=0; i<G.vexnum; i++) {
		for(p= G.vertices[i].firstarc; p; p=p->nextarc) {
			j = p->adjvex;
			++indegree[j];
		}
	}
}

//打印求关键路径的中间变量
void showTable(ALGraph G) {
	int i, j, dut;
	ArcNode *p;
	int ee[MaxVertexNum], el[MaxVertexNum]; 
	printf("v:\t");
	for(i=0; i<G.vexnum; i++) {
		printf("%4c", 'a'+i);
	}
	printf("\nve:\t");
	for(i=0; i<G.vexnum; i++) {
		printf("%4d", ve[i]);
	}
	printf("\nvl:\t");
	for(i=0; i<G.vexnum; i++) {
		printf("%4d", vl[i]);
	}

}

#endif


// #include <stdio.h>
// #include <stdlib.h>

// #include "graph.h"
// #include "criticalpath.h"

// int main() {
// 	ALGraph G;
// 	CreateDN(G);
// 	CriticalPath(G);
 // showTable(G);
// }