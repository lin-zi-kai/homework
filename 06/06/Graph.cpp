#include <stdio.h>
#include <stdlib.h>
#define MAXV 100          //最大顶点个数
#define INF 32767        //INF表示无穷

typedef int InfoType;	////定义边的权值为int型

//邻接矩阵的定义
typedef struct VertexType
{
	int no;               //顶点编号
	InfoType info;        //顶点的其他信息，比如权值
}VertexType;

typedef struct Graph
{
	int edges[MAXV][MAXV];	//邻接矩阵
	int n, e;				//顶点数，边数
	VertexType vexs[MAXV];	//存放顶点的信息
}Graph;

//邻接表的定义
typedef struct ANode    //边的结点的数据结构
{
	int adjvex;			//该边的终点的位置
	struct ANode* nextarc;	//指向下一条边的指针
	InfoType info;			 //该边的相关信息，比如权值
} ANode;

typedef struct VNode
{
	InfoType data;	//顶点信息
	int count;		//存放顶点的入度，在拓扑排序中用
	ANode* firstarc;//指向第一条边
}VNode;

typedef VNode AList[MAXV];//AdjList表示邻接表的类型

typedef struct
{
	AList alist;	//邻接表
	int n, e;		//图的顶点数n和边是e
}AGraph;

//初始化邻接表
void ArrayToList(int* Arr, int n, AGraph*& G)
{
	int i, j, count = 0;	//count用于统计边数，即矩阵中非0元素的个数
	ANode* p;
	G = (AGraph*)malloc(sizeof(AGraph));
	G->n = n;
	for (i = 0; i < n; i++)				////给邻接表中所有头节点的指针域置初值
		G->alist[i].firstarc = NULL;
	for (i = 0; i < n; i++)
		for (j = n - 1; j >= 0; j--)
			if (Arr[i * n + j] != 0)		//存在一条边，将Arr看作n×n的二维数组，Arr[i*n+j]=Arr[i][j]（n是有多少列）
			{
				p = (ANode*)malloc(sizeof(ANode));	//创建一个节点*p
				p->adjvex = j;
				p->info = Arr[i * n + j];
				p->nextarc = G->alist[i].firstarc;		//创建一个节点*p
				G->alist[i].firstarc = p;
				count++;
			}
	G->e = count;
}

//返回图G中编号为v的顶点的出度
int OutDegree(AGraph* G, int v)
{
	int n = 0;
	ANode* p;
	p = G->alist[v].firstarc;
	while (p != NULL)
	{
		n++;
		p = p->nextarc;
	}
	return n;
}

void Degree(AGraph* G)
{
	int i;
	for (i = 0; i < G->n; i++)
		printf("顶点%d的出度为:%d\n", i, OutDegree(G, i));
}

//输出图G中出度最大的一个顶点
void MaxDegree(AGraph* G)
{
	int maxv = 0, maxds = 0, i, x;
	for (i = 0; i < G->n; i++)
	{
		x = OutDegree(G, i);
		if (x > maxds)
		{
			maxds = x;
			maxv = i;
		}
	}
	printf("顶点%d出度最大,出度为%d\n", maxv, maxds);
}

//输出图G中出度为0的顶点数
void ZeroDs(AGraph* G)
{
	int i, x;
	int n = 0;
	for (i = 0; i < G->n; i++)
	{
		x = OutDegree(G, i);
		if (x == 0)
			n++;
	}
	printf("%d",n);
}

//返回图G中是否存在边<i,j>
bool Arc(AGraph* G, int i, int j)
{
	ANode* p;
	bool jud = false;
	p = G->alist[i].firstarc;
	while (p != NULL)
	{
		if (p->adjvex == j)
		{
			jud = true;
			break;
		}
		p = p->nextarc;
	}
	return jud;
}

void TopoSort(AGraph* G, int n)
{
	int i, j, k, top, m = 0;
	ANode* p;
	int* d = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)		
	{
		d[i] = 0;
	}
	for (i = 0; i < n; i++)		
	{
		p = G->alist[i].firstarc;
		while (p != NULL)
		{
			j = p->adjvex;
			d[j]++;
			p = p->nextarc;
		}
	}
	top = -1;
	for (i = 0; i < n; i++)		
	{
		if (d[i] == 0)
		{
			printf("%d  ", top);
			d[i] = top;
			top = i;
			printf("%d  ", top);

		}
	}
	while (top != -1)
	{
		j = top;
		top = d[top];
		printf("%d ", j);
		m++;		
		p = G->alist[j].firstarc;
		while (p)
		{
			k = p->adjvex;		
			d[k]--;		
			if (d[k] == 0)		
			{
				printf("%d  ", top);
				d[k] = top;
				top = k;
			}
			p = p->nextarc;
		}
	}
	if (m < n)
		printf("存在回路\n");
	free(d);
}


int main()
{
	AGraph* G;
	int A[5][5] =
	{
		{0,10,1,1,20},
		{10,0,30,40,0},
		{0,30,0,50,0},
		{0,40,50,0,0},
		{20,0,0,0,0},
	};
	ArrayToList(A[0], 5, G);
	Degree(G);
	MaxDegree(G);
	printf("出度为0的顶点数:"); 
	ZeroDs(G);
	printf("\n");
	TopoSort(G, 5);
	return 0;
}

