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
//	printf("***欢迎你来做一位数的加减乘除运算***\n");
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
//				   printf("恭喜!答对了！\n");
//			   }
//			   else
//				   printf("答错了，再接再厉\n");
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
//				   printf("恭喜!答对了！\n");
//			   }
//			   else
//				   printf("答错了，再接再厉\n");
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
//				   printf("恭喜!答对了！\n");
//			   }
//			   else
//				   printf("答错了，再接再厉\n");
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
//				   printf("恭喜!答对了！\n");
//			   }
//			   else
//				   printf("答错了，再接再厉\n");
//			   break;
//		   }
//		}
//		numOfQues++;
//		printf("输入N退出，回车继续做题\n");
//		fflush(stdin);
//		scanf("%c", &inquiry);
//		if ('N' == inquiry)
//			break;
//	} while (!('N' == inquiry || 'n' == inquiry));
//	printf("你的答题正确率为%d%%", numOfRight * 100 / numOfQues);
//	switch (numOfRight * 10 / numOfQues)
//	{
//	    case 10:
//		case 9:
//			printf("牛蛙牛蛙！\n");
//			break;
//		case 8:
//		case 7:
//			printf("还行！\n");
//			break;
//		case 6:
//			printf("刚及格，就这？\n");
//			break;
//		default:
//			printf("不及格，太拉了\n");
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
		printf("请输入%d同学的成绩", stuno);
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
	printf("最高分同学是：%d成绩是：%d\n", stumax, max);
	printf("最低分同学是：%d成绩是：%d\n", stumin, min);
}

