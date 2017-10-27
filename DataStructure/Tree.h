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
int BTHeight(BiTNode *b);
void DispBTree(BiTNode *b);
void VisitNode(BiTNode *N); // visit the node
void PreOrder(BiTNode *b);
void InOrder(BiTNode *b);
void PostOrder(BiTNode *b);
BiTNode *FindNode(BiTNode *b, ElemType x);
BiTNode *LchildNode(BiTNode *p);
BiTNode *RchildNode(BiTNode *p);
int NodesSum(BiTNode *b);
void DispLeaf(BiTNode *b);
int NodeLevel(BiTNode *b, ElemType x, int h);
void Lnodenum(BiTNode *b, int h, int k, int &n); // todo: why this?
bool Like(BiTNode *b1, BiTNode *b2); // if tree appearance is the same
bool Ancestor(BiTNode *b, ElemType x);

SqStack S;
void InOrderNoneRecurrsion(BiTNode *b); // todo: 
void LevelOrder(BiTNode *b);
BiTNode* CreatBT1(char *pre, char *in, int n);

/*thread bi-tree*/
typedef struct ThreadNode {
	ElemType data;
	struct ThreadNode *lchild, *rchild;
	int ltag, rtag;
}ThreadNode, *ThreadTree;

