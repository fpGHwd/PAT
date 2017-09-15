#include "stdafx.h"
#include "SqList.h"

bool ListInsert(SqList *&L, int i, ElemType e)
{
	int j;

	if (i < 1 || i > L->length + 1)
		return false;	// argument error return false
	if (L->length >= MaxSize)
		return false;

	for (j = L->length; j > i; j--)		// move the elements
		L->data[j] = L->data[j - 1];

	L->data[i-1] = e;	// insert element e // turn the logic-index to the physic-index
	L->length++;		// sequence list length add 1
	return true;		// insert success and return true
}

bool ListInsert(DLinkList &L, int i, ElemType e)
{
	return NULL;
}

bool ListDelete(SqList *&L, int i, ElemType e)
{
	int j;

	if (i < 1 || i > L->length)
		return false;

	e = L->data[i-1];
	for (j = i; j < L->length - 1; j++)
		L->data[j] = L->data[j + 1];
	L->length--;

	return true;
}

bool ListDelete(DLinkList &L, int i, ElemType e)
{
	return NULL;
}

int LocalElem(SqList *L, ElemType e) // logic index is 1 to L->length
{
	int i;
	for (i = 0; i < L->length; i++) {
		if (L->data[i] == e)
			return i;
	}
	return 0;
}

int LocalElem(DLinkList L, ElemType e)
{
	return NULL;
}

bool DeleteReconstruct(SqList *&L, ElemType e) {
	int index_available = 0, i;

	if (L == NULL)
		return false;

	for (i = 0; i < L->length; i++)
	{
		if (L->data[i] != e) {
			L->data[index_available] = L->data[i];
			index_available++;
		}
	}
	L->length = index_available; // set the sequence list length to index_available(actually the same).
								 // need: T(n) = O(n), S(n) = O(1)
								 // new sequence list T(n) = n*n, does not match the need.
	return true;
}

LinkList CreateListHeadInsert(LinkList &L)
{
	LinkNode *s; int x;
	L = (LinkList)malloc(sizeof(LinkNode));
	
	scanf_s("%d", &x);
	while (x >= 1000) {
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf_s("%d", &x);
	}
	return L;
}

DLinkList CreateListHeadInsert(DLinkList &L)
{
	return NULL;
}

LinkList CreateListTailInsert(LinkList &L)
{
	return L;
}

DLinkList CreateListTailInsert(DLinkList &L)
{
	return NULL;
}

LinkNode* GetElem(LinkList L, int i)
{
	LinkNode *p; int j = 1;

	if (i == 0)
		return L;
	if (i < 1)
		return NULL;

	p = L->next;
	while ( p && j < i) {
		p = p -> next;
		j++;
	}
	return p; // if j > list.length, return null;
}

DNode* GetElem(DLinkList L, int i)
{
	DNode *p; int j = 1;
	if (i == 0)
		return L;
	if (i < 1)
		return NULL;
	p = L->next;
	while (p != NULL && j < i) {
		p = p->next;
		j++;
	}
	return p; // if j > list length , return null,(P is null)
}

LinkNode *LocateElem(LinkList L, ElemType e)
{
	LinkNode *p = L->next;

	while (p != NULL && p->data != e)
		p = p->next;

	return p;
}

bool InsertElem(LinkList &L, int i, ElemType e) // i is logic index
{
	LinkNode *p;
	LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
	s->data = e;
	p = GetElem(L, i - 1);
	if (p == NULL || p->next == NULL)
		return false;
	s->next = p->next;
	p->next = s;

	return true;
}

bool InsertElem(DLinkList &L, int i, ElemType e)
{
	DNode *p, *s;
	p = GetElem(L, i - 1);
	if (p = NULL)
		return false;
	s = (DNode *)malloc(sizeof(DNode));
	s->data = e;
	s->next = p->next;
	s->prior = p;
	p->next->prior = s;
	p->next = s;
	return true;
}

bool DeleteElem(LinkList &L, int i, ElemType e)
{
	LinkNode *p, *q;
	p = GetElem(L, i - 1);
	if (p == NULL)
		return false;
	q = p->next;
	p->next = q->next;
	free(q);
	return true;
}

bool DeleteElem(DLinkList &L, int i, ElemType e)
{
	LinkNode *p, *q;

	return false;
}

bool DeleteElem_v2(LinkList &L, int i, ElemType e)
{
	LinkNode *p, *q;
	p = GetElem(L, i);
	if (p == NULL)
		return false;
	q = p->next;
	p->data = q->data;
	p->next = q->next;
	free(q);
}

int ListLength(LinkList L)
{
	int i = 0;
	LinkNode *p = L->next;
	while (p != NULL)
		p = p->next;
	return i;
}

