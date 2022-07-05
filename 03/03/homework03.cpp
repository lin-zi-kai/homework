#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

struct Node
{
    DataType data;    
    struct Node* next;       
};

struct Queue
{
    Node* rear;
};

void Initiate(Queue* queue)
{
    queue->rear = (Node*)malloc(sizeof(Node));
    queue->rear->next = queue->rear;
}

int isNotEmpty(Queue* queue)
{
    if (queue->rear->next == queue->rear) 
        return 0;
    else
        return 1;
}
//入队函数
int queuePush(Queue* queue, int x)
{
    Node* p = queue->rear;    
    while (p->next != queue->rear)
    {
        p = p->next;
    }
    Node* q;
    q = (Node*)malloc(sizeof(Node));
    q->data = x;                   
    q->next = queue->rear;          
    p->next = q;                    
    printf("入队成功！\n");
    return 1;
}
//出队函数，将成功出队的数据赋给d
int queuePop(Queue* queue, int* d)
{
    if (isNotEmpty(queue) == 0)
    {
        printf("队列为空！");
        return 0;
    }
    Node* q = queue->rear->next;       
    queue->rear->next = q->next;      
    *d = q->data;                      
    free(q);                          
    return 1;
}

void print(Queue* queue)
{
    Node* p = queue->rear;
    printf("队列：");
    if (isNotEmpty(queue) == 0)
    {
        printf("队列为空\n");
        return;
    }
    //遍历输出
    while (p->next != queue->rear)
    {
        printf("%d  ", p->next->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    Queue queue, * p;
    p = &queue;
    Initiate(p);
    printf("请输入要入队的数：");
    int n, data;
    scanf_s("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf_s("%d", &data);
        queuePush(p, data);
    }
    print(p);
    int x;
    /*测试出队*/
    if (queuePop(p, &x))
        printf("已取出数据：%d\n", x);
    print(p);
    printf("出队成功\n");
    system("pause");
    if (queuePop(p, &x))
        printf("已取出数据：%d\n", x);
    print(p);
    system("pause");
    if (queuePop(p, &x))
        printf("已取出数据：%d\n", x);
    print(p);
    printf("出队成功：");
    scanf_s("%d", &data);
    queuePush(p, data);
    print(p);
    system("pause");
    /*又测试出队*/
    if (queuePop(p, &x))
        printf("已取出数据：%d\n", x);
    print(p);
    system("pause");
    if (queuePop(p, &x))
        printf("已取出数据：%d\n", x);
    print(p);
    system("pause");
    if (queuePop(p, &x))
        printf("已取出数据：%d\n", x);
    print(p);
    system("pause");
    if (queuePop(p, &x))
        printf("已取出数据：%d\n", x);
    print(p);
    system("pause");
    return 0;
}