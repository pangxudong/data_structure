#ifndef _GRAPH_H_
#define _GRAPH_H_

#define ERROR -1
#define OK 1
typedef int Status;

#define MaxVertexNum 100
typedef enum {DG, DN, UDG, UDN} GraphKind;	//有向图，有向网，无向图，无向网
typedef char VertexType;	//顶点类型
typedef char InfoType;

/* 邻接矩阵 */
#define INFINITY 123456
typedef int EdgeType;		//权值w,或0，1
typedef struct {
	VertexType Vex[MaxVertexNum];
	EdgeType Edge[MaxVertexNum][MaxVertexNum];
	int vexnum, arcnum;
}MGraph;


/* 邻接表 */
typedef struct ArcNode {		//边表节点
	int adjvex;					//该弧所指向的顶点位置
	EdgeType weight;
	struct ArcNode *nextarc;		//下一条弧的位置
}ArcNode;
typedef struct VNode {			//顶点表节点
	VertexType data;			//顶点信息
	ArcNode *firstarc;				//顶点指向的第一条弧
}VNode, AdjList[MaxVertexNum];
typedef struct {
	AdjList vertices;			//邻接表
	int vexnum, arcnum;			//图的顶点数和弧数
}ALGraph;

/*有向图的是自链表(Orthogonal List)表示 */
typedef struct ArcBox{
	int tailvex, headvex;		//该弧的尾和头顶点的位置
	struct ArcBox *hlink, *tlink;	//分别为弧头相同和弧尾相同的弧的链域
	InfoType *info;				//该弧的相关信息指针,权等
} ArcBox;
typedef struct VexNode{
	VertexType data;		//头结点
	ArcBox *firstin, *firstout;	//分别指向该顶点的第一条入弧和出弧
} VexNode;
typedef struct {
	VexNode xlist[MaxVertexNum];	//表头向量
	int vexnum, arcnum;
}OLGraph;

/* 无向图的邻接多重链表存储表示形式 */
typedef enum {unvisited, visited} VisitIf;
typedef struct EBox {
	VisitIf mark;		//访问标记
	int ivex, jvex;		//该边依附的两个顶点位置
	struct EBox *ilink, *jlink;		//分别指向依附这两个顶点的下一条边
	IncInfo *info;
} EBox;
typedef struct VexBox {
	VertexType data;
	EBox *firstedge;	//指向第一条依附该顶点的边
} VexBox;
typedef struct {
	VexBox adjmulist[MaxVertexNum];	//无向图顶点向量
	int vexnum, edgenum;		
}AMLGraph;

/* 函数声明 */
Status CreateUDN(MGraph &G);	//（邻接矩阵）表示法，构造无向网G
Status CreateDN(MGraph &G);		//（邻接矩阵）表示法，构造有向网G
int LocateVex(MGraph G, VertexType u);
int LocateVex(ALGraph G, VertexType u);
int LocateVex(OLGraph G, VertexType u);
Status CreateDG(OLGraph &G);
Status CreateDN(ALGraph &G);
Status CreateUDG(ALGraph &G);
Status CreateDG(ALGraph &G);
int FirstNeighbor(ALGraph G, int v);//返回指定第v个顶点的第一个邻接顶点的位置，若顶点在G中不存在邻接顶点，返回-1
int NextNeighbor(ALGraph G, int v, int w);//返回v的下一个(相对于w)的邻接顶点的位置，若w是最后一个，则返回-1
void Display(MGraph G);
void Display(ALGraph G);
void Input(InfoType * &info);

/* 函数实现 */
Status CreateUDN(MGraph &G) {
	int i, j, k;
	VertexType v1, v2;
	EdgeType w;

	printf("请输入图的顶点数、弧数：");
	scanf("%d %d", &G.vexnum, &G.arcnum);
	getchar();
	printf("输入%d个顶点：", G.vexnum);
	for(i=0; i<G.vexnum; i++) {
		scanf("%c", &G.Vex[i]);
		getchar();
	}
	for(i=0; i<G.vexnum; i++) {
		for(j=0; j<G.vexnum; j++) {
			G.Edge[i][j] = INFINITY;
		}
	}
	for(k=0; k<G.arcnum; k++) {
		printf("输入第%d条弧：", k+1);
		scanf("%c %c %d", &v1, &v2, &w);
		getchar();
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		G.Edge[i][j] = w;
		G.Edge[j][i] = G.Edge[i][j];
	}
	return OK;
}

