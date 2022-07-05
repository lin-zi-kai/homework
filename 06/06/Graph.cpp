#include <stdio.h>
#include <stdlib.h>
#define MAXV 100          //��󶥵����
#define INF 32767        //INF��ʾ����

typedef int InfoType;	////����ߵ�ȨֵΪint��

//�ڽӾ���Ķ���
typedef struct VertexType
{
	int no;               //������
	InfoType info;        //�����������Ϣ������Ȩֵ
}VertexType;

typedef struct Graph
{
	int edges[MAXV][MAXV];	//�ڽӾ���
	int n, e;				//������������
	VertexType vexs[MAXV];	//��Ŷ������Ϣ
}Graph;

//�ڽӱ�Ķ���
typedef struct ANode    //�ߵĽ������ݽṹ
{
	int adjvex;			//�ñߵ��յ��λ��
	struct ANode* nextarc;	//ָ����һ���ߵ�ָ��
	InfoType info;			 //�ñߵ������Ϣ������Ȩֵ
} ANode;

typedef struct VNode
{
	InfoType data;	//������Ϣ
	int count;		//��Ŷ������ȣ���������������
	ANode* firstarc;//ָ���һ����
}VNode;

typedef VNode AList[MAXV];//AdjList��ʾ�ڽӱ������

typedef struct
{
	AList alist;	//�ڽӱ�
	int n, e;		//ͼ�Ķ�����n�ͱ���e
}AGraph;

//��ʼ���ڽӱ�
void ArrayToList(int* Arr, int n, AGraph*& G)
{
	int i, j, count = 0;	//count����ͳ�Ʊ������������з�0Ԫ�صĸ���
	ANode* p;
	G = (AGraph*)malloc(sizeof(AGraph));
	G->n = n;
	for (i = 0; i < n; i++)				////���ڽӱ�������ͷ�ڵ��ָ�����ó�ֵ
		G->alist[i].firstarc = NULL;
	for (i = 0; i < n; i++)
		for (j = n - 1; j >= 0; j--)
			if (Arr[i * n + j] != 0)		//����һ���ߣ���Arr����n��n�Ķ�ά���飬Arr[i*n+j]=Arr[i][j]��n���ж����У�
			{
				p = (ANode*)malloc(sizeof(ANode));	//����һ���ڵ�*p
				p->adjvex = j;
				p->info = Arr[i * n + j];
				p->nextarc = G->alist[i].firstarc;		//����һ���ڵ�*p
				G->alist[i].firstarc = p;
				count++;
			}
	G->e = count;
}

//����ͼG�б��Ϊv�Ķ���ĳ���
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
		printf("����%d�ĳ���Ϊ:%d\n", i, OutDegree(G, i));
}

//���ͼG�г�������һ������
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
	printf("����%d�������,����Ϊ%d\n", maxv, maxds);
}

//���ͼG�г���Ϊ0�Ķ�����
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

//����ͼG���Ƿ���ڱ�<i,j>
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
		printf("���ڻ�·\n");
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
	printf("����Ϊ0�Ķ�����:"); 
	ZeroDs(G);
	printf("\n");
	TopoSort(G, 5);
	return 0;
}

