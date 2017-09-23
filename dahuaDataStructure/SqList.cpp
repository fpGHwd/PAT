#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 20
typedef int ElemType;
typedef struct {
	ElemType data[MAXSIZE];
	int length;
}SqList;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;

SqList *sq; // simple

void swap(int *a, int *b) {
	int tmp;

	tmp = *a;*a = *b;*b = tmp;
}

void test_swap(void) {
	int a = 2, b = 3;
	printf("before swap a(%d) and b(%d)\n", a, b);
	swap(&a, &b);
	printf("after swap a(%d) and b(%d)\n", a, b);
}

void InitSqList(SqList **sq) { // SqList * InitSqList(void);
	SqList *s = (SqList *)malloc(sizeof(SqList));
	int b[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
	int i;
	for (i = 0; i < 10; i++) {
		s->data[i] = b[i];
	}
	s->length = 10;
	*sq = s;
	//return s;
}

Status GetElem(SqList *L, int i, ElemType *e) {
	if (L->length == 0)
		return ERROR;
	if (i< 0 || i> L->length)
		return ERROR;
	*e = L->data[i - 1];
	return OK;
}

Status ListInsert(SqList *L, int i, ElemType e) {
	int k;
	if (L->length == MAXSIZE)
		return ERROR;
	if (i < 1 || i > L->length + 1)
		return ERROR;
	if (i > L->length) {
		L->data[L->length] = e;
		L->length++;
	}
	else {
		for (k = L->length - 1; k >= i - 1; k--) // k = length-1
			L->data[k+1] = L->data[k];
		L->data[i] = e; // k = i // merge with L->data[i - 1] = e
		L->length++;
	}

	return OK;
}

Status ListDelete(SqList *L, int i, ElemType *e) {
	int k;

	if (L->length == 0)
		return ERROR;
	if (i<1 || i> L->length)
		return ERROR;
	
	*e = L->data[i - 1];
	for (k = i; k < L->length; k++)
		L->data[k - 1] = L->data[k];
	L->length--; // if i = L->length, just L->length-- is ok

	return OK;
}

Status PrintSqList(SqList *L) {
	int i;

	printf("###print SqList elements:");
	for (i = 0; i < L->length; i++)
		printf("%d ", L->data[i]);
	printf("###\n");

	return OK;
}

typedef struct Node {
	ElemType data;
	struct Node *next;
}Node;
typedef struct Node *LinkList;

LinkList linklist;

Status PrintSqList(LinkList *L) {
	Node *p ;
	int k = 1;
	if (*L == NULL)
		return ERROR;
	p = (*L)->next; // FIX
	while (p!=NULL) {
		printf("%d - %d\n", k, p->data);
		p = p->next;k++;
	};
	return OK;
}

int GetLength(LinkList *L) {
	Node *p;
	int i = 0;
	p = (*L)->next;
	while (p) {
		p = p->next;
		i++;
	}
	return i;
}

Status GetElem(LinkList *L, int i, ElemType *e) {
	int j = 1;
	Node *p;
	if (i > GetLength(L) || i < 1)
		return ERROR;

	p = (*L)->next;
	while (p && j < i) {
		p = p->next; j++;
	}
	if (p == NULL || j > i)
		return ERROR;
	*e = p->data;
		
	return OK;
}

Status InitSqList(LinkList *L) {
	int b[10] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };
	int k = 10;
	Node *p;

	Node *n = (Node *)malloc(sizeof(Node));
	n->next = NULL;
	*L = n;

	p = *L;
	for (k = 0; k < 10; k++) {
		p->next = (Node*)malloc(sizeof(Node));
		p = p->next;
		p->data = b[k];
		p->next = NULL;
	}

	return OK;
}

Status ListInsert(LinkList *L, int i, ElemType e) {
	Node *p, *s;
	int j = 1;

	if (i > GetLength(L) || i < 1)
		return ERROR;
	//p = (*L)->next;
	p = (*L);

	while (p && j<i) {
		p = p->next;
		j++;
	}
	if (p == NULL || j > i)
		return ERROR;
	s = (Node*)malloc(sizeof(Node));
	s->data = e;
	s->next = p->next;
	p->next = s;

	return OK;
}

Status ListDelete(LinkList *L, int i, ElemType *e) {
	int j = 1;
	Node *p, *q;

	if (i< 1 || i> GetLength(L))
		return ERROR;
	if (L == NULL)
		return ERROR;
	p = *L;
	while (p->next && j < i) {
		p = p->next; j++;
	}
	
	if (!p->next || j> i)
		return ERROR;
	*e = p->next->data; // p is necessary
	q = p->next;
	p->next = p->next->next;
	free(q);
	/*
	q = p->next; // equivelent code // code on book
	*e = q->data;
	p->next = q->next;
	free(q);
	*/

	return OK;
}

void test_sqlist(void) {

	// initiate
	//test_swap();
	//InitSqList(&sq);
	
	// test GetElem
	/*
	int i;
	ElemType e;
	for (i = sq->length; i > 0; i--) {
		if (GetElem(sq, i, &e))
			printf("GetElem(sq, %d, &e):%d\n", i, e);
		else
			printf("failed to get the element\n");
	}*/

	// test ListInsert
	/*
	ElemType e = 6;
	PrintSqList(sq);
	srand((unsigned)time(NULL));
	ListInsert(sq, rand() % (sq->length) + 1, e);
	PrintSqList(sq);
	*/

	// test ListDelete
	/*
	ElemType e = -1;
	PrintSqList(sq);
	srand((unsigned)time(NULL));
	ListDelete(sq, rand() % (sq->length) + 1, &e);
	PrintSqList(sq);
	*/ // is ok

	// test LinkListInitiate
	InitSqList(&linklist);
	//PrintSqList(linklist); // test print link list
	//printf("length of the link list is %d\n", GetLength(linklist));// test length of the link list

	/*
	ElemType e = -1; // test list insert
	int index = -1;
	srand((unsigned)time(NULL));
	index = rand() % GetLength(&linklist) + 1;
	PrintSqList(&linklist);
	printf("insert index = %d\n", index);
	ListInsert(&linklist, index, e);
	PrintSqList(&linklist); // test ok

	index = rand() % GetLength(&linklist) + 1;
	PrintSqList(&linklist);
	printf("delete index = %d\n", index);
	ListDelete(&linklist, index, &e);
	printf("delete element = %d\n", e);
	PrintSqList(&linklist); // test ok
	*/

	printf("\n");
	system("pause");
}