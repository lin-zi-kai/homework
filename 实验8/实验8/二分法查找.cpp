#include <stdio.h>
#define MAXL 100

typedef int KeyType;
typedef char InfoType[10];

typedef struct
{
	KeyType key;
	InfoType data;
}NodeType;

typedef NodeType SeqList[MAXL];

int BinSearch(SeqList R, int n, KeyType k)
{
	int low = 0, high = n - 1, mid, count = 0;
	while (low <= high)
	{
		mid = (low + high) / 2;
		printf("  ��%d�αȽ�:��[%d ,%d]�бȽ�Ԫ��R[%d]:%d\n", ++count, low, high, mid, R[mid].key);
		if (R[mid].key == k)
			return(mid);
		if (R[mid].key > k)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}

int main()
{
	SeqList R;
	KeyType k = 9;
	int a[] = { 1,2,3,4,5,6,7,8,9,10 }, i, n = 10;
	for (i = 0; i < n; i++)
		R[i].key = a[i];
	printf("�ؼ�������:");
	for (i = 0; i < n; i++)
		printf("%d ", R[i].key);
	printf("\n");
	printf("����%d�ıȽϹ������£�\n", k);
	if ((i = BinSearch(R, n, k)) != -1)
		printf("Ԫ��%d��λ����%d\n", k, i);
	else
		("Ԫ��%d���ڱ���\n", k);
}
