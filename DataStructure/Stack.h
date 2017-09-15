#pragma once

#include "stdafx.h"

#define MaxSize 50

typedef int ElemType;


/* Sequence Stack*/
typedef struct {
	ElemType data[MaxSize];
	int top;
}SqStack;

void TestSqStack(void);
void InitStack(SqStack *&s);
bool StackEmpty(SqStack *s);
bool Push(SqStack *&s, ElemType e);
bool Pop(SqStack *&s, ElemType &e);
bool GetTop(SqStack *&s, ElemType &e);


/*Link Stack*/
typedef struct LinkNode {
	ElemType data;
	struct LinkNode *next;
}LiStack;

void InitStack(LiStack *&s);
void DestroyStack(LiStack *&s);
bool StackEmpty(LiStack *s);
void Push(LiStack *&s, ElemType e);
bool Pop(LiStack *&s, ElemType &e);
bool GetTop(LiStack *s, ElemType &e);

// test program
bool Match(char exp[], int n);
