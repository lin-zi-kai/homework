#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAXV 100	
#define INF 32767		//InfoType定义为int类型时表示无穷大 
int visitedM1[MAXV] = { 0 };
typedef int InfoType;
typedef struct
{
	int no;			//顶点的编号 
	InfoType info;	//顶点其他信息 
}VertexType;		//边的类型 
typedef struct {			//图的定义 
	int edgs[MAXV][MAXV];	//邻接矩阵存放权值 
	int n, e;				//顶点数、弧数
	VertexType vex[MAXV];	//存放顶点信息 
}MGraph;					//图的邻接矩阵表示类型 

int LocateVex(MGraph g, InfoType u);		//在图中查找顶点 
int CreatUDN(MGraph& g);						//采用邻接矩阵表示法创建有向网 
void PrintEdge(MGraph g);						//输出邻接矩阵 
int InDegreeM(MGraph g, int v);    				//求邻接矩阵某点v的入度
void DFSM(MGraph g, int v);						//邻接矩阵的深度优先遍历,v是初始顶点编号 
void BFSM(MGraph g, int v);						//邻接矩阵的广度优先遍历,v是初始顶点编号 

int LocateVex(MGraph g, InfoType u)		//在图中查找顶点 
{
	int i;
	for (i = 0; i < g.n; i++)
	{
		if (u == g.vex[i].info)
			return i;
	}
	return -1;
}
int CreatUDN(MGraph& g)	//采用邻接矩阵表示法创建有向网 
{
	int i, j, k, v1, v2, w;
	printf("请输入总顶点数：");
	scanf("%d", &g.n);
	printf("请输入总弧数：");
	scanf("%d", &g.e);
	printf("请依次输入点的信息：");
	for (i = 0; i < g.n; i++)
	{	//输入点的信息 
		scanf("%d", &g.vex[i].info);
		g.vex[i].no = i;
	}
	for (i = 0; i < g.n; i++)
		for (j = 0; j < g.e; j++)
		{
			if (i == j)
				g.edgs[i][j] = 0;
			else
				g.edgs[i][j] = INF;
		}
	for (k = 0; k < g.e; k++)
	{
		printf("请输入边依附的顶点：");
		scanf("%d %d", &v1, &v2);
		printf("请输入边的权值：");
		scanf("%d", &w);
		i = LocateVex(g, v1);
		j = LocateVex(g, v2);
		g.edgs[i][j] = w;
	}
	return 0;
}
void PrintEdge(MGraph g)
{
	for (int i = 0; i < g.n; i++) {
		for (int j = 0; j < g.n; j++) {
			printf("%d\t", g.edgs[i][j]);
		}
		printf("\n");
	}
}
int InDegreeM(MGraph g, int v)    	
{
	int degree = 0;	
	for (int i = 0; i < g.n; i++)
	{
		if (g.edgs[i][v] > 0 && g.edgs[i][v] < INF)
		{
			degree++;
		}
	}
	return degree;
}

void DFSM(MGraph g, int v)			
{
	visitedM1[v] = 1;
	printf("%d   ", g.vex[v].info);
	for (int i = 0; i < g.n; i++) 
	{
		if ((g.edgs[v][i] > 0) && (g.edgs[v][i] < INF))
		{
			if (visitedM1[i] == 0)
				DFSM(g, i);
		}
	}
}
void BFSM(MGraph g, int v)			
{
	int visitedM2[MAXV];
	int  i, j;
	int queue[MAXV];
	int front = 0, rear = 0;
	for (i = 0; i < g.n; i++)				
		visitedM2[i] = 0;
	visitedM2[v] = 1;					
	printf("%d   ", g.vex[v].info);
	queue[rear] = v;
	rear = (rear + 1) % MAXV;
	while (rear != front)
	{
		j = queue[front];				
		front = (front + 1) % MAXV;
		for (i = 0; i < g.n; i++)
			if (g.edgs[j][i] > 0 && g.edgs[j][i] < INF)
			{
				if (visitedM2[i] == 0)
				{
					visitedM2[i] = 1; 
					printf("%d   ", g.vex[i].info);
					queue[rear] = i; 
					rear = (rear + 1) % MAXV;
				}
			}
	}
}
int main()
{
	int degree;
	MGraph g;
	CreatUDN(g);
	printf("邻接矩阵为：\n");
	PrintEdge(g);
	for (int i = 0; i < g.n; i++) {
		degree = InDegreeM(g, i);
		printf("顶点%d的入度为：%d\n", g.vex[i].info, degree);
	}
	printf("邻接矩阵的深度优先遍历输出为：");
	DFSM(g, 0);
	printf("\n");
	printf("邻接矩阵的广度优先遍历输出为：");
	BFSM(g, 0);
	return 0;

}
