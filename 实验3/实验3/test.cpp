#define _CRT_SECURE_NO_WARNINGS
#include "Sq.h"
#define MAXSIZE 50

bool IsPalindrome(ST* ps,CircularQueue* obj,int n) {
    int a, b;
    int i = 0;
    int x = 0;
   
    while (n)
    {
        x = n % 10;
        n = n / 10;
        StackPush(ps, x);
        CircularQueueEnQueue(obj, x);
        i++;
    }
    for (i; i > 0; i--) 
    {
        a = StackTop(ps);
        StackPop(ps);
        b = CircularQueueFront(obj);
        CircularQueueDeQueue(obj);
        if (a != b)
            return false;
    }
    return true;
}

int main()
{
    ST st;
    CircularQueue cq;
    StackInit(&st);
    CircularQueue* obj = CircularQueueCreate(MAXSIZE);
    int n = 0;
    printf("请输入：");
    scanf("%d", &n);
    if (IsPalindrome(&st,obj,n))
        printf("是回文数");
    else
        printf("不是回文数");
    CircularQueueFree(obj);
    CircularQueueDeQueue(obj);
}