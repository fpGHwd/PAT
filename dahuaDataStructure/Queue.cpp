#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;

#define MAXSIZE 20

typedef int QElemType;
typedef struct {
	QElemType data[MAXSIZE];
	int front;
	int rear;
}SqQueue;

SqQueue *sqqueue;

Status InitQueue(SqQueue **Q) {
	*Q = (SqQueue *)malloc(sizeof(SqQueue));
	(*Q)->front = 0;
	(*Q)->rear = 0;
	return OK;
}

int QueueLength(SqQueue *Q) {
	return (Q->rear - Q->front + MAXSIZE) % MAXSIZE;
}

Status EnQueue(SqQueue *Q, QElemType e) {
	if ((Q->rear + 1) % MAXSIZE == Q->front) // full queue
		return ERROR;
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;

	return OK;
}

Status DeQueue(SqQueue *Q, QElemType *e) {
	if (Q->rear == Q->front)
		return ERROR;
	//*e = Q->data[(Q->rear - 1 + MAXSIZE) % MAXSIZE];
	*e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	return OK;
}

typedef struct QNode {
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct {
	QueuePtr front, rear;
}LinkQueue;

static LinkQueue *linkqueue;

void InitQueue(LinkQueue **L) {
	*L = (LinkQueue*)malloc(sizeof(LinkQueue));
	(*L)->front = (*L)->rear = NULL;
}

bool QueueEmpty(LinkQueue *L) { // forget and cause problem
	if (L->rear == NULL && L->front == NULL)
		return true;
	else
		return false;
	// return L->rear == NULL && L->front == NULL;
}

Status EnQueue(LinkQueue *L, QElemType e) {
	QNode *p, *n;

	n = (QNode *)malloc(sizeof(QNode));
	if (n == NULL)
		return ERROR; 
	n->data = e;
	n->next = NULL; // set node


	if (L->front == NULL && L->rear == NULL)
		L->rear = L->front = n;
	else {
		L->rear->next = n;
		L->rear = n;
	}


	/*
	if (L->rear)
		L->front = L->rear->next = n; */
	//L->rear = n;

	return OK;
}

Status DeQueue(LinkQueue *L, QElemType *e) {
	QNode *p;

	if (L->front == NULL && L->rear == NULL) // weak condition judgment
		return ERROR;

	*e = L->front->data;
	p = L->front;
	if (L->front == L->rear)
		L->front = L->rear = NULL;
	else
		L->front = p->next;

	free(p);

	return OK;
}


static int Array[10] = { 1,2,3,4,5,6,7,8,9,10 };
void QueueTest(void) { 
	int i;
	QElemType e;

	/*
	// test initiate sqqueue and dequeue and enqueue
	InitQueue(&sqqueue);
	for (i = 0; i < 5; i++)
		EnQueue(sqqueue, Array[i]);
	DeQueue(sqqueue, &e); 
	DeQueue(sqqueue, &e);
	for (i = 5; i < 10; i++)
		EnQueue(sqqueue, Array[i]);
	DeQueue(sqqueue, &e);
	DeQueue(sqqueue, &e); // test OK
	*/

	// test linkqueue 
	/*
	InitQueue(&linkqueue); // fixed: not success 20170925-12:15
	for (i = 0; i < 5; i++)
		EnQueue(linkqueue, Array[i]);
	DeQueue(linkqueue, &e);
	DeQueue(linkqueue, &e);
	DeQueue(linkqueue, &e);
	DeQueue(linkqueue, &e);
	DeQueue(linkqueue, &e);
	DeQueue(linkqueue, &e); // EMPTY THE QUEUE
	for (i = 5; i < 10; i++)
		EnQueue(linkqueue, Array[i]);
	DeQueue(linkqueue, &e);
	DeQueue(linkqueue, &e);
	*/

	printf("\n");
}

