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
	if (S->top >= MAXSIZE - 1) // or S->top == MAXSIZE -1
		return ERROR;
	else {
		S->data[++S->top] = e;
	}
	return OK;
}

Status Pop(SqStack *S, SElemType *e) {
	if (S->top == -1)
		return ERROR;
	else {
		*e = S->data[S->top--];
	}
	return OK;
}


// share stack
typedef struct {
	SElemType data[MAXSIZE];
	int top1;
	int top2;
}SqDoubleStack;

SqDoubleStack *doublestack;

typedef enum StackFlag {
	LEFT,
	RIGHT,
}StackFlag;

Status InitDoubleStack(SqDoubleStack *S); // todo: implement

// stackNumber
Status Push(SqDoubleStack *S, SElemType e, int stackNumber) // stackNumber?
{  // stackNumber 
	if (!(stackNumber == 1 || stackNumber == 2))
		return ERROR;
	if (S->top1 + 1 == S->top2)
		return ERROR;
	if (stackNumber = 1) {
		S->data[++S->top1] = e;
	}
	else if (stackNumber == 2) {
		S->data[--S->top2] == e;
	}
	
	return OK;
}

Status Pop(SqDoubleStack *S, SElemType *e, int stackNumber) {

	if (S->top1 == -1 || S->top2 == MAXSIZE)
		return ERROR;
	if (stackNumber == 1) {
		*e = S->data[S->top1--];
	}
	else if(stackNumber == 2) {
		*e = S->data[S->top2++];
	}
	return OK;
}

typedef struct StackNode {
	SElemType data;
	struct StackNode *next;
}StackNode , *LinkStackPtr;

typedef struct LinkStack {
	LinkStackPtr top;
	int count;
}LinkStack;

LinkStack *linkstack;
void InitLinkStack(LinkStack **linkstack) {
	*linkstack = (LinkStack *)malloc(sizeof(LinkStack));
	(*linkstack)->count = 0;
	(*linkstack)->top = NULL;
}

Status Push(LinkStack *L, SElemType e) {
	StackNode *n = (StackNode *)malloc(sizeof(StackNode));
	n->data = e;
	n->next = L->top;
	L->top = n;
	L->count++;
	return OK;
}

Status Pop(LinkStack *L, SElemType *e) {
	StackNode *n;
	if (L->count == -1) // the weakest condition to judge if popping is valid
		return ERROR;
	*e = L->top->data;
	n = L->top;
	L->top = n->next;
	free(n);
	L->count--;
	return OK;
}

static char *input = "9+(3-1)*3+10/2";
char* ReversePolishNotation(char* input) { // todo implementation

	return NULL;
}


int Fbi(int i) {
	if (i <= 2)
		return 1;
	return Fbi(i - 1) + Fbi(i - 2);
}

static int Array[10] = {1,2,3,4,5,6,7,8,9,10};
void TestStack(void) {
	int i;
	//SElemType e = 20;
	//InitStack(&stack);

	/*
	// test Push and Pop
	for (i = 10; i > 0; i--) {
		Push(stack, Array[i-1]);
	}
	while (i++<10)
		Pop(stack, &e);
	*/
	
	/*
	InitLinkStack(&linkstack);
	//Push(linkstack, e);
	for (i =0; i < 10; i++)
		Push(linkstack, Array[i]); // test OK
	for (i = 0; i < 10; i++)
		Pop(linkstack, &e); // test OK
	*/
	/*
	for (i = 1; i < 50; i++) {
		printf("%d ", Fbi(i));
	}*/
	//printf("Fbi(3) = %d\n", Fbi(10));
	//printf("Fbi(21)/Fbi(20) = %f\n", Fbi(21) / (Fbi(20) * 0.1));

	printf("\n");
	return;
}