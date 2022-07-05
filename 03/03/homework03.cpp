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
//��Ӻ���
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
    printf("��ӳɹ���\n");
    return 1;
}
//���Ӻ��������ɹ����ӵ����ݸ���d
int queuePop(Queue* queue, int* d)
{
    if (isNotEmpty(queue) == 0)
    {
        printf("����Ϊ�գ�");
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
    printf("���У�");
    if (isNotEmpty(queue) == 0)
    {
        printf("����Ϊ��\n");
        return;
    }
    //�������
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
    printf("������Ҫ��ӵ�����");
    int n, data;
    scanf_s("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf_s("%d", &data);
        queuePush(p, data);
    }
    print(p);
    int x;
    /*���Գ���*/
    if (queuePop(p, &x))
        printf("��ȡ�����ݣ�%d\n", x);
    print(p);
    printf("���ӳɹ�\n");
    system("pause");
    if (queuePop(p, &x))
        printf("��ȡ�����ݣ�%d\n", x);
    print(p);
    system("pause");
    if (queuePop(p, &x))
        printf("��ȡ�����ݣ�%d\n", x);
    print(p);
    printf("���ӳɹ���");
    scanf_s("%d", &data);
    queuePush(p, data);
    print(p);
    system("pause");
    /*�ֲ��Գ���*/
    if (queuePop(p, &x))
        printf("��ȡ�����ݣ�%d\n", x);
    print(p);
    system("pause");
    if (queuePop(p, &x))
        printf("��ȡ�����ݣ�%d\n", x);
    print(p);
    system("pause");
    if (queuePop(p, &x))
        printf("��ȡ�����ݣ�%d\n", x);
    print(p);
    system("pause");
    if (queuePop(p, &x))
        printf("��ȡ�����ݣ�%d\n", x);
    print(p);
    system("pause");
    return 0;
}