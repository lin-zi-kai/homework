#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef char ElemType;

typedef struct
{
	ElemType data;
	int weight;
	int parent;
	int lchild;
	int rchild;
}HuffNode;

typedef struct
{
	ElemType cd[MAXSIZE];
	int start;
}HuffCode;


void HuffmanCreat(HuffNode* ht, int n)
{
	int i, k, min1, min2, lnode, rnode;
	for (i = 1; i <= n; i++)
	{
		getchar();
		printf("第%d个元素的结点值：", i);
		scanf("%c", &ht[i].data);
		printf("权重：");
		scanf("%d", &ht[i].weight);
	}
	for (i = 1; i <= 2 * n - 1; i++)
	{
		ht[i].parent = 0;
		ht[i].lchild = 0;
		ht[i].rchild = 0;
	}
	for (i = n + 1; i <= 2 * n - 1; i++)
	{
		min1 = min2 = 32767;
		lnode = 1;
		rnode = 1;
		for (k = 1; k <= i - 1; k++)	
			if (ht[k].parent == 0)
				if (ht[k].weight < min1)
				{
					min2 = min1;
					rnode = lnode;
					min1 = ht[k].weight;
					lnode = k;
				}
				else if (ht[k].weight < min2)
				{
					min2 = ht[k].weight;
					rnode = k;
				}
		ht[i].weight = min1 + min2;
		ht[i].lchild = lnode;
		ht[i].rchild = rnode;
		ht[lnode].parent = i;
		ht[rnode].parent = i;
	}
}

void PrintBTNode(HuffNode* hf, int index, int n, int level)		 
{
	int i = n;
	if (hf[i].weight != NULL)
	{
		if (hf[i].rchild != NULL)
		{
			n = hf[i].rchild;
			PrintBTNode(hf, index, n, level + 1);
		}
		if (level != 0)
		{
			for (int k = 0; k < 4 * (level - 1); k++)
			{
				printf(" ");
			}
			printf("---");
		}
		if (i <= n)
			printf("%c", hf[i].data);
		else
			printf("○");
		printf("\n");
		if (hf[i].lchild != NULL)
		{
			n = hf[i].lchild;
			PrintBTNode(hf, index, n, level + 1);
		}
	}
}

void Encoding(HuffNode ht[], HuffCode hcd[], int n)		
{
	HuffCode d;
	int i, k, f, c;
	for (i = 1; i <= n; i++)
	{
		d.start = n + 1;		 
		c = i;				 
		f = ht[i].parent;
		while (f != 0)
		{
			if (ht[f].lchild == c)
				d.cd[--d.start] = '0';	
			else
				d.cd[--d.start] = '1';	
			c = f;						 
			f = ht[f].parent;					
		}
		hcd[i] = d;
	}
	printf("输出哈夫曼编码：\n");
	for (i = 1; i <= n; i++)
	{
		printf("%c：", ht[i].data);
		for (k = hcd[i].start; k <= n; k++)
			printf("%c", hcd[i].cd[k]);
		printf("\n");
	}
}
int main()
{
	int n;
	HuffNode ht[MAXSIZE];
	HuffCode hcd[MAXSIZE];
	printf("请输入元素个数：");
	scanf("%d", &n);
	HuffmanCreat(ht, n);
	PrintBTNode(ht, n, 2 * n - 1, 0);;
	Encoding(ht, hcd, n);
	return 0;
}
