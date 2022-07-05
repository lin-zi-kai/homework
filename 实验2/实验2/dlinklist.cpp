#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#define HEAD printf("------------------------------------------------------------------------------------\n");

//��ʼ��һ��˫����
//��ʼ����Ҫ���Ĺ����ǽ�ͷ���malloc������
typedef char DLinkType;
//���Ľṹ�壨ָ��ǰ����㣬��̽�㣬����һ�����ݣ�
typedef struct DLinkNode {
    DLinkType data;
    struct DLinkNode* next;
    struct DLinkNode* prev;
}DLinkNode;

void DLinkListInit(DLinkNode*& head)
{
    assert(head);
    (head) = (DLinkNode*)malloc(sizeof(DLinkNode));
    (head)->next = NULL;
    (head)->prev = NULL;
}
//����һ�����
//��װһ�����������ڲ���ʱֱ��ʹ�á�
DLinkNode* CreateNode(DLinkType value)
{
    DLinkNode* ret = (DLinkNode*)malloc(sizeof(DLinkNode));
    ret->data = value;
    ret->next = NULL;
    ret->prev = NULL;
    return ret;
}
//����һ�����
//��Ӧ����������һ�����ٽ��
void DestroyNode(DLinkNode* ptr)
{
    free(ptr);
    ptr = NULL;
}
//˫�����β��
DLinkNode* PushDLinkList(DLinkNode* head, DLinkType value)
{
    assert(head != NULL);
    DLinkNode* newnode = CreateNode(value);
    //���½��ĺ�̽ڵ�ָ���
    newnode->next = NULL;
    DLinkNode* end = head;
    //�ҵ����һ�����
    while (end->next != NULL)
    {
        end = end->next;
    }
    //�����һ������next���ָ��newnode
    end->next = newnode;
    //��newnode��prev���ָ��end
    newnode->prev = end;
    return newnode;
}
// βɾ
void DLinListPopBack(DLinkNode* head)
{
    assert(head);
    DLinkNode* tmp = head;
    //�����ǰ����û����ЧԪ��
    if (tmp->next == NULL)
        return;
    //�����ǰ����ֻ��һ�����
    if (tmp->next->next == NULL)
    {
        DestroyNode(tmp->next);
        head->next = NULL;
        return;
    }
    while (tmp->next->next)
    {
        tmp = tmp->next;
    }
    DestroyNode(tmp->next);
    tmp->next = NULL;
}
//ͷ��
void DLinkListPushFront(DLinkNode* head, DLinkType value)
{
    assert(head);
    DLinkNode* newnode = CreateNode(value);
    if (head->next == NULL)
    {
        head->next = newnode;
        newnode->next = NULL;
        newnode->prev = head;
        return;
    }
    newnode->next = head->next;
    head->next->prev = newnode;
    head->next = newnode;
    newnode->prev = head;
}
//ͷɾ
void DLinkListPopFront(DLinkNode* head)
{
    assert(head);
    //ֻ��һ��ͷ�ڵ�
    if (head->next == NULL)
    {
        return;
    }
    DLinkNode* to_delete = head->next;
    head->next = to_delete->next;
    DestroyNode(to_delete);
    if (head->next != NULL)
    {
        head->next->prev = head;
    }
}
//�������в���
DLinkNode* DLinkListFind(DLinkNode* head, DLinkType to_find)
{
    assert(head);
    if (head->next == NULL)
        return NULL;
    DLinkNode* tmp = head->next;
    while (tmp)
    {
        if (tmp->data == to_find)
            return tmp;
        tmp = tmp->next;
    }
    return NULL;
}
//
///** 
//* @brief ��ָ��λ��֮ǰ����һ��Ԫ�� 
//*/ 
void DLinkListInsert(DLinkNode* pos, DLinkType value)
{
    assert(pos);
    DLinkNode* newnode = CreateNode(value);
    newnode->next = pos;
    newnode->prev = pos->prev;
    pos->prev = newnode;
    newnode->prev->next = newnode;
}
//��ָ��λ��֮�����һ��Ԫ��  
void DLinkListInsertAfter(DLinkNode* pos, DLinkType value)
{
    assert(pos);
    DLinkNode* newnode = CreateNode(value);
    newnode->prev = pos;
    newnode->next = pos->next;
    pos->next = newnode;
    newnode->next->prev = newnode;
}
void PrintList(DLinkNode* head)
{
    assert(head);
    DLinkNode* tmp = head->next;
    if (tmp == NULL)
        return;
    while (tmp != NULL)
    {
        printf("%c  ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

void Reverse(DLinkNode* ps)
{
    if (ps == NULL ||  ps->next == NULL)
        return;
    DLinkNode* p1 = ps->next;
    DLinkNode* p2 = p1->next;
    DLinkNode* p3 = NULL;
    p1->next = NULL;
    while (p2)
    {
        p3 = p2->next;
        p2->next = p1;
        p1->prev = p2;
        p1 = p2;
        p2 = p3;
    }
    ps->next = p1;
}

int main()
{
    HEAD;
    DLinkNode* head;
    DLinkListInit(head);
    PushDLinkList(head, 'a');
    PushDLinkList(head, 'b');
    PushDLinkList(head, 'c');
    PushDLinkList(head, 'd');
    PushDLinkList(head, 'e');
    PrintList(head);
	Reverse(head);
    PrintList(head);
	return 0;
}
