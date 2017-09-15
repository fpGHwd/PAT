#include "stdafx.h"
#include "Queue.h"

void InitQueue(SqQueue *&s)
{
	s->front = s->rear = 0;
}

void InitQueue(LinkQueue *&Q)
{
	LinkNode *n;
	n = (LinkNode *)malloc(sizeof(LinkNode));
	Q->front = Q->rear = n;
	Q->front->next = NULL;// forget
}

bool IsEmpty(SqQueue &s)
{
	return (s.rear == s.front);
}

bool IsEmpty(LinkQueue &Q)
{
	return (Q.rear == Q.front);
}

bool EnQueue(SqQueue *&s, ElemType x)
{
	if ((s->rear + 1) % MaxSize == s->front)
		return false;
	s->data[s->rear] = x;
	++s->rear %= MaxSize; // s->rear++; s->rear %= MaxSize
	return true;
}

bool EnQueue(LinkQueue *&Q, ElemType x)
{
	LinkNode *e = (LinkNode*)malloc(sizeof(LinkNode));
	e->data = x;
	e->next = NULL; // forget this sentence
	Q->rear->next = e;
	Q->rear = e;
}

bool DeQueue(SqQueue *&s, ElemType &x)
{
	if (s->front == s->rear)
		return false; // empty queue // also can use IsEmpty()
	x = s->data[s->front];
	++s->front %= MaxSize;
	return true;
}

bool DeQueue(LinkQueue *&Q, ElemType &x)
{
	LinkNode *n;
	if (Q->front == Q->rear)
		return false;
	x = Q->front->data;
	n = Q->front;
	Q->front = Q->front->next;
	free(n);
	return true;
}

