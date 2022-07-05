#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 20

#define NULL 0
typedef char TElemType;
typedef int Status;
typedef struct BTNode
{
	TElemType data;
	struct BTNode* lchild, * rchild;
}BTNode;
Status CreateBiTree(BTNode*& T)
{
	char ch;
	ch = getchar();
	if (ch == '#') T = NULL;//#�����ָ��
	else
	{
		T = (BTNode*)malloc(sizeof(BTNode));
		T->data = ch;//���ɸ����
		CreateBiTree(T->lchild);//����������
		CreateBiTree(T->rchild);//����������
	}
	return 1;
}
///����������
void PreOrder(BTNode* T)
{
	if (T)
	{
		printf("%2c", T->data);///T->data==(*T).data
		PreOrder(T->lchild);///�������������
		PreOrder(T->rchild);///�������������
	}
}

///����������
void InOrder(BTNode* T)
{
	if (T)
	{
		InOrder(T->lchild);///�������������
		printf("%2c", T->data);
		InOrder(T->rchild);///�������������

	}
}
///����������
void Postorder(BTNode* T)
{
	if (T)
	{
		Postorder(T->lchild);///�������������
		Postorder(T->rchild);///�������������
		printf("%2c", T->data);///���ʸ����
	}
}
///��α���������T���ӵ�һ�㿪ʼ��ÿ�������
void LevleOrder(BTNode* T)
{
	BTNode* Queue[MAX] = { 0 };
	BTNode* b;
	///��һά�����ʾ���У�front��rear�ֱ��ʾ���׺Ͷ�βָ��
	int front, rear;
	front = rear = 0;
	if (T) ///�����ǿ�
	{
		Queue[rear++] = T;///����������
		while (front != rear) ///�����зǿ�
		{
			b = Queue[front++];///����Ԫ�س����У�������������
			printf("%2c", b->data);
			if (b->lchild != NULL)
			{
				Queue[rear++] = b->lchild;
				///�������ǿգ��������

			}
			if (b->rchild != NULL)
			{
				Queue[rear++] = b->rchild;
				///�������ǿգ��������
			}
		}
	}
}


///������������
int depth(BTNode* T) {
	int dep1, dep2;
	if (T == NULL)  return 0;
	else
	{
		dep1 = depth(T->lchild);
		dep2 = depth(T->rchild);
		return dep1 > dep2 ? dep1 + 1 : dep2 + 1;
	}
}


BTNode* Max(BTNode* T1, BTNode* T2)
{
	if (T1 == NULL)
		return T2;
	if (T2 == NULL)
		return T1;
	if (T1->data > T2->data)
		return T1;
	return T2;
}

BTNode* FindMax(BTNode* T)
{
	BTNode* rdata;
	BTNode* ldata;
	if (T == NULL)
		return T;
	ldata = FindMax(T->lchild);
	rdata = FindMax(T->rchild);
	return Max(T, Max(ldata, rdata));
}

//����˫�׽��
BTNode* FindParent(BTNode* T, char e)
{
	BTNode* p;
	if (T)
	{
		if (T->lchild && T->lchild->data == e 
			|| T->rchild && T->rchild->data == e)
			return T;
		p = FindParent(T->lchild, e);
		if (!p)  
			return FindParent(T->rchild, e);
	}
	else
		return NULL;
}
//���ƶ�����
void CopyTree(BTNode* T, BTNode*& NewT)
{
	if (T == NULL)
		NewT = NULL;
	else
	{
		NewT = (BTNode*)malloc(sizeof(BTNode));
		NewT->data = T->data;
		CopyTree(T->lchild, NewT->lchild);
		CopyTree(T->rchild, NewT->rchild);
	}
}
//������������е�һ������ָ��
BTNode* FindPoint(BTNode* T)
{
	while (T->lchild)
	{
		T = T->lchild;
	}
	return T;
}

int main()
{
	int max = 0;//���ֵ
	BTNode* T;//����ʼ�������*T����ʱTΪ��ַ
	printf("������Ϊ��");
	CreateBiTree(T);//����һ�ö�����
	/*printf("PrevOrder:");
	PreOrder(T);
	printf("\nInOrder:");
	InOrder(T);
	printf("\nPostorder:");
	Postorder(T);
	printf("\nLevelorder:");
	LevleOrder(T);
	printf("\nDepth:%d", depth(T));*/
	//printf("Max:%d", FindMax(T)->data-48);
	//getchar();
	//printf("������һ���Ǹ��ڵ㣺");
	////scanf("%c", &e);
	//char e;
	//e=getchar();
	//BTNode* k = Find(T, e);
	//if (k!=NULL)
	//	printf("����˫�׽ڵ�Ϊ%c", k->data);
	//else
	//	printf("�Ҳ���");
	/*BTNode* newT;
	CopyTree(T,newT);
	printf("NewTree(PreOrder)��");
	PreOrder(newT);*/ 
	printf("��һ������ָ��(Postorder)��%c", FindF(T)->data);
	//return 0;
}

//���룺124##5##36##7##