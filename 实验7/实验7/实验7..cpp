#include <stdio.h>
#include <stdlib.h>
#define MAXV 100	
#define MaxSize 1000
#define INF 32726		//InfoType����Ϊint����ʱ��ʾ����� 
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
void Dijkstra(MGraph g, int v);			//�ҿ�˹�����㷨���Դ�㵽�������������·��
void Dispath(MGraph g, int dist[], int path[], int s[], int v);//������·�� 


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
	int a[6] = { 'A','B','C','D','E','F' };
	int w[9] = { 5,30,2,8,15,7,4,10,18 };
	char v1[9] = { 'A','A','B','B','C','C','E','F','F' };
	char v2[9] = { 'C','D','A','E','B','F','D','D','E' };
	G.n = 6;
	G.e = 9;
	for (i = 0; i < G.n; i++) {
		G.vex[i].info = a[i];
		G.vex[i].no = i;
	}
	for (i = 0; i < G.n; i++)		//��ʼ���ڽӾ��� 
		for (j = 0; j < G.e; j++) {
			if (i == j)
				G.edges[i][j] = 0;
			else
				G.edges[i][j] = INF;
		}
	printf("\n");
	for (k = 0; k < G.e; k++) {		//����������Ķ����Լ��ߵ�Ȩֵ 
		i = LocateVex(G, v1[k]);
		j = LocateVex(G, v2[k]);
		G.edges[i][j] = w[k];
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
void Dijkstra(MGraph G, int v)
{
	int dist[MAXV], path[MAXV];
	int s[MAXV];
	int mindis, i, j, u;
	for (i = 0; i < G.n; i++)
	{
		dist[i] = G.edges[v][i];
		s[i] = 0;
		if (G.edges[v][i] < INF)
			path[i] = v;
		else
			path[i] = -1;
	}
	s[v] = 1; path[v] = 0;
	for (i = 0; i < G.n; i++)
	{
		mindis = INF;
		for (j = 0; j < G.n; j++)
			if (s[j] == 0 && dist[j] < mindis)
			{
				u = j;
				mindis = dist[j];
			}
		s[u] = 1;
		for (j = 0; j < G.n; j++)
			if (s[j] == 0)
				if (G.edges[u][j] < INF && dist[u] + G.edges[u][j] < dist[j])
				{
					dist[j] = dist[u] + G.edges[u][j];
					path[j] = u;
				}
	}
	Dispath(G, dist, path, s, v);
}

void Dispath(MGraph G, int dist[], int path[], int s[], int v)
{
	int i, j, k;
	int apath[MAXV], d;
	for (i = 0; i < G.n; i++)
		if (s[i] == 1 && i != v)
		{
			printf("��%c��%c����̳���Ϊ��%d\t·��Ϊ��", G.vex[v].info, G.vex[i].info, dist[i]);
			d = MAXV - 1;
			apath[d] = i;
			k = path[i];
			if (k == -1)
				printf("��·��\n");
			else
			{
				while (k != v)
				{
					d--;
					apath[d] = k;
					k = path[k];
				}
				printf("%c ", G.vex[v].info);
				for (j = d; j < MAXV; j++)
					printf("%c ", G.vex[apath[j]].info);
				printf("\n");
			}
		}
}

int main()
{
	MGraph G;
	CreatUDN(G);
	Dijkstra(G, 0);
}
