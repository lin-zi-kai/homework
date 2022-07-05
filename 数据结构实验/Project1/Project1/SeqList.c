#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MaxSize 50

typedef char DataType;

typedef struct SeqList
{
    DataType* data;
    int length;
}SeqList;

void CreateList(SeqList* L)
{
    L->data = (DataType*)malloc(sizeof(DataType) * MaxSize);
    for (int i = 0; i < MaxSize; i++)
    {
        L->data[i] =' ';
    }
    L->length = 0;
    printf("请输入顺序表的长度：");
    scanf("%d", &L->length);
    printf("请输入顺序表的元素：\n");
    for (int i = 0; i < L->length; i++)
    {
        rewind(stdin);
        scanf("%c", &L->data[i]);   
    }
    printf("创建成功\n");
}

char GetElemLocate(SeqList* L, int i)
{
    return L->data[i - 1];
}


int GetElemNum(SeqList* L, char e)
{
    for (int i = 0; i < L->length; i++)
    {
        if (L->data[i] == e)
            return i + 1;
    }
    return 0;
}

void InsertNum(SeqList* L, int i, int e)
{
    int j = 0;
    if (i<1 || i>L->length+1)
    {
        printf("插入位置错误\n");
        return;
    }
    if (L->length > MaxSize)
    {
        printf("插入位置错误\n");
        return;
    }
    for (int j = L->length; j >= i; j--)
    {
        L->data[j] = L->data[j - 1];
    }
    L->data[i - 1] = e;
    L->length++;
    printf("插入成功\n");
}

int DeleteNum(SeqList* L, int i)
{
    int j = 0;
    int k = 0;
    if (i<1 || i>L->length)
    {
        printf("删除位置错误\n");
        return 0;
    }
    if (L->length > MaxSize)
    {
        printf("删除位置错误\n");
        return 0;
    }
    k = L->data[i];
    for (j = i; j < L->length; j++)
        L->data[j - 1] = L->data[j];
    L->length--;
    printf("删除成功\n");
    return k;
}

void DestoryList(SeqList* L)
{
    if (L->data)
        L->data = NULL;
    L->length = 0;
    printf("销毁成功\n");
}

int ListLength(SeqList* L)
{
    return (L->length);
}

bool ListEmpty(SeqList* L)
{
    return(L->length == 0);
}

void ListPrint(SeqList* L)
{
    for (int i = 0; i < L->length; i++)
    {
        printf("%c ", L->data[i]);
    }
    printf("\n");
}

//int main()
//{
//    SeqList L;
//    CreateList(&L);
//    ListPrint(&L);
//    printf("顺序表的长度为%d\n", ListLength(&L));
//    if (!ListEmpty(&L))
//        printf("顺序表不为空");
//    else
//        printf("顺序表为空");
//    printf("%c\n", GetElemLocate(&L, 3));
//    printf("%d\n", GetElemNum(&L, 'a'));
//    InsertNum(&L, 4, 'f');
//    ListPrint(&L);
//    DeleteNum(&L, 3);
//    ListPrint(&L);
//    DestoryList(&L);
//    return 0;
//}

//int main()
//{
//    SeqList L;
//    printf("*******************************************\n");
//    printf("*****1.创建顺序表*********2.打印顺序表*****\n");
//    printf("*****3.按值查找***********4.按位查找*******\n");
//    printf("*****5.插入数据***********6.删除数据*******\n");
//    printf("*****7.输出长度***********8.释放顺序表*****\n");
//    printf("*****9.是否为空**********-1.退出程序*******\n");
//    printf("*******************************************\n");
//    int control;
//    char nums;
//    int i, inlocate, dellocate;
//    DataType innum;
//    do {
//        printf("请输入你的操作选项：");
//        scanf("%d", &control);
//        switch (control)
//        {
//        case 1:
//        {
//            CreateList(&L);
//            break;
//        }
//        case 2:
//        {
//            for (int i = 0; i < L.length; i++)
//            {
//                printf("%c ", L.data[i]);
//            }
//            printf("\n");
//            break;
//        }
//        case 3:
//        {
//            printf("请输入所需查找的值:");
//            rewind(stdin);
//            scanf("%c", &nums);
//            printf("该值对应的逻辑位置为%d\n", GetElemNum(&L, nums));
//            break;
//        }
//        case 4:
//        {
//            printf("请输入所需查找内容的序号:");
//            scanf("%d", &i);
//            printf("该序号对应的内容为：%c\n", GetElemLocate(&L, i));
//            break;
//        }
//        case 5:
//        {
//            printf("请输入插入位置:");
//            scanf("%d", &inlocate);
//            printf("请输入插入的内容:");
//            rewind(stdin);
//            scanf("%c", &innum);
//            InsertNum(&L, inlocate, innum);
//            break;
//        }
//        case 6:
//        {
//            printf("请输入所需删除数据的位置:");
//            scanf("%d", &dellocate);
//            DeleteNum(&L, dellocate);
//            break;
//        }
//        case 7:
//        {
//            printf("顺序表的长度为%d\n", ListLength(&L));
//            break;
//        }
//        case 8:
//        {
//            DestoryList(&L);
//            break;
//        }
//        case 9:
//        {
//            int ret = ListLength(&L);
//            if (ret == 0)
//                printf("顺序表为空。\n");
//            else
//                printf("顺序表不为空。\n");
//            break;
//        }
//        case -1:
//        {
//            printf("退出成功\n");
//            break;
//        }
//        default:
//        {
//            printf("选择错误，请重新选择\n");
//            break;
//        }
//        }
//    } while (control != -1);
//    return 0;
//}
//
//void sort(SeqList* L,int m,int n)
//{
//    int str1 = 0;
//    int str2 = m;
//    char tmp;
//    while (str1 < m - 1 )
//    {
//        while (str2 < m + n )
//        {
//            while (L->data[str1] <= L->data[str2])
//                str1++;
//            tmp = L->data[str2];
//            int str3 = str2;
//            int str4 = str2 - 1;
//            while (str3 > str1)
//            {
//                L->data[str3--] = L->data[str4--];
//            }
//            L->data[str1] = tmp;
//            str1++;
//            str2++;
//        }      
//    }
//}

//int main()
//{
//    SeqList l;
//    CreateList(&l);
//    ListPrint(&l);
//    sort(&l, 3, 3);
//    ListPrint(&l);
//    return 0;
//}


void Union(SeqList La, SeqList Lb, SeqList* Lc)
{
    for (int i = 0; i < La.length; i++)
    {
        for (int j = 0; j < Lb.length; j++)
        {
            rewind(stdin);
            if (La.data[i] == Lb.data[j])
            {
                Lc->data[Lc->length] = La.data[i];
                Lc->length++;
                break;
            }
        }
    }
    for (int i = 0; i < Lc->length; i++)
    {
        printf("%c ", Lc->data[i]);
    }
}

int main()
{
    SeqList La;
    SeqList Lb;
    SeqList Lc;
    Lc.data = (DataType*)malloc(sizeof(DataType) * MaxSize);
    for (int i = 0; i < MaxSize; i++)
    {
        Lc.data[i] = ' ';
    }
    Lc.length = 0;
    CreateList(&La);
    CreateList(&Lb); 
    Union(La, Lb, &Lc);
    return 0;
}
