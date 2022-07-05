#define _CRT_SECURE_NO_WARNINGS
#include "Sq.h"


void StackInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}

void StackDestory(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}

void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		ps->a = (STDataType*)realloc(ps->a, newCapacity * sizeof(STDataType));
		if (ps->a == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		ps->capacity = newCapacity;
	}
	ps->a[ps->top] = x;
	ps->top++;
}

void StackPop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);
	--ps->top;
}

bool StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}

STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);

	return ps->a[ps->top - 1];
}


int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}

void OctToBin(ST* ps,int n)
{
	int m = 0;
	while (n)
	{
		StackPush(ps, n % 2);
		n = n / 2;
	}
	while (!StackEmpty(ps))
	{
		printf("%d", StackTop(ps));
		StackPop(ps);
	}
}

/*int main()
{
	ST st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	printf("%d ", StackTop(&st));
	printf("\n");
	StackPop(&st);
	StackPush(&st, 3);
	StackPush(&st, 4);
	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
	StackDestory(&st);
	return 0;
}*/

//int main()
//{
//	ST st;
//	StackInit(&st);
//	int n = 0;
//	printf("请输入一位十进制整数：");
//	scanf("%d", &n);
//	OctToBin(&st, n);
//	StackDestory(&st);
//	return 0;
//}