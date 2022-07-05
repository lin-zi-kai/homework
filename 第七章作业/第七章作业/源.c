#define _CRT_SECURE_NO_WARNINGS
//6.
//#include <stdio.h>
//#include <math.h>
//double ssin(double x, double y)
//{
//	double p = 1, t, sum = 0, sign=1;
//	t = x; 
//	while(fabs(t)>y)
//	{
//		sum = sum + sign * t;
//		t = t * x * x / (p + 1) / (p + 2);
//		p = p + 2;
//		sign = sign * (-1);
//	}
//	return sum;
//}
//
//void main()
//{
//	double x, y;
//	scanf("%lf%lf", &x, &y);
//	printf("sin(%f)=%f\n",x,ssin(x, y));
//	printf("\n");
//
//}



//7.
//#include <stdio.h>
//void main()
//{
//	void paixu(int a[], int n);
//	int a[10] = { 0 };
//	int i = 0;
//	printf("enter data:\n");
//	for (i = 0; i < 10; i++)
//		scanf("%d", &a[i]);
//	paixu(a, 10);
//	for (i = 0; i < 10; i++)
//		printf("%d ", a[i]);
//	printf("\n");
//}
//void paixu(int a[], int n)
//{
//	int i, j, m;
//	for (i = 0; i < n - 1; i++)
//	{
//		for(j=1;j<n-i;j++)
//			if (a[j] < a[j-1])
//			{
//				m = a[j-1];
//				a[j-1] = a[j];
//				a[j] = m;
//			}
//	}
//}



//8.
//#include <stdio.h>
//#include <stdlib.h>
//int gcd(int m, int n)
//{
//	int t;
//	if (n == 0 || m == 0)
//	{
//		printf("输入错误！");
//		return -1;
//	}
//	while (m % n != 0)
//	{
//		t = m % n;
//		m = n;
//		n = t;
//	}
//	return n;
//}
//
//void main()
//{
//	int x, y;
//	scanf("%d%d", &x, &y);
//	printf("%d\n", gcd(x, y));
//}

//9
//#include <stdio.h>
//#include <stdlib.h>
//double intpower(double x, int y)
//{
//	double t;
//	if (y == 0)return 1;
//	else {
//		t = x * intpower(x, y - 1);
//		return t;
//	}
//}
//
//void main()
//{
//	int y;
//	double x;
//	scanf("%lf%d", &x, &y);
//	printf("%lf\n", intpower(x, y));
//}

//10.
#include <stdio.h>
#include <string.h>
#define M 1000
int findlstr(char p[])
{
	int low=0, high=0,i, count=0, temp, low_temp, high_temp;
	for (i = 0; i < (int)strlen(p); i++)
	{
		temp = 0;
		low_temp = i;
		while (p[i] != ' ' && p[i] != '\0')
		{
			temp++;
			i++;
		}
		high_temp = i - 1;
		if (temp > count)
		{
			count = temp;
			low = low_temp;
			high = high_temp;
		}
	}
	return low;
}
void main()
{
	char p[M] = { 0 };
	gets(p);
	printf("最长单词的位置=%d\n", findlstr(p)+1);

}