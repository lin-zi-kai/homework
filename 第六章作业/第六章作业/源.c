#define _CRT_SECURE_NO_WARNINGS

//5.
//#include <stdio.h>
//void main()
//{
//	char s1[80], s2[40];
//	int i = 0, j = 0;
//	printf("请输入第一个字符串：\n");
//	gets(s1);
//	printf("请输入第二个字符串：\n");
//	gets(s2);
//	while (s1[i++] != '\0');
//		i--;
//	while ((s1[i++] = s2[j++]) != '\0');
//		printf("%s\n", s1);
//}



//7.
//#include <stdio.h>
//#include <string.h>
//#define N 1
//void main()
//{
//	char str[100] = { 0 };
//	int i, length;
//	printf("请输入要加密的字符串（长度不要大于100）：\n");
//	gets(str);
//	length = strlen(str);
//	printf("\n加密后的字符串是：\n");
//	for (i = 0; i < length; i++)
//	{
//		str[i] = str[i] + N;
//		printf("%c", str[i]);
//	}
//	printf("\n还原后的字符串是：\n");
//	for (i = 0; i < length; i++)
//	{
//		str[i] = str[i] - N;
//		printf("%c", str[i]);
//	}
//}


//9.
//#include <stdio.h>
//void main()
//{
//	int a[10];
//	int i, j,temp;
//	printf("请输入10个数：");
//	for (i = 0; i < 10; i++)
//		scanf("%d", &a[i]);
//	for (i = 0; i < 9; i++)
//	{
//		for (j = i + 1; j < 10; j++)
//		{
//			if (a[i] > a[j])
//			{
//				temp = a[i];
//				a[i] = a[j];
//				a[j] = temp;
//			}
//		}
//	}
//	printf("\n");
//	for(i=0;i<10;i++)
//		printf("%d ",a[i]);
//}


//10
#include <stdio.h>
void main()
{
	int a[15];
	int i,number, flag = 0;
	printf("请输入长度为15的数组：\n");
	for (i = 0; i < 15; i++)
		scanf("%d", &a[i]);
	printf("请输入要查找的数：");
	scanf("%d", &number);
	for (i = 0; i < 15; i++)
	{
		if (a[i] == number)
		{
			printf("该数是数组中的第%d个元素的值\n",i+1);
			flag = 1;
		}
	}
	if (flag == 0)
		printf("没有这个数");
}