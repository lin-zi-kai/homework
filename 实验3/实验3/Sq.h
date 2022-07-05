#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct
{
	int* a;
	int front;
	int tail;
	int k;
}CircularQueue;

typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;		// Õ»¶¥
	int capacity;	// ÈÝÁ¿
}ST;

bool CircularQueueIsEmpty(CircularQueue* obj);
bool CircularQueueIsFull(CircularQueue* obj);
CircularQueue* CircularQueueCreate(int k);
bool CircularQueueEnQueue(CircularQueue* obj, int value);
bool CircularQueueDeQueue(CircularQueue* obj);
int CircularQueueFront(CircularQueue* obj);
int  CircularQueueRear(CircularQueue* obj);
bool CircularQueueIsEmpty(CircularQueue* obj);
bool CircularQueueIsFull(CircularQueue* obj);
void CircularQueueFree(CircularQueue* obj);

void StackInit(ST* ps);
void StackDestory(ST* ps);
void StackPush(ST* ps, STDataType x);
void StackPop(ST* ps);
bool StackEmpty(ST* ps);
STDataType StackTop(ST* ps);
int StackSize(ST* ps);
void OctToBin(ST* ps, int n);



