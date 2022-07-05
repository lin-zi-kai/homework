#include <stdio.h>

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void Swap(int* pa, int* pb)
{
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
} 

void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				--end;
			}
			else
				break;
		}
		a[end + 1] = tmp;
	}
}

void SelectSort(int* a, int n)
{
	int left = 0, right = n - 1;
	while (left < right)
	{
		int mini = left, maxi = left;
		for (int i = left + 1; i <= right; ++i)
		{
			if (a[i] < a[mini])
				mini = i;
			if (a[i] > a[maxi])
				maxi = i;
		}
		Swap(&a[left], &a[mini]);
		if (left == maxi)
			maxi = mini;
		Swap(&a[right], &a[maxi]);
		left++;
		right--;
	}
}


int PartSort(int* a, int left, int right)
{
	int keyi = left;
	int prev = left, cur = left + 1;
	while (cur <= right)
	{
		if (a[cur] < a[keyi] && a[++prev] != a[cur])
			Swap(&a[prev], &a[cur]);
		++cur;
	}
	Swap(&a[prev], &a[keyi]);
	return prev;
}
void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
		return;
	int keyi = PartSort(a, begin, end);
	QuickSort(a, begin, keyi - 1);
	QuickSort(a, keyi + 1, end);
}

void AdjustDown(int* a, size_t size, size_t root)
{
	size_t parent = root;
	size_t child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && a[child + 1] > a[child])
			++child;
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
void HeapSort(int* a, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
		AdjustDown(a, n, i);
	size_t end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}

int main()
{
	int n = 14;
	int i;
	int a[] = { 39,80,76,41,13,29,50,78,30,11,100,7,41,86 };
	printf("测试数组为<39,80,76,41,13,29,50,78,30,11,100,7,41,86>");
	printf("\n\n");
	//printf("直接插入算法排序结果：");
	//InsertSort(a, n);
	//printf("直接选择排序结果：");
	//SelectSort(a,n);
	//printf("快速排序算法排序结果：");
	//int low = 0;
	//int high = 13;
	//QuickSort(a, low, high);
	printf("堆排序算法排序结果：");
	HeapSort(a, n); 
	PrintArray(a, n);
	return 0;
}
