#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef char ElemType;
typedef struct LinkList
{
	ElemType data;
	struct LinkList* next;
}ListNode;

ListNode* InitList()
{
	ListNode* c = (ListNode*)malloc(sizeof(ListNode));
	ListNode* tmp = c;
	if (tmp == NULL)
		return NULL;
	tmp->next = NULL;
	return c;
}

bool PopList(LinkList* c, ElemType n)
{
	if (c == NULL)
		return false;
	LinkList* p = c;
	LinkList* newnode = (LinkList*)malloc(sizeof(LinkList));
	newnode->data = n;
	while (p != NULL)
	{
		if (p->next == NULL)
		{
			p->next = newnode;
			newnode->next = NULL;
			break;
		}
		else
		{
			p = p->next;
		}
	}
	return true;
}

bool AddList(LinkList* c, ElemType e, int n)
{
	if (c == NULL)
		return false;
	int i = 0;
	LinkList* p = c;
	LinkList* newnode = (LinkList*)malloc(sizeof(LinkList));
	newnode->data = e;
	while (p != NULL)
	{
		if (i == n - 1)
		{
			newnode->next = p->next;
			p->next = newnode;
			break;
		}
		else
		{
			p = p->next;
			i++;
		}
	}
	return true;
}

bool DelList(LinkList* c, int n, ElemType& e)
{
	if (c == NULL)
		return false;
	LinkList* p = c->next;
	ListNode* prev = c;
	int count = 0;
	while (prev != NULL && count <= n)
	{
		if (count == n)
		{
			prev->next = p->next;
			free(p);
			break;
		}
		else
		{
			p = p->next;
			prev = prev->next;
			count++;
		}
	}
	if (p == NULL)
		printf("找不到\n");
	else
		e = p->data;
	return true;
}

bool Modlist(LinkList* c, ElemType &e, int n)
{
	if (c == NULL)
		return false;
	LinkList* p = c;
	int count = 0;
	while (p != NULL)
	{
		if (count == n)
		{
			scanf("%d", &e);
			p->data = e;
		}
		else
		{
			p = p->next;
			count++;
		}
	}
	return true;
}

void PrintList(LinkList* c)
{
	LinkList* p = c->next;
	while (p != NULL)
	{
		printf("%c  ", p->data);
		p = p->next;
	}
	printf("\n");
}

int LenList(ListNode* c)
{
	ListNode* p = c->next;
	int count = 0;
	while (p != NULL)
	{
		count++;
		p = p->next;
	}
	return count;
}

int Locate(ListNode* c, ElemType n)
{
	ListNode* p = c->next;
	int count = 1;
	while (p != NULL)
	{
		if (p->data == n)
			return count;
		else
		{
			p = p->next;
			count++;
		}
	}
}

ElemType Find(ListNode* c, int n)
{
	ListNode* p = c->next;
	int i = 0;
	for (i = 0; i < n; i++)
	{
		if (p != NULL && i == n - 1)
			return p->data;
		p = p->next;
	}
	printf("找不到\n", n);
	return 0;
}

void Destorylist(LinkList*& c)
{
	free(c);
	printf("销毁成功\n");
}

void IsEmpty(LinkList* head)
{
	if (head->next == NULL)
		printf("链表为空\n");
	else
		return;
}

void DelRangeList(LinkList* head, int min, int max)
{
	LinkList* p, * q, * tmp = NULL, * temp;
	p = head->next;
	while (p && p->data <= min)
	{
		tmp = p;
		p = p->next;
	}
	if (p)
	{
		while (p && p->data < max)
		{  
			p = p->next;
		}
		q = tmp->next;
		tmp->next = p;
		while (q != p)
		{
			temp = q->next;
			free(q);
			q = temp;
		}
	}
}

//int main()
//{
//	LinkList* h = InitList();
//	char e;
//	PopList(h, 'a');
//	PopList(h, 'b');
//	PopList(h, 'c');
//	PopList(h, 'd');
//	PopList(h, 'e');
//	PrintList(h);
//	printf("链表长度为%d\n", LenList(h));
//	IsEmpty(h);
//	printf("链表的第3个元素为%c\n", Find(h, 3));
//	printf("元素a的逻辑位置为%d\n", Locate(h, 'a'));
//	AddList(h, 'f', 4);
//	PrintList(h);
//	DelList(h, 2, e);
//	PrintList(h);
//	Destorylist(h); 
//	return 0;
//}

int main()
{
	LinkList* head;
	int min = 0, max = 0;
	head = InitList();
	PopList(head, 'a');
	PopList(head, 'b');
	PopList(head, 'c');
	PopList(head, 'd');
	PopList(head, 'e');
	PrintList(head);
	printf("输入最小值和最大值:");
	scanf("%d %d", &min,&max);
	DelRangeList(head, min, max);
	PrintList(head);
	return 0;
}
