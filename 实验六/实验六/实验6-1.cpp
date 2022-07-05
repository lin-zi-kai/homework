#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAXV 100	
#define INF 32767		//InfoType����Ϊint����ʱ��ʾ����� 
int visitedM1[MAXV] = { 0 };
typedef int InfoType;
typedef struct
{
	int no;			//����ı�� 
	InfoType info;	//����������Ϣ 
}VertexType;		//�ߵ����� 
typedef struct {			//ͼ�Ķ��� 
	int edgs[MAXV][MAXV];	//�ڽӾ�����Ȩֵ 
	int n, e;				//������������
	VertexType vex[MAXV];	//��Ŷ�����Ϣ 
}MGraph;					//ͼ���ڽӾ����ʾ���� 

int LocateVex(MGraph g, InfoType u);		//��ͼ�в��Ҷ��� 
int CreatUDN(MGraph& g);						//�����ڽӾ����ʾ������������ 
void PrintEdge(MGraph g);						//����ڽӾ��� 
int InDegreeM(MGraph g, int v);    				//���ڽӾ���ĳ��v�����
void DFSM(MGraph g, int v);						//�ڽӾ����������ȱ���,v�ǳ�ʼ������ 
void BFSM(MGraph g, int v);						//�ڽӾ���Ĺ�����ȱ���,v�ǳ�ʼ������ 

int LocateVex(MGraph g, InfoType u)		//��ͼ�в��Ҷ��� 
{
	int i;
	for (i = 0; i < g.n; i++)
	{
		if (u == g.vex[i].info)
			return i;
	}
	return -1;
}
int CreatUDN(MGraph& g)	//�����ڽӾ����ʾ������������ 
{
	int i, j, k, v1, v2, w;
	printf("�������ܶ�������");
	scanf("%d", &g.n);
	printf("�������ܻ�����");
	scanf("%d", &g.e);
	printf("��������������Ϣ��");
	for (i = 0; i < g.n; i++)
	{	//��������Ϣ 
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
		printf("������������Ķ��㣺");
		scanf("%d %d", &v1, &v2);
		printf("������ߵ�Ȩֵ��");
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
	printf("�ڽӾ���Ϊ��\n");
	PrintEdge(g);
	for (int i = 0; i < g.n; i++) {
		degree = InDegreeM(g, i);
		printf("����%d�����Ϊ��%d\n", g.vex[i].info, degree);
	}
	printf("�ڽӾ����������ȱ������Ϊ��");
	DFSM(g, 0);
	printf("\n");
	printf("�ڽӾ���Ĺ�����ȱ������Ϊ��");
	BFSM(g, 0);
	return 0;

}
