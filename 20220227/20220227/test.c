#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#define n 10
//
//void search(int a[],int key)
//{
//	int count = 0;
//	for (int i = 0;i < n;i++)
//	{
//		if (a[i] == key)
//		{
//			printf("a[%d]\n", i);
//			count++;
//		}
//	}
//	if (count == 0)
//		printf("0\n");
//}
//
//void maxmin(int a[])
//{
//	int max = 0;
//	int min = 0;
//	for (int i = 0; i < n; i++)
//	{
//		if (a[max] < a[i])
//			max = i;
//		if (a[min] > a[i])
//			min = i;
//	}
//	printf("���ֵΪ%d,��СֵΪ%d", a[max], a[min]);
//}
//
//int main()
//{
//	int a[n] = { 0 };
//	printf("���������Ԫ�أ�");
//	for (int i = 0; i < n; i++)
//		scanf("%d", &a[i]);
//	int key = 0;
//	printf("keyΪ��");
//	scanf("%d", &key);
//	search(a, key);
//	maxmin(a);
//	return 0;
//}

#include <stdio.h>
#include <time.h>
int int_cmp(const void* p1, const void* p2)
{
	return (*(int*)p2 - *(int*)p1);
}

int main()
{
	int arr[1000] = {0};
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 1000; i++)
	{
		arr[i] = rand();
	}
	qsort(arr, 1000, sizeof(int), int_cmp);
	printf("%d", arr[4]);
	return 0;
}