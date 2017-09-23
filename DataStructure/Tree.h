#pragma once
#include "stdafx.h"
#include "Stack.h"

typedef int ElemType;

typedef struct BiTNode {
	ElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

void VisitNode(BiTNode *N); // visit the node
void PreOrder(BiTree T);
void InOrder(BiTree T);
void PostOrder(BiTree T);

SqStack S;
void InOrderNoneRecurrsion(BiTree T);

void LevelOrder(BiTree T);

/*thread bi-tree*/
typedef struct ThreadNode {
	ElemType data;
	struct ThreadNode *lchild, *rchild;
	int ltag, rtag;
}ThreadNode, *ThreadTree;

