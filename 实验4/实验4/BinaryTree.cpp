#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define ElemType char
#define MaxSize 50

typedef struct BinaryTreeNode 
{
	ElemType data;
	struct BinaryTreeNode* lchild;
	struct BinaryTreeNode* rchild;
}BTNode;

void CreatBinaryTree(BTNode*& T, char* str) 
{
	BTNode* Tree[MaxSize], * p = NULL;
	int top = -1, tag, j = 0;
	char ch;
	T = NULL;
	ch = str[j];
	while (ch != '\0') 
	{
		switch (ch) 
		{
		case'(':
			top++;
			Tree[top] = p;
			tag = 1;
			break;
		case')':
			top--;
			break;
		case',':
			tag = 2;
			break;
		default:
			p = (BTNode*)malloc(sizeof(BTNode));
			p->data = ch;
			p->lchild = p->rchild = NULL;
			if (T == NULL)
				T = p;
			else 
			{
				switch (tag) 
				{
				case 1:
					Tree[top]->lchild = p;
					break;
				case 2:
					Tree[top]->rchild = p;
					break;
				}
			}
		}
		j++;
		ch = str[j];
	}
}

void VisiteNode(BTNode* T)
{
	if (T == NULL)
		printf("结点不存在。\n");
	else
		printf("%c ", T->data);
}

void PrintBinaryTree(BTNode* T, int level) 
{
	if (T != NULL) 
	{
		PrintBinaryTree(T->rchild, level + 1);
		if (level != 0)
		{
			for (int i = 0; i < 4 * (level - 1); i++)
				printf("%s", " ");
			printf("%s", " - - -");
		}
		VisiteNode(T);
		printf("\n");
		PrintBinaryTree(T->lchild, level + 1);
	}
}

int BinaryTreeDepth(BTNode* T) 
{
	int ld, rd;
	if (T == NULL)
		return 0;
	if (T->lchild)
		ld = BinaryTreeDepth(T->lchild);
	else
		ld = 0;
	if (T->rchild)
		rd = BinaryTreeDepth(T->rchild);
	else
		rd = 0;
	return (ld > rd) ? (ld + 1) : (rd + 1);
}

int Count(BTNode* T)
{
	if (T != NULL)
		return (Count(T->lchild) + Count(T->rchild) + 1);
	else
		return 0;
}

void InOrder(BTNode* T)
{
	if (T != NULL) 
	{
		InOrder(T->lchild);
		printf("%c ", T->data);
		InOrder(T->rchild);
	}
}

void LevelOrder(BTNode* T) 
{
	BTNode* p;
	BTNode* q[MaxSize];
	int front, rear;
	front = rear = -1;
	rear++;
	q[rear] = T;
	while (front != rear) 
	{
		front = (front + 1) % MaxSize;
		p = q[front];
		VisiteNode(p);
		if (p->lchild != NULL)
		{
			rear = (rear + 1) % MaxSize;
			q[rear] = p->lchild;
		}
		if (p->rchild != NULL)
		{
			rear = (rear + 1) % MaxSize;
			q[rear] = p->rchild;
		}
	}
}

bool IsCBiTree(BTNode* T)
{
	if (T == NULL)
		return true;
	int flag = 0;
	BTNode* p = NULL;
	BTNode* q[MaxSize];
	int front, rear;
	front = rear = 0;
	rear++;
	q[rear] = T;	
	while (front != rear) 
	{
		front++;
		p = q[front];
		if (!p) 
		{
			flag = 1;
			continue;
		}
		else if (flag)
			return false;
		else 
		{	
			q[rear] = p->lchild;
			rear++;
			q[rear] = p->rchild;
			rear++;
		}
	}
	return true;
}

int main() 
{
	BTNode* T;
	char str[] = "1(2,3(4(6,),5))";
	CreatBinaryTree(T, str);
	printf("横向打印二叉树：\n");
	PrintBinaryTree(T, 0);
	printf("二叉树高度为：%d\n", BinaryTreeDepth(T));
	printf("二叉树结点数为：%d\n", Count(T));
	printf("中序遍历序列为：");
	InOrder(T);
	printf("\n");
	printf("层序遍历序列为：");
	LevelOrder(T);
	printf("\n");
	if (IsCBiTree(T))
		printf("是完全二叉树。");
	else
		printf("不是完全二叉树。");
	return 0;
}
