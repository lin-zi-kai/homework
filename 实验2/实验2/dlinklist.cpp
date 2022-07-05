#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#define HEAD printf("------------------------------------------------------------------------------------\n");

//初始化一个双链表
//初始化需要做的工作是将头结点malloc出来。
typedef char DLinkType;
//结点的结构体（指向前驱结点，后继结点，还有一个数据）
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
//创建一个结点
//封装一个函数，便于插入时直接使用。
DLinkNode* CreateNode(DLinkType value)
{
    DLinkNode* ret = (DLinkNode*)malloc(sizeof(DLinkNode));
    ret->data = value;
    ret->next = NULL;
    ret->prev = NULL;
    return ret;
}
//销毁一个结点
//对应创建结点就有一个销毁结点
void DestroyNode(DLinkNode* ptr)
{
    free(ptr);
    ptr = NULL;
}
//双链表的尾插
DLinkNode* PushDLinkList(DLinkNode* head, DLinkType value)
{
    assert(head != NULL);
    DLinkNode* newnode = CreateNode(value);
    //让新结点的后继节点指向空
    newnode->next = NULL;
    DLinkNode* end = head;
    //找到最后一个结点
    while (end->next != NULL)
    {
        end = end->next;
    }
    //让最后一个结点的next结点指向newnode
    end->next = newnode;
    //让newnode的prev结点指向end
    newnode->prev = end;
    return newnode;
}
// 尾删
void DLinListPopBack(DLinkNode* head)
{
    assert(head);
    DLinkNode* tmp = head;
    //如果当前链表没有有效元素
    if (tmp->next == NULL)
        return;
    //如果当前链表只有一个结点
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
//头插
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
//头删
void DLinkListPopFront(DLinkNode* head)
{
    assert(head);
    //只有一个头节点
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
//在链表中查找
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
//* @brief 往指定位置之前插入一个元素 
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
//往指定位置之后插入一个元素  
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
