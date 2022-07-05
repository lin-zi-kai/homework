#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAXV 100
int visited[MAXV];
typedef int Vertex;
typedef int InfoType;
typedef struct ANode {
	int adjvex;			//�ñߵ��յ��� 
	struct ANode* nextarc;//ָ����һ���ߵ�ָ�� 
	InfoType info;			//�ñߵ������Ϣ
}ArcNode;				//�߱��� 
typedef struct {
	Vertex data;		//��ͷ������� 
	ArcNode* firstarc;	//������Ϣ 
}VNode;
typedef VNode Adjlist[MAXV];
typedef struct {
	Adjlist adjlist;		//�ڽӱ� 
	int n, e;			//����n�ͱ���e 
}ALGraph;

int LocateVex(ALGraph G, Vertex u);		//��ͼ�в��Ҷ��� 
int CreatALGraph(ALGraph& G);						//�����ڽӾ����ʾ������������ 
void PrintALGraph(ALGraph G);						//����ڽӾ��� 
int InDegree(ALGraph G, int v);    				//���ڽӾ���ĳ��v�����
void DFS(ALGraph G, int v);						//�ڽӾ����������ȱ���,v�ǳ�ʼ������ 
void BFS(ALGraph G, int v);						//�ڽӾ���Ĺ�����ȱ���,v�ǳ�ʼ������ 


int LocateVex(ALGraph G, Vertex u)		//��ͼ�в��Ҷ��� 
{
	int i;
	for (i = 0; i < G.n; i++)
	{
		if (u == G.adjlist[i].data)
			return i;
	}
	return -1;
}
int CreatUDG(ALGraph& G)						//�����ڽӱ�����������G
{
	ArcNode* p;
	int i, j, k, v1, v2, w;
	printf("�������ܶ�������");
	scanf("%d", &G.n);
	printf("�������ܱ�����");
	scanf("%d", &G.e);
	printf("��������������Ϣ��");
	for (i = 0; i < G.n; i++) {				//��������Ϣ 
		scanf("%d", &G.adjlist[i].data);	//���붥���ֵ 
		G.adjlist[i].firstarc = NULL;		//��ʼ����ͷ����ָ���� 
	}
	for (k = 0; k < G.e; k++) {					//����ߣ������ڽӱ� 
		printf("������������Ķ��㣺");
		scanf("%d %d", &v1, &v2);
		printf("������ñߵ�Ȩ�أ�");
		scanf("%d", &w);
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->info = w;
		p->adjvex = j;					//�ڽӵ����Ϊj
		p->nextarc = G.adjlist[i].firstarc;//���½��ͷ�嵽�߱�
		G.adjlist[i].firstarc = p;
	}
	return 0;
}
void PrintALGraph(ALGraph G)		//����ڽӱ� 
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
void DestroyALGraph(ALGraph G)		//���ٱ߱��� 
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
	printf("�ڽӱ�Ϊ��\n");
	PrintALGraph(G);
	for (i = 0; i < G.n; i++)
	{
		degree = InDegree(G, i);
		printf("����%d�����Ϊ��%d\n", G.adjlist[i].data, degree);
	}
	printf("�ڽӱ�������������Ϊ��");
	DFS(G, 0);
	printf("\n");
	printf("�ڽӱ�Ĺ����������Ϊ��");
	BFS(G, 0);
	DestroyALGraph(G);
}
