#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#define MaxSize 50
//
//typedef struct SeqList
//{
//    int* data;
//    int length;
//}SeqList;
//
//void CreateList(SeqList* L)
//{
//    L->data = (int*)malloc(sizeof(int) * MaxSize);
//    for (int i = 0; i < MaxSize; i++)
//    {
//        L->data[i] = 0;
//    }
//    L->length = 0;
//    printf("������˳���ĳ��ȣ�\n");
//    scanf("%d", &L->length);
//    printf("������˳�������ݣ�\n");
//    for (int i = 0; i < L->length; i++)
//    {
//        scanf("%d", &L->data[i]);
//    }
//    printf("�����ɹ�\n");
//}
//
//int GetElemLocate(SeqList* L, int i)
//{
//    return L->data[i - 1];
//}
//
//int GetElemNum(SeqList* L, int e)
//{
//    for (int i = 0; i < L->length; i++)
//    {
//        if (L->data[i] == e)
//            return i + 1;
//    }
//    printf("�Ҳ�����ֵ\n");
//    return 0;
//}
//
//void InsertNum(SeqList* L, int i, int e)
//{
//    int j = 0;
//    if (i<1 || i>L->length+1)
//    {
//        printf("����λ�ô���\n");
//        return;
//    }
//    if (L->length > MaxSize)
//    {
//        printf("����λ�ô���\n");
//        return;
//    }
//    for (int j = L->length; j >= i; j--)
//    {
//        L->data[j] = L->data[j - 1];
//    }
//    L->data[i - 1] = e;
//    L->length++;
//    printf("����ɹ�\n");
//}
//
//int DeleteNum(SeqList* L, int i)
//{
//    int j = 0;
//    int k = 0;
//    if (i<1 || i>L->length)
//    {
//        printf("ɾ��λ�ô���");
//        return 0;
//    }
//    if (L->length > MaxSize)
//    {
//        printf("ɾ��λ�ô���");
//        return 0;
//    }
//    k = L->data[i];
//    for (j = i; j < L->length; j++)
//        L->data[j - 1] = L->data[j];
//    L->length--;
//    printf("ɾ���ɹ�\n");
//    return k;
//}
//
//void DestoryList(SeqList* L)
//{
//    if (L->length == 0)
//        printf("˳�������\n");
//    if (L->data)
//        L->data = NULL;
//    L->length = 0;
//    printf("���ٳɹ�\n");
//
//}
//
//int ListLength(SeqList* L)
//{
//    return (L->length);
//}
//
//bool ListEmpty(SeqList* L)
//{
//    return(L->length == 0);
//}
//
////�㷨2.2
//void Union(SeqList* La, SeqList* Lb)
//{
//    int e;
//    int La_length = ListLength(La);
//    while (!ListEmpty(Lb))
//    {
//        e = DeleteNum(Lb, 1);
//        if (!GetElemNum(La, e))
//        {
//            InsertNum(La, ++La_length, e);
//        }
//    }
//    DestoryList(Lb);
//}
//
//int main()
//{
//    SeqList L;
//    SeqList Lb;
//    printf("*******************************************\n");
//    printf("*****1.����˳���*********2.��ӡ˳���*****\n");
//    printf("*****3.��ֵ����***********4.��λ����*******\n");
//    printf("*****5.��������***********6.ɾ������*******\n");
//    printf("*****7.�������***********8.�ͷ�˳���*****\n");
//    printf("*****-1.�˳�����**********9.�㷨2.2********\n");
//    printf("*******************************************\n");
//    int control;
//    int nums;
//    int i, inlocate, innum, dellocate;
//    do {
//        printf("��������Ĳ���ѡ�");
//        scanf("%d", &control);
//        switch (control)
//        {
//            case 1: 
//            {
//                CreateList(&L);
//                CreateList(&Lb);
//                break;
//            }
//            case 2:
//            {
//                for (int i = 0; i < L.length; i++)
//                {
//                    printf("%d  ", L.data[i]);
//                }
//                printf("\n");
//                break;
//            }
//            case 3:
//            {
//                printf("������������ҵ�ֵ:");
//                scanf("%d", &nums);
//                printf("��ֵ��Ӧ���߼�λ��Ϊ%d\n", GetElemNum(&L, nums));
//                break;
//            }
//            case 4:
//            {
//                printf("����������������ݵ����:");
//                scanf("%d", &i);
//                printf("����Ŷ�Ӧ������Ϊ��%d\n", GetElemLocate(&L, i));
//                break;
//            }
//            case 5:
//            {
//                printf("���������λ��:");
//                scanf("%d", &inlocate);
//                printf("�����������ֵ��С:");
//                scanf("%d", &innum);
//                InsertNum(&L, inlocate, innum);
//                break;
//            }
//            case 6:
//            {
//                printf("����������ɾ�����ݵ�λ��:");
//                scanf("%d", &dellocate);
//                DeleteNum(&L, dellocate);
//                break;
//            }
//            case 7: 
//            {
//                printf("˳���ĳ���Ϊ%d\n", ListLength(&L));
//                break;
//            }
//            case 8:
//            {
//                DestoryList(&L);
//                break;
//            }
//            case 9:
//            {
//                Union(&L, &Lb);
//                break;
//            }
//            case -1: 
//            {
//                printf("�˳��ɹ�");
//                break;
//            }
//            default:
//            {
//                printf("ѡ�����������ѡ��\n");
//                break;
//            }
//        }
//    } while (control != -1);
//
//    return 0;
//}


