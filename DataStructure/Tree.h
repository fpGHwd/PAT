#pragma once
#include "stdafx.h"
#include "Stack.h"

#define MaxSons 6

typedef int ElemType;

typedef struct {
	ElemType data; // node data
	int parent;
}PTree[MaxSize];

void InitATreeInParent(void);

// child chain storage structure
typedef struct node{
	ElemType data;
	struct node *sons[MaxSons];
}TSonNode;

// child brother chain storage structure
typedef struct ChildBrotherChainNode {
	ElemType data;
	struct ChildBrotherChainNode *hp; // sibling pointer
	struct ChildBrotherChainNode *hv; // child pointer
}TSBNode;

// 二叉树的链式存储结构
typedef struct BiTNode {
	ElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

void CreateBTree(BiTNode *&b, char *str);
void DestroyTree(BiTNode *&b);
BiTNode *FindNode(BiTNode *b, ElemType x);
BiTNode *LchildNode(BiTNode *p);
BiTNode *RchildNode(BiTNode *p);
int BTHeight(BiTNode *b);
void DispBTree(BiTNode *b);
void VisitNode(BiTNode *N); // visit the node
void PreOrder(BiTNode *b);
void InOrder(BiTNode *b);
void PostOrder(BiTNode *b);

SqStack S;
void InOrderNoneRecurrsion(BiTNode *b);
void LevelOrder(BiTNode *b);

/*thread bi-tree*/
typedef struct ThreadNode {
	ElemType data;
	struct ThreadNode *lchild, *rchild;
	int ltag, rtag;
}ThreadNode, *ThreadTree;