//有向网
Status CreateDN(MGraph &G) {
	int i, j, k;
	VertexType v1, v2;
	EdgeType w;

	printf("请输入图的顶点数、弧数：");
	scanf("%d %d", &G.vexnum, &G.arcnum);
	getchar();
	printf("输入%d个顶点：", G.vexnum);
	for(i=0; i<G.vexnum; i++) {
		scanf("%c", &G.Vex[i]);
		getchar();
	}
	for(i=0; i<G.vexnum; i++) {
		for(j=0; j<G.vexnum; j++) {
			G.Edge[i][j] = INFINITY;
		}
	}
	for(k=0; k<G.arcnum; k++) {
		printf("输入第%d条弧：", k+1);
		scanf("%c %c %d", &v1, &v2, &w);
		getchar();
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		G.Edge[i][j] = w;
	}
	return OK;
}


int LocateVex(MGraph G, VertexType u) {
	int i;
	for(i=0; i<G.vexnum; i++) {
		if(u == G.Vex[i]) {
			return i;
		}
	}
	printf("Locate ERROR!\n");
	return ERROR;
}

int LocateVex(ALGraph G, VertexType u) {
	int i;
	for(i=0; i<G.vexnum; i++) {
		if(u == G.vertices[i].data) {
			return i;
		}
	}
	printf("Locate ERROR\n"); 
	return ERROR;
}

int LocateVex(OLGraph G, VertexType u) {
	int i;
	for(i=0; i<G.vexnum; i++) {
		if (u == G.xlist[i].data) {
			return i;
		}
	}
	printf("Locate ERROR\n"); 
	return ERROR;
}

//输入弧的相关信息
void Input(InfoType * &info)
{
	info = (InfoType *)malloc(50 * sizeof(InfoType));
	printf("输入弧的信息：");
	gets(info);
}

//创建十字链表存储表示的有向图
int CreateDG(OLGraph &G) {
	int i, j, k, IncInfo;
	VertexType v1, v2;
	ArcBox *p;
	printf("输入有向图顶点数和弧数及弧是否含信息(0/1): ");
	scanf("%d %d %d", &G.vexnum, &G.arcnum, &IncInfo);
	getchar();
	printf("输入%d个顶点(空格分隔)：", G.vexnum);
	for(i=0; i<G.vexnum; i++) {		//构造表头向量
		scanf("%c", &G.xlist[i].data);
		G.xlist[i].firstin = NULL;
		G.xlist[i].firstout = NULL;
		getchar();
	}
	for(k=0; k<G.arcnum; k++) {		//输入各弧构造十字链表
		printf("输入第%d条弧：", k+1);
		scanf("%c %c", &v1, &v2);
		getchar();
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		p = (ArcBox *)malloc(sizeof(ArcBox));
		if (!p) {
			return ERROR;
		}
		(*p).headvex = j;
		(*p).tailvex = i;
		(*p).hlink = G.xlist[j].firstin;	
		(*p).tlink = G.xlist[i].firstout;
		(*p).info = NULL;
		G.xlist[i].firstout = G.xlist[j].firstin = p;	//入弧和出弧链头的插入,头插法
		if(IncInfo) {
			Input((*p).info);
		}
	}
	return OK;
}

Status CreateUDG(ALGraph &G) {
	int i, j, k;
	VertexType v1, v2;
	ArcNode *p, *r, *s;

	printf("请输入图的顶点数、弧数：");
	scanf("%d %d", &G.vexnum, &G.arcnum);
	getchar();
	printf("输入%d个顶点：", G.vexnum);
	for (i = 0; i < G.vexnum; i++) {
		scanf("%c", &G.vertices[i].data);
		getchar();
		G.vertices[i].firstarc = NULL;
	}
	for (k = 0; k < G.arcnum; k++) {
		printf("输入第%d条弧：", k+1);
		scanf("%c %c", &v1, &v2);
		getchar();
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		p = (ArcNode *)malloc(sizeof(ArcNode));
		if (!p)
			return ERROR;

		p->adjvex = j;					//尾插
		p->nextarc = NULL;
		r = G.vertices[i].firstarc;
		if(G.vertices[i].firstarc == NULL) {
			G.vertices[i].firstarc = p;
		}else {
			while(r) { s = r; r = r->nextarc;} 
			s->nextarc = p;
		}								

		// p->nextarc = G.vertices[i].firstarc;//头插法
		// p->adjvex = j;
		// G.vertices[i].firstarc = p;
		p = (ArcNode *)malloc(sizeof(ArcNode));
		if (!p)
			return ERROR;

		p->adjvex = i;							//尾插
		p->nextarc = NULL;
		r = G.vertices[j].firstarc;
		if(G.vertices[j].firstarc == NULL) {
			G.vertices[j].firstarc = p;
		}else {
			while(r) { s = r; r = r->nextarc;} 
			s->nextarc = p;
		}

		// p->nextarc = G.vertices[j].firstarc;	//头插
		// p->adjvex = i;
		// G.vertices[j].firstarc = p;
	}
	return OK;
}