//#include<stdio.h>
//#include<stdlib.h>
//#define MaxSize 100
////����˳���
//typedef struct SqList {
//    int* data;
//    int length;
//}SqList;
//
////2.����˳���
//void CreatList(SqList* L)
//{
//    L->data = (int*)malloc(sizeof(int) * MaxSize);
//    for (int i = 0; i < MaxSize; i++)
//    {
//        L->data[i] = 0;
//    }
//    L->length = 0;
//    printf("������˳���ĳ��ȣ�\n");
//    scanf("%d", &L->length);
//    printf("������˳�������ݣ�\n");
//    for (int i = 0; i < L->length; i++)
//    {
//        scanf("%d", &L->data[i]);
//    }
//    printf("�����ɹ�\n");
//}
////8.˳���ĳ���
//int ListLength(SqList* L)
//{
//    printf("����Ϊ%d\n", L->length);
//    return (L->length);
//}
////ɾ��
//void Delnum(SqList* L, int x, int y)
//{
//    int i = 0, j = L->length - 1;
//    while (i < j)
//    {
//        if ((L->data[i] < x) || (L->data[i] > y))
//            i++;
//        if ((L->data[j] >= x) && (L->data[j] <= y))
//            j--;
//        if (((L->data[j] < x) || (L->data[j] > y)) && ((L->data[i] >= x) && (L->data[i] <= y)))
//        {
//            int tmp = L->data[i];
//            L->data[i] = L->data[j];
//            L->data[j] = tmp;
//        }
//    }
//    L->length = j;
//}
//
//void MoveList(SqList* L, int x, int y)
//{
//    {
//        int x = 1, y = L->length;
//        while (x < y)
//        {
//            if (L->data[x] > 0 && L->data[y] < 0)
//            {
//                int tmp = L->data[x];
//                L->data[x] = L->data[y];
//                L->data[y] = tmp;
//            }
//            if (L->data[x] < 0)
//                x++;
//            if (L->data[y] >= 0)
//                y--;
//        }
//    }
//}
//
//int main()
//{
//    SqList L;
//    int x = 0, y = 0;
//    CreatList(&L);
//    //printf("������ɾ�����ݵĴ�С��Χ��");
//    //scanf("%d %d", &x, &y);
//    MoveList(&L, x, y);
//    for (int i = 0; i < L.length; i++)
//    {
//        printf("%d  ", L.data[i]);
//    }
//    printf("\n");
//    return 0;
//}
//
//#include<stdio.h>
//#include<stdlib.h>
//
//typedef int ElemType;
//
//typedef struct LinkList
//{
//	ElemType data;
//	struct LinkList* next;
//}ListNode;
//
//ListNode* Initlist()
//{
//	ListNode* c = (ListNode*)malloc(sizeof(ListNode));
//	ListNode* temp = c;
//	if (temp == NULL)
//		return NULL;
//	temp->next = NULL;
//	return c;
//}
//
//bool AddList(LinkList* c, ElemType n)
//{
//	if (c == NULL)
//		return false;
//	LinkList* p = c;
//	LinkList* NewNode = (LinkList*)malloc(sizeof(LinkList));
//	NewNode->data = n;
//	while (p != NULL)
//	{
//		if (p->next == NULL)
//		{
//			p->next = NewNode;
//			NewNode->next = NULL;
//			break;
//		}
//		else
//		{
//			p = p->next;
//		}
//	}
//	return true;
//}
//
//bool DelList(LinkList* c, int n, ElemType& e)
//{
//	if (c == NULL)
//		return false;
//	LinkList* p = c->next;
//	ListNode* pre = c;
//	int count = 1;
//	while (pre != NULL && count <= n)
//	{
//		if (count == n)
//		{
//			pre->next = p->next;
//			free(p);
//			break;
//		}
//		else
//		{
//			p = p->next;
//			pre = pre->next;
//			count++;
//		}
//	}
//	if (p == NULL)
//	{
//		printf("�Ҳ���\n");
//	}
//	else
//	{
//		e = p->data;
//	}
//	return true;
//
//}
//
//bool SearchList(LinkList* c, int n, ElemType& e)
//{
//	if (c == NULL)
//		return false;
//	LinkList* p = c;
//	n = 0;
//	while (p != NULL)
//	{
//		if (p->data == e)
//		{
//			printf("�ҵ��ˣ�λ��%d��λ\n", n);
//		}
//		else
//		{
//			p = p->next;
//		}
//	}
//	return true;
//}
//
//bool ModList(LinkList* c, ElemType& e, int n)
//{
//	if (c == NULL)
//		return false;
//	LinkList* p = c;
//	int count = 0;
//	while (p != NULL)
//	{
//		if (count == n)
//		{
//			scanf("%d", &e);
//			p->data = e;
//		}
//		else
//		{
//			p = p->next;
//			count++;
//		}
//	}
//	return true;
//}
//
//void Printlist(LinkList* c)
//{
//	LinkList* p = c->next;
//	while (p != NULL)
//	{
//		printf("%d\t", p->data);
//		p = p->next;
//	}
//	printf("\n");
//}
//
//int LenList(ListNode* c)
//{
//	int count = 0;
//	ListNode* p = c->next;
//	while (p != NULL)
//	{
//		count++;
//		p = p->next;
//	}
//	return count;
//}
//
//int Locate(ListNode* c, ElemType n)
//{
//	ListNode* p = c->next;
//	int count = 1;
//	while (p != NULL)
//	{
//		if (p->data == n)
//			return count;
//		else
//		{
//			p = p->next;
//			count++;
//		}
//	}
//	return 0;
//}
//
//void DestoryList(LinkList*& c)
//{
//	free(c);
//	printf("�ͷųɹ�\n");
//}
//
//void test()
//{
//	LinkList* head;
//	int e;
//	head = Initlist();
//	AddList(head, 1);
//	AddList(head, 2);
//	AddList(head, 3);
//	AddList(head, 4);
//	Printlist(head);
//	printf("%d\n", LenList(head));
//	printf("%d\n", Locate(head, 2));
//	AddList(head, 5);
//	Printlist(head);
//	DelList(head, 3, e);
//	Printlist(head);
//
//}
//
//void reverse(ListNode* c)
//{
//	LinkList* p = c->next;
//	LinkList* q = NULL;
//	while (q = p->next)
//	{
//		p->next = q->next;
//		q->next = c->next;
//		c->next = q;
//	}
//}
//
//int main()
//{
//	LinkList* head;
//	head = Initlist();
//	int control;
//	int nums,i,j,e;
//	printf("*******************************************\n");
//	printf("******-1.�˳�����**********1.��ӡ����******\n");
//	printf("******2.��������***********3.�������******\n");
//	printf("******4.��ֵ����***********5.ɾ������******\n");
//	printf("******6.�ͷ�����***********7.���ýڵ�******\n");
//	printf("*******************************************\n");
//	do 
//    {
//	    printf("��������Ĳ���ѡ�");
//	    scanf("%d", &control);
//	    switch (control)
//	    {
//	        case 1:
//	        {
//				Printlist(head);
//				break;
//	        }
//	        case 2:
//	        {
//	            printf("������Ҫ�����ֵ:");
//	            scanf("%d", &nums);
//				AddList(head, nums);            
//	            break;
//	        }
//			case 3:
//			{
//				printf("������ĳ���Ϊ%d\n", LenList(head));
//				break;
//			}
//			case 4:
//	        {
//	            printf("�������������Ԫ�صĴ�С��");
//	            scanf("%d", &i);
//	            printf("��Ԫ�ص�λ��Ϊ��%d\n", Locate(head, i));
//	            break;
//	        }
//			case 5:
//			{
//				printf("������Ҫɾ�����ݵ�λ�ã�");
//			    scanf("%d", &j);
//				DelList(head, j, e);
//				break;
//			}
//			case 6:
//			{
//				DestoryList(head);
//				break;
//			}
//			case 7:
//			{
//				reverse(head);
//				break;
//			}
//			case -1: 
//	        {
//	            printf("�˳��ɹ�");
//	            break;
//	        }
//	        default:
//	        {
//	            printf("ѡ�����������ѡ��\n");
//	            break;
//	        }
//	    }
//    } while (control != -1);
//	system("pause");
//	return 0;
//}


