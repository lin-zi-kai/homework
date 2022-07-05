#include <stdio.h>
#include <stdlib.h>
#define MAXV 100	
#define MaxSize 1000
#define MaxValue 32726		//InfoType����Ϊint����ʱ��ʾ����� 
typedef char InfoType;
typedef struct
{
	int no;			//����ı�� 
	InfoType info;	//������Ϣ 
}VertexType;		//�ߵ����� 
typedef struct {			//ͼ�Ķ��� 
	int edges[MAXV][MAXV];	//�ڽӾ��� 
	int n, e;				//������������
	VertexType vex[MAXV];	//��Ŷ�����Ϣ 
}MGraph;					//ͼ���ڽӾ����ʾ���� 
typedef struct {
	int u;		//�ߵ���ʼ���� 
	int v;		//�ߵ���ֹ��� 
	int w;
}Edge;

int CreatUDN(MGraph& G);				//�����ڽӾ����ʾ������������ 
int LocateVex(MGraph G, InfoType u);		//��ͼ�в��Ҷ��� 
void PrintEdge(MGraph G);				//����ڽӾ��� 
void Prim(MGraph g, int v);				//����ķ�㷨������С������
void InsertSort(Edge E[], int n);		//�Ա߼��������������ֱ�Ӳ������� 
void Kruskal(MGraph g);					//��³˹�����㷨������С������ 

int LocateVex(MGraph G, InfoType u)		//��ͼ�в��Ҷ��� 
{
	int i;
	for (i = 0; i < G.n; i++)
	{
		if (u == G.vex[i].info)
			return i;
	}
	return -1;
}
int CreatUDN(MGraph& G)	//�����ڽӾ����ʾ������������ 
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
	for (i = 0; i < G.n; i++)		//��ʼ���ڽӾ��� 
		for (j = 0; j < G.e; j++) {
			if (i == j)
				G.edges[i][j] = 0;
			else
				G.edges[i][j] = MaxValue;
		}
	printf("\n");
	for (k = 0; k < G.e; k++) {		//����������Ķ����Լ��ߵ�Ȩֵ 
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
		printf("��<%c,%c>ȨΪ��%d\n", G.vex[nearvex[k]].info, G.vex[k].info, min);
		lowcost[k] = 0;
		for (j = 0; j < G.n; j++)
			if (G.edges[k][j] != 0 && G.edges[k][j] < lowcost[j])
			{
				lowcost[j] = G.edges[k][j];
				nearvex[j] = k;
			}
	}
}
void InsertSort(Edge E[MaxSize], int n)		//�Ա߼��������������ֱ�Ӳ�������,n�Ǳ��� 
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
			printf("��<%c,%c>ȨΪ��%d\n", G.vex[u].info, G.vex[v].info, E[j].w);
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
	printf("(����ķ�㷨)��С���������ɣ�\n");
	Prim(G, 0);
	printf("(��³˹�����㷨)��С���������ɣ�\n");
	Kruskal(G);
}
