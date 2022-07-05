#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAXV 100
int visited[MAXV];
typedef int Vertex;
typedef int InfoType;
typedef struct ANode {
	int adjvex;			//该边的终点编号 
	struct ANode* nextarc;//指向下一条边的指针 
	InfoType info;			//该边的相关信息
}ArcNode;				//边表结点 
typedef struct {
	Vertex data;		//表头结点类型 
	ArcNode* firstarc;	//顶点信息 
}VNode;
typedef VNode Adjlist[MAXV];
typedef struct {
	Adjlist adjlist;		//邻接表 
	int n, e;			//顶点n和边数e 
}ALGraph;

int LocateVex(ALGraph G, Vertex u);		//在图中查找顶点 
int CreatALGraph(ALGraph& G);						//采用邻接矩阵表示法创建有向网 
void PrintALGraph(ALGraph G);						//输出邻接矩阵 
int InDegree(ALGraph G, int v);    				//求邻接矩阵某点v的入度
void DFS(ALGraph G, int v);						//邻接矩阵的深度优先遍历,v是初始顶点编号 
void BFS(ALGraph G, int v);						//邻接矩阵的广度优先遍历,v是初始顶点编号 


int LocateVex(ALGraph G, Vertex u)		//在图中查找顶点 
{
	int i;
	for (i = 0; i < G.n; i++)
	{
		if (u == G.adjlist[i].data)
			return i;
	}
	return -1;
}
int CreatUDG(ALGraph& G)						//采用邻接表法创建有向网G
{
	ArcNode* p;
	int i, j, k, v1, v2, w;
	printf("请输入总顶点数：");
	scanf("%d", &G.n);
	printf("请输入总边数：");
	scanf("%d", &G.e);
	printf("请依次输入点的信息：");
	for (i = 0; i < G.n; i++) {				//输入点的信息 
		scanf("%d", &G.adjlist[i].data);	//输入顶点的值 
		G.adjlist[i].firstarc = NULL;		//初始化表头结点的指针域 
	}
	for (k = 0; k < G.e; k++) {					//输入边，构造邻接表 
		printf("请输入边依附的顶点：");
		scanf("%d %d", &v1, &v2);
		printf("请输入该边的权重：");
		scanf("%d", &w);
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->info = w;
		p->adjvex = j;					//邻接点序号为j
		p->nextarc = G.adjlist[i].firstarc;//将新结点头插到边表
		G.adjlist[i].firstarc = p;
	}
	return 0;
}
void PrintALGraph(ALGraph G)		//输出邻接表 
{
	ArcNode* p;
	for (int i = 0; i < G.n; i++) {
		p = G.adjlist[i].firstarc;
		printf("%d", G.adjlist[i].data);
		while (p != NULL)
		{
			printf("-->");
			printf("%d", G.adjlist[p->adjvex].data);
			p = p->nextarc;
		}
		printf("\n");
	}
}
void DestroyALGraph(ALGraph G)		//销毁边表结点 
{
	ArcNode* p1, * p2;
	p1 = (ArcNode*)malloc(sizeof(ArcNode));
	p2 = (ArcNode*)malloc(sizeof(ArcNode));
	for (int i = 0; i < G.n; i++)
	{
		p1 = G.adjlist[i].firstarc;
		while (p1 != NULL)
		{
			p2 = p1->nextarc;
			free(p1);
			p1 = p2;
		}
		free(p2);
	}
}
int InDegree(ALGraph G, int v)	   				
{
	ArcNode* p;
	int degree = 0;
	for (int i = 0; i < G.n; i++)
	{
		p = G.adjlist[i].firstarc;
		while (p != NULL)
		{
			if (v == p->adjvex)
				degree++;
			p = p->nextarc;
		}
	}
	return degree;
}
void DFS(ALGraph G, int v)						 
{
	ArcNode* p;
	int i;
	visited[v] = 1;
	printf("%d   ", G.adjlist[v].data);
	p = G.adjlist[v].firstarc;
	while (p != NULL) 
	{
		i = p->adjvex;
		if (p != NULL)
		{
			if (visited[i] == 0)
				DFS(G, i);
			p = p->nextarc;
		}
	}
}
void BFS(ALGraph G, int v)						
{
	ArcNode* p;	
	int queue[MAXV], front = 0, rear = 0;
	int visited[MAXV];
	for (int i = 0; i < G.n; i++) 
		visited[i] = 0;	 
	visited[v] = 1;
	printf("%d   ", G.adjlist[v].data);
	rear = (rear + 1) % MAXV;
	queue[rear] = v;
	int j;
	while (rear != front)
	{
		front = (front + 1) % MAXV;
		j = queue[front];
		p = G.adjlist[j].firstarc;
		while (p != NULL)
		{
			if (visited[p->adjvex] == 0)
			{
				printf("%d   ", G.adjlist[p->adjvex].data);
				visited[p->adjvex] = 1;
				rear = (rear + 1) % MAXV;
				queue[rear] = p->adjvex;
			}
			p = p->nextarc;
		}
	}
}
int main()
{
	ALGraph G;
	int i, degree;
	CreatUDG(G);
	printf("邻接表为：\n");
	PrintALGraph(G);
	for (i = 0; i < G.n; i++)
	{
		degree = InDegree(G, i);
		printf("顶点%d的入度为：%d\n", G.adjlist[i].data, degree);
	}
	printf("邻接表的深度优先序列为：");
	DFS(G, 0);
	printf("\n");
	printf("邻接表的广度优先序列为：");
	BFS(G, 0);
	DestroyALGraph(G);
}
