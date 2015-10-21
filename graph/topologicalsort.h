/**
 * DAG有向无环图， 
 * AOV网：顶点代表活动，<v0, v1>代表v0必须先于v1进行
 * VOE网：弧表示活动，权表示活动持续的时间
 */

 #ifndef _TOPOLOGICALSORT_H_
 #define _TOPOLOGICALSORT_H_

bool TopologicalSort(ALGraph G);
void FindInDegree(ALGraph G, int indegree[]);;

bool TopologicalSort(ALGraph G) {
	int stack[MaxVertexNum];
	int top = -1;
	int indegree[MaxVertexNum];
	int i, count, v;
	ArcNode *p;

	FindInDegree(G, indegree);
	for(i=0; i<G.vexnum; i++) {
		if(indegree[i] == 0) {
			stack[++top] = i;
		}
	}
	count = 0;				//计数，记录当前已经输出的顶点数
	while(top != -1) {
		i = stack[top--];	//输出栈顶元素
		printf("%c ", G.vertices[i].data);
		count++;
		for(p=G.vertices[i].firstarc; p; p=p->nextarc) {
			//将所有顶点i指向的顶点的入度减1
			v = p->adjvex;
			if(!(--indegree[v])) {
				stack[++top] = v;	//入度为0，入栈
			}
		}
	}
	if(count < G.vexnum) {
		return false;		//排序失败，有向图中有回路
	}else {
		return true;
	}
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

 #endif

// #include <stdio.h>
// #include <stdlib.h>

// #include "graph.h"
// #include "topologicalsort.h"

// int main() {
// 	ALGraph G;
// 	CreateDG(G);
// 	TopologicalSort(G);
// }