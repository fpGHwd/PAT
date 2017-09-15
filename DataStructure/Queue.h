#pragma once

#include "stdafx.h"

#define MaxSize 50

typedef int ElemType;

/*sequence queue*/
typedef struct{
	ElemType data[MaxSize];
	int front, rear;
}SqQueue;

void InitQueue(SqQueue *&s);
bool IsEmpty(SqQueue &s);
bool EnQueue(SqQueue *&s, ElemType x);
bool DeQueue(SqQueue *&s, ElemType &x);


/*link queue*/
typedef struct LinkNode {
	ElemType data;
	struct LinkNode *next;
}LinkNode;
typedef struct {
	LinkNode *front, *rear;
}LinkQueue;

void InitQueue(LinkQueue *&Q);
bool IsEmpty(LinkQueue &Q);
bool EnQueue(LinkQueue *&Q, ElemType x);
bool DeQueue(LinkQueue *&Q, ElemType &x);