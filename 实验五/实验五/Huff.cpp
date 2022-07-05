#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 50
typedef char DataType;
typedef struct HuffNode
{
	DataType data;
	double weight;
	int parent;
	int lchild;
	int rchild;
}HuffNode;

typedef struct HuffCode          //����������Ĵ洢�ṹ
{
	DataType cd[MAXNUM];  //��ű���λ��
	int start;			  //�������ʼλ��
}HuffCode;

//�����������
void HaffmanCreat(HuffNode ht[], int n)
{
	int i, k, lnode, rnode;
	double min1, min2;
	for (i = 0; i < 2 * n - 1; i++)		//��������г�ʼ��
	{
		ht[i].parent = ht[i].lchild = ht[i].rchild = -1;
	}
	for (i = n; i < 2 * n - 1; i++)
	{
		min1 = min2 = 32767;
		lnode = rnode = -1;
		for (k = 0; k <= i - 1; k++)
		{
			if (ht[k].parent == -1)
			{
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
			}
		}
		ht[i].weight = ht[lnode].weight+ht[rnode].weight;
		ht[i].lchild = lnode;
		ht[i].rchild = rnode;
		ht[lnode].parent = i;
		ht[rnode].parent = i;
	}
	printf("�������������ɹ�");
}

//�������������
void EnCoding(HuffNode ht[], HuffCode hcd[], int n)
{
	int i, f, c;
	HuffCode hc;
	for (i = 0; i < n; i++)
	{
		hc.start = n;
		c = i;
		f = ht[i].parent;
		while (f != -1)
		{
			if (ht[f].lchild == c)
				hc.cd[hc.start--] = '0';
			else
				hc.cd[hc.start--] = '1';
			c = f;
			f = ht[f].parent;
		}
		hc.start++;
		hcd[i] = hc;
	}
}

//��������������ƽ�����ҳ���
void PrinfHuffCode(HuffNode ht[], HuffCode hcd[], int n)
{
	int i, k;
	int sum = 0, m = 0, j;
	printf("������������룺\n");
	for (i = 0; i < n; i++)
	{
		j = 0;
		printf("%c ", ht[i].data);
		for (k = hcd[i].start; k <= n; k++)
		{
			printf("%c ",hcd[i].cd[k]);
			j++;
		}
		printf("\n");
		m += ht[i].weight;
		sum += ht[i].weight*j;
	}
	printf("\nƽ�����ҳ���=%f", 1.0 * sum / m);
}

int main()
{
	int n= 8, i;
	char str[] = { 'A','B','C','D','E','F','G','H' };
	int fnum[] = { 9,5,3,7,6,2,1,1 };
	HuffNode ht[2 * MAXNUM];
	HuffCode hcd[MAXNUM];
	for (i = 0; i < n; i++)
	{
		ht[i].data = str[i];
		ht[i].weight = fnum[i];
	}
	HaffmanCreat(ht, n);
	EnCoding(ht, hcd, n);
	PrinfHuffCode(ht, hcd, n);
	return 0;
}