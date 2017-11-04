#pragma once

#define MaxSize 100

typedef int ElemType;

/*sequence list*/
typedef struct {
	ElemType data[MaxSize];
	int length;
}SqList; /* can also define this type via pointer */

#ifdef DYNAMIC_SQLIST
typedef struct {
	ElemType *data;
	int MaxSize, length;
}SeqList;
#endif

bool ListInsert(SqList *&L, int i, ElemType e);
bool ListDelete(SqList *&L, int i, ElemType e); // delete a element in a sequence list
int LocalElem(SqList *L, ElemType e); 
bool DeleteReconstruct(SqList *&L, ElemType e); // compare with element type and reconstruct the sequence/(T(n) = n; S(n) = 1);


/*link list*/
typedef struct LinkNode{
	ElemType data;
	struct LinkNode *next;
}LinkNode, *LinkList;

LinkList CreateListHeadInsert(LinkList &L);
LinkList CreateListTailInsert(LinkList &L);
LinkNode *GetElem(LinkList L, int i);
LinkNode *LocateElem(LinkList L, ElemType e); // locate a element and return the element
bool InsertElem(LinkList &L, int i, ElemType e);
bool DeleteElem(LinkList &L, int i, ElemType e);
bool DeleteElem_v2(LinkList &L, int i, ElemType e);
int ListLength(LinkList L);


/*dual link list*/
typedef struct DNode {
	ElemType data;
	struct DNode *prior, *next;
}DNode, *DLinkList;

DLinkList CreateListHeadInsert(DLinkList &L);
DLinkList CreateListTailInsert(DLinkList &L);
DNode *GetElem(DLinkList L, int i);
bool InsertElem(DLinkList &L, int i, ElemType e);
bool DeleteElem(DLinkList &L, int i, ElemType e);
bool ListInsert(DLinkList &L, int i, ElemType e);
bool ListDelete(DLinkList &L, int i, ElemType e); // delete a element in a sequence list
int LocalElem(DLinkList L, ElemType e);
