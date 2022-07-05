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
	if (ch == '#') T = NULL;//#代表空指针
	else
	{
		T = (BTNode*)malloc(sizeof(BTNode));
		T->data = ch;//生成根结点
		CreateBiTree(T->lchild);//构造左子树
		CreateBiTree(T->rchild);//构造右子树
	}
	return 1;
}
///先序遍历输出
void PreOrder(BTNode* T)
{
	if (T)
	{
		printf("%2c", T->data);///T->data==(*T).data
		PreOrder(T->lchild);///先序遍历左子树
		PreOrder(T->rchild);///先序遍历右子树
	}
}

///中序遍历输出
void InOrder(BTNode* T)
{
	if (T)
	{
		InOrder(T->lchild);///中序遍历左子树
		printf("%2c", T->data);
		InOrder(T->rchild);///中序遍历右子树

	}
}
///后序遍历输出
void Postorder(BTNode* T)
{
	if (T)
	{
		Postorder(T->lchild);///后序遍历左子树
		Postorder(T->rchild);///后序遍历右子树
		printf("%2c", T->data);///访问根结点
	}
}
///层次遍历二叉树T，从第一层开始，每层从左到右
void LevleOrder(BTNode* T)
{
	BTNode* Queue[MAX] = { 0 };
	BTNode* b;
	///用一维数组表示队列，front和rear分别表示队首和队尾指针
	int front, rear;
	front = rear = 0;
	if (T) ///若树非空
	{
		Queue[rear++] = T;///根结点入队列
		while (front != rear) ///当队列非空
		{
			b = Queue[front++];///队首元素出队列，并访问这个结点
			printf("%2c", b->data);
			if (b->lchild != NULL)
			{
				Queue[rear++] = b->lchild;
				///左子树非空，则入队列

			}
			if (b->rchild != NULL)
			{
				Queue[rear++] = b->rchild;
				///右子树非空，则入队列
			}
		}
	}
}


///求二叉树的深度
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

//查找双亲结点
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
//复制二叉树
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
//后序遍历序列中第一个结点的指针
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
	int max = 0;//最大值
	BTNode* T;//（开始定义的是*T）此时T为地址
	printf("二叉树为：");
	CreateBiTree(T);//建立一棵二叉树
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
	//printf("请输入一个非根节点：");
	////scanf("%c", &e);
	//char e;
	//e=getchar();
	//BTNode* k = Find(T, e);
	//if (k!=NULL)
	//	printf("它的双亲节点为%c", k->data);
	//else
	//	printf("找不到");
	/*BTNode* newT;
	CopyTree(T,newT);
	printf("NewTree(PreOrder)：");
	PreOrder(newT);*/ 
	printf("第一个结点的指针(Postorder)：%c", FindF(T)->data);
	//return 0;
}

//输入：124##5##36##7##