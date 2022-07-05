#define LENTH 5 
#include "Sq.h"

CircularQueue* CircularQueueCreate(int k)
{
	CircularQueue* obj = (CircularQueue*)malloc(sizeof(CircularQueue));
	obj->a = (int*)malloc(sizeof(int) * (k + 1));
	obj->front = obj->tail = 0;
	obj->k = k;
	return obj;
}

bool CircularQueueEnQueue(CircularQueue* obj, int value)
{
	if (CircularQueueIsFull(obj))
		return false;
	obj->a[obj->tail] = value;
	if (obj->tail == obj->k)
		obj->tail = 0;
	else
		obj->tail++;
	return true;
}

bool CircularQueueDeQueue(CircularQueue* obj)
{
	if (CircularQueueIsEmpty(obj))
		return false;
	if (obj->front == obj->k)
		obj->front = 0;
	else
		obj->front++;
	return true;
}

int CircularQueueFront(CircularQueue* obj)
{
	if (CircularQueueIsEmpty(obj))
		return -1;
	return obj->a[obj->front];
}

int  CircularQueueRear(CircularQueue* obj)
{
	if (CircularQueueIsEmpty(obj))
		return -1;
	if (obj->tail == 0)
		return obj->a[obj->k];
	else
		return obj->a[obj->tail - 1];
}

bool CircularQueueIsEmpty(CircularQueue* obj)
{
	return obj->front == obj->tail;
}

bool CircularQueueIsFull(CircularQueue* obj)
{
	if (obj->tail == obj->k && obj->front == 0)
		return true;
	else
		return obj->tail + 1 == obj->front;
}

void CircularQueueFree(CircularQueue* obj)
{
	free(obj->a);
	free(obj);
}

//int main()
//{
//	CircularQueue* obj = CircularQueueCreate(LENTH);
//	if (!CircularQueueIsEmpty(obj))
//		printf("队列不为空\n");
//	else
//		printf("队列为空\n");
//	CircularQueueEnQueue(obj, 1);
//	if (!CircularQueueIsEmpty(obj))
//		printf("队列不为空\n");
//	else
//		printf("队列为空\n");
//	CircularQueueEnQueue(obj, 2);
//	CircularQueueEnQueue(obj, 3);
//	if (!CircularQueueIsFull(obj))
//		printf("队列不为满\n");
//	else
//		printf("队列为满\n");
//	CircularQueueEnQueue(obj, 4);
//	CircularQueueEnQueue(obj, 5);
//	if (!CircularQueueIsFull(obj))
//		printf("队列不为满\n");
//	else
//		printf("队列为满\n");
//	printf("%d\n", CircularQueueFront(obj));
//	printf("%d\n", CircularQueueRear(obj));
//	CircularQueueDeQueue(obj);
//	CircularQueueDeQueue(obj);
//	printf("%d\n", CircularQueueFront(obj));
//	CircularQueueFree(obj);
//	return 0;
//}