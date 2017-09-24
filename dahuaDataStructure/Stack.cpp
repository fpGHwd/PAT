#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>

#define MAXSIZE 20 //

typedef int SElemType; // 
typedef struct {
	SElemType data[MAXSIZE];
	int top;
}SqStack;

SqStack *stack;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;

void InitStack(SqStack **S)
{
	*S = (SqStack*)malloc(sizeof(SqStack));
	(*S)->top = -1;
}

Status PrintStack(SqStack *S) {
	int i;

	if (S->top == -1)
		return ERROR;
	else {
		for (i = S->top; i < 0; i--) // top + 1 is the number of the elements
			printf("%d ", i);
	}
}

Status Push(SqStack *S, SElemType e) {
	if (S->top > MAXSIZE - 1)
		return ERROR;
	else {
		S->data[++S->top] = e;
	}
	return OK;
}

int Array[10] = { 1,2,3,4,5,6,7,8,9,10 };

void TestStack(void) {
	int i;
	InitStack(&stack);
	for (i = 10; i > 0; i--) {
		Push(stack, Array[i-1]);
	}

	printf("\n");
	return;
}