#include<stdio.h>
#include<stdlib.h>
typedef struct Listnode
{
	int data;
	struct Listnode* next;
}*LinkList, Listnode;
void Create(LinkList* L, int len)
{
	LinkList r;
	(*L) = (LinkList)malloc(sizeof(Listnode));
	r = (*L);
	if (!(*L)) exit(0);
	(*L)->next = (*L);
	LinkList s = NULL;
	for (int i = 0; i < len; i++)
	{

		s = (LinkList)malloc(sizeof(Listnode));
		if (!s) exit(0);
		int num;
		scanf("%d", &num);
		s->data = num;
		r->next = s;
		r = s;
	}
	s->next = (*L);
}

Listnode* Find(Listnode* L)
{
	Listnode* p = L->next;
	while (p->next != L)
	{
		p = p->next;
	}
	return p;
}

LinkList combine(LinkList L1, LinkList L2)
{
	LinkList r1, r2;
	LinkList p;
	r1 = Find(L1);
	r2 = Find(L2);
	p = r1->next;
	r1->next = r2->next->next;
	free(r2->next);
	r2->next = p;
	return L1;
}

void Print(Listnode* L)
{
	LinkList p = L->next;
	do
	{
		printf("%d\t", p->data);
		p = p->next;

	} while (p != L);
}

int main()
{
	LinkList L, L1, L2;
	int len1, len2;
	printf("�������һ��ѭ������ĳ��ȣ�");
	scanf("%d", &len1);
	Create(&L1, len1);
	printf("������ڶ���ѭ������ĳ��ȣ�");
	scanf("%d", &len2);
	Create(&L2, len2);
	printf("ѭ������1��");
	Print(L1);
	printf("\n");
	printf("ѭ������2��");
	Print(L2);
	printf("\n");
	L = combine(L1, L2);
	printf("�ϲ����ѭ������");
	Print(L);
	return 0;
}
