#define _CRT_SECURE_NO_WARNINGS 1

//3
//#include <stdio.h>
//void main()
//{
//	int a, b, temp, i, n;
//	double sum = 0.0;
//	n = 20;
//	a = 2, b = 1;
//	for (i = 1; i < n; i++)
//	{
//		sum = sum + ((double)a / b);
//		temp = b;
//		b = a;
//		a = a + temp;
//	}
//	printf("s=%f\n", sum);
//}


//7.
//#include <stdio.h>
//void main()
//{
//	int i, k;
//	for (i = 1; i <= 9; i++)
//	{
//		for (k = 1; k <= i; k++)
//			printf(" %d*%d=%d ", k, i, i * k);
//		printf("\n");
//	}
//}


//8.
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//void main()
//{
//	int a, b, numOfQues = 0, numOfRight = 0;
//	char inquiry='a';
//	srand(time(NULL));
//	printf("***��ӭ������һλ���ļӼ��˳�����***\n");
//	do {
//		fflush(stdin);
//		int temp = rand() % 4;
//		a = rand() % 10;
//		b = rand() % 10;
//		switch (temp)
//		{
//		   case 0:
//		   {
//			   int ans;
//			   printf("%d+%d=", a, b);
//			   scanf("%d", &ans);
//			   if (ans == a + b)
//			   {
//				   numOfRight++;
//				   printf("��ϲ!����ˣ�\n");
//			   }
//			   else
//				   printf("����ˣ��ٽ�����\n");
//			   break;
//		   }
//		   case 1:
//		   {
//			   int ans;
//			   printf("%d-%d=", a, b);
//			   scanf("%d", &ans);
//			   if (ans == a - b)
//			   {
//				   numOfRight++;
//				   printf("��ϲ!����ˣ�\n");
//			   }
//			   else
//				   printf("����ˣ��ٽ�����\n");
//			   break;
//		   }
//		   case 2:
//		   {
//			   int ans;
//			   printf("%d*%d=", a, b);
//			   scanf("%d", &ans);
//			   if (ans == a * b)
//			   {
//				   numOfRight++;
//				   printf("��ϲ!����ˣ�\n");
//			   }
//			   else
//				   printf("����ˣ��ٽ�����\n");
//			   break;
//		   }
//		   case 3:
//		   {
//			   if (b == 0 || (a % b != 0))continue;
//			   int ans;
//			   printf("%d/%d=", a, b);
//			   scanf("%d", &ans);
//			   if (ans == a / b)
//			   {
//				   numOfRight++;
//				   printf("��ϲ!����ˣ�\n");
//			   }
//			   else
//				   printf("����ˣ��ٽ�����\n");
//			   break;
//		   }
//		}
//		numOfQues++;
//		printf("����N�˳����س���������\n");
//		fflush(stdin);
//		scanf("%c", &inquiry);
//		if ('N' == inquiry)
//			break;
//	} while (!('N' == inquiry || 'n' == inquiry));
//	printf("��Ĵ�����ȷ��Ϊ%d%%", numOfRight * 100 / numOfQues);
//	switch (numOfRight * 10 / numOfQues)
//	{
//	    case 10:
//		case 9:
//			printf("ţ��ţ�ܣ�\n");
//			break;
//		case 8:
//		case 7:
//			printf("���У�\n");
//			break;
//		case 6:
//			printf("�ռ��񣬾��⣿\n");
//			break;
//		default:
//			printf("������̫����\n");
//	}
//}



//9.
#include <stdio.h>
void main()
{
	int stuno = 201201;
	int score, i;
	int min = 100, max = 0;
	int stumin = stuno, stumax = stuno;
	for (i = 1; i < 9; i++)
	{
		printf("������%dͬѧ�ĳɼ�", stuno);
		scanf("%d", &score);
		if (score > max)
		{
			max = score;
			stumax = stuno;
		}
		if (score < min)
		{
			min = score;
			stumin = stuno;
		}
		stuno++;
	}
	printf("��߷�ͬѧ�ǣ�%d�ɼ��ǣ�%d\n", stumax, max);
	printf("��ͷ�ͬѧ�ǣ�%d�ɼ��ǣ�%d\n", stumin, min);
}