//创建邻接表存储的有向网，弧信息即为权值
Status CreateDN(ALGraph &G){
	int i, j, k;
	ArcNode *p;
	EdgeType value;
	VertexType v1, v2;
	printf("请输入有向网的顶点数及弧数：");
	scanf("%d %d", &G.vexnum, &G.arcnum);
	getchar();
	printf("输入%d个顶点：", G.vexnum);
	for (i = 0; i < G.vexnum; i++) {
		scanf("%c", &G.vertices[i].data);
		getchar();
		G.vertices[i].firstarc = NULL;
	}
	printf("输入%d条弧（有向）\n", G.arcnum);
	for (k = 0; k < G.arcnum; k++) {
		printf("输入第%d条弧及权值(空格分隔)：", k+1);
		scanf("%c %c %d", &v1, &v2, &value);
		getchar();
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		p = (ArcNode *)malloc(sizeof(ArcNode));
		if (!p)
			return ERROR;
		p->nextarc = G.vertices[i].firstarc;
		p->adjvex = j;
		p->weight = value;
		G.vertices[i].firstarc = p;
	}

	return OK;
}

//创建邻接表存储的有向图
Status CreateDG(ALGraph &G)
{
	int i, j, k;
	ArcNode *p;
	VertexType v1, v2;
	printf("请输入有向图的顶点数、弧数：");
	scanf("%d %d", &G.vexnum, &G.arcnum);
	getchar();
	printf("输入%d个顶点：", G.vexnum);
	for (i = 0; i < G.vexnum; i++) {
		scanf("%c", &G.vertices[i].data);
		getchar();
		G.vertices[i].firstarc = NULL;
	}
	printf("输入%d条弧（有向）\n", G.arcnum);
	for (k = 0; k < G.arcnum; k++) {
		printf("输入第%d条弧：", k+1);
		scanf("%c %c", &v1, &v2);
		getchar();
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		p = (ArcNode *)malloc(sizeof(ArcNode));
		if (!p)
			return ERROR;
		p->nextarc = G.vertices[i].firstarc;
		p->adjvex = j;
		G.vertices[i].firstarc = p;
		G.vertices[i].firstarc->weight = p->weight;
	}

	return OK;
}

void Display(MGraph G) {
	int i, j;
	for(i=0; i<G.vexnum; i++) {
		for(j=0; j<G.vexnum; j++) {
			printf("%d\t", G.Edge[i][j]);
		}
		printf("\n");
	}
}

void Display(ALGraph G) {
	int i, w;

	for(i=0; i<G.vexnum; i++) {
		printf("%c ", G.vertices[i].data);
		for(w = FirstNeighbor(G, i); w>=0; w=NextNeighbor(G, i, w)) {
			printf("%c ", G.vertices[w].data);
		}
		printf("\n");
	}
}

int FirstNeighbor(ALGraph G, int v) {
	if(NULL != G.vertices[v].firstarc) {
		return G.vertices[v].firstarc->adjvex;
	}else {
		return -1;
	}
}

int NextNeighbor(ALGraph G, int v, int w) {
	ArcNode *p;//弧指针
	p = G.vertices[v].firstarc;
	while(p) {
		if (p->adjvex == w) {
			p = p->nextarc;
			if(NULL != p) {
				return p->adjvex;
			}else {
				return -1;
			}
		}else {
			p = p->nextarc;
		}
	}
}

#endif