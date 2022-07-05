#include <stdio.h>
#define MAXL 100

typedef int KeyType;
typedef char InfoType[10];

typedef struct {
	KeyType key;
	InfoType data;
}NodeType;

typedef NodeType SeqList[MAXL];

int SeqSearch(SeqList R, int n, KeyType k)
{
	int i = 0;
	while (i < n && R[i].key != k)
	{
		printf("%d ", R[i].key);
		i++;
	}
	if (i >= n)
		return (-1);
	else
	{
		printf("%d", R[i].key);
		return(i);	}
}

int main()
{
	SeqList R;
	int n = 10, i;
	KeyType k = 5;
	int a[] = { 3,6,2,10,1,8,5,7,4,9 };
	for (i = 0; i < n; i++)
		R[i].key = a[i];
	printf("关键字序列：");
	for (i = 0; i < n; i++)
		printf("%d ", R[i].key);
	printf("\n");
	printf("查找%d所比较的关键字：\n", k);
	if ((i = SeqSearch(R, n, k)) != -1)
		printf("\n元素%d位置是%d", k, i);
	else
		printf("\n元素%d不在表中", k);
	printf("\n");
	return 0;
}
