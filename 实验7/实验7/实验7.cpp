#include <stdio.h>
#include <stdlib.h>
#define MAXV 100	
#define MaxSize 1000
#define MaxValue 32726		//InfoType定义为int类型时表示无穷大 
typedef char InfoType;
typedef struct
{
	int no;			//顶点的编号 
	InfoType info;	//顶点信息 
}VertexType;		//边的类型 
typedef struct {			//图的定义 
	int edges[MAXV][MAXV];	//邻接矩阵 
	int n, e;				//顶点数、弧数
	VertexType vex[MAXV];	//存放顶点信息 
}MGraph;					//图的邻接矩阵表示类型 
typedef struct {
	int u;		//边的起始顶点 
	int v;		//边的终止结点 
	int w;
}Edge;

int CreatUDN(MGraph& G);				//采用邻接矩阵表示法创建有向网 
int LocateVex(MGraph G, InfoType u);		//在图中查找顶点 
void PrintEdge(MGraph G);				//输出邻接矩阵 
void Prim(MGraph g, int v);				//普利姆算法构造最小生成树
void InsertSort(Edge E[], int n);		//对边集按递增排序进行直接插入排序 
void Kruskal(MGraph g);					//克鲁斯卡尔算法构造最小生成树 

int LocateVex(MGraph G, InfoType u)		//在图中查找顶点 
{
	int i;
	for (i = 0; i < G.n; i++)
	{
		if (u == G.vex[i].info)
			return i;
	}
	return -1;
}
int CreatUDN(MGraph& G)	//采用邻接矩阵表示法创建无向网 
{
	int i, j, k;
	int a[7] = { 'A','B','C','D','E','F','G' };
	int w[10] = { 60,50,65,40,50,70,30,42,52,45 };
	char v1[10] = { 'A','A','B','B','E','E','F','D','D','G' };
	char v2[10] = { 'C','B','D','E','D','F','D','G','C','C' };
	G.n = 7;
	G.e = 10;
	for (i = 0; i < G.n; i++) {
		G.vex[i].info = a[i];
		G.vex[i].no = i;
	}
	for (i = 0; i < G.n; i++)		//初始化邻接矩阵 
		for (j = 0; j < G.e; j++) {
			if (i == j)
				G.edges[i][j] = 0;
			else
				G.edges[i][j] = MaxValue;
		}
	printf("\n");
	for (k = 0; k < G.e; k++) {		//输入边依附的顶点以及边的权值 
		i = LocateVex(G, v1[k]);
		j = LocateVex(G, v2[k]);
		G.edges[i][j] = w[k];
		G.edges[j][i] = w[k];
	}
	return 0;
}
void PrintEdge(MGraph G)
{
	for (int i = 0; i < G.n; i++) {
		for (int j = 0; j < G.n; j++) {
			printf("%d\t", G.edges[i][j]);
		}
		printf("\n");
	}
}
void Prim(MGraph G, int v)
{
	int min, i, j;
	int lowcost[MAXV];
	int nearvex[MAXV];
	for (i = 0; i < G.n; i++)
	{
		lowcost[i] = G.edges[v][i];
		nearvex[i] = v;
	}
	int k = 0;
	for (i = 1; i < G.n; i++)
	{
		min = MaxValue;
		for (j = 0; j < G.n; j++)
		{
			if (lowcost[j] > 0 && lowcost[j] < min)
			{
				min = lowcost[j];
				k = j;
			}
		}
		printf("边<%c,%c>权为：%d\n", G.vex[nearvex[k]].info, G.vex[k].info, min);
		lowcost[k] = 0;
		for (j = 0; j < G.n; j++)
			if (G.edges[k][j] != 0 && G.edges[k][j] < lowcost[j])
			{
				lowcost[j] = G.edges[k][j];
				nearvex[j] = k;
			}
	}
}
void InsertSort(Edge E[MaxSize], int n)		//对边集按递增排序进行直接插入排序,n是边数 
{
	int i, j;
	Edge temp;
	for (i = 1; i < 2 * n; i++)
	{
		temp = E[i];
		j = i - 1;
		while (j >= 0 && temp.w < E[j].w)
		{
			E[j + 1] = E[j];
			j--;
		}
		E[j + 1] = temp;
	}
}
void Kruskal(MGraph G)
{
	int i, j, u, v, sn1, sn2, k;
	int vset[MAXV];
	Edge E[MaxSize];
	k = 0;
	for (i = 0; i < G.n; i++)
		for (j = 0; j < G.n; j++)
			if (G.edges[i][j] != 0 && G.edges[i][j] != MaxValue)
			{
				E[k].u = i;
				E[k].v = j;
				E[k].w = G.edges[i][j];
				k++;
			}
	InsertSort(E, G.e);
	for (i = 0; i < G.n; i++)
		vset[i] = i;
	k = 1;		
	j = 0;		
	while (k < G.n)
	{
		u = E[j].u;		
		v = E[j].v;
		sn1 = vset[u];	
		sn2 = vset[v];
		if (sn1 != sn2)	
		{
			printf("边<%c,%c>权为：%d\n", G.vex[u].info, G.vex[v].info, E[j].w);
			k++;				 
			for (i = 0; i < G.n; i++)	
				if (vset[i] == sn2)
					vset[i] = sn1;
		}
		j++;
	}
}
int main()
{
	MGraph G;
	CreatUDN(G);
	printf("(普利姆算法)最小生成树构成：\n");
	Prim(G, 0);
	printf("(克鲁斯卡尔算法)最小生成树构成：\n");
	Kruskal(G);
}
