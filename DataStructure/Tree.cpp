#include "stdafx.h"
#include "Tree.h"

void VisitNode(BiTNode *N)
{
	if (N = NULL)
		return;
	else
		printf("%d-", N->data);
}

void PreOrder(BiTree T)
{
	if (T != NULL) {
		VisitNode(T);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

void InOrder(BiTree T)
{
	if (T != NULL) {
		InOrder(T->lchild);
		VisitNode(T);
		InOrder(T->rchild);
	}
}

void PostOrder(BiTree T) {
	if (T != NULL) {
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		VisitNode(T);
	}
}

#include "Stack.h"
void InOrderNoneRecurrsion(BiTree T)
{
	InitStack(&S);
	BiTree p = T;

	/*
	if (p != NULL) {
		if (p->lchild) {
			if (p->lchild->lchild) {
				VisitNode(p->lchild);
			}
			VisitNode(p->lchild);
			if (p->rchild) {
				VisitNode(p->rchild);
			}
		}
		VisitNode(p);
		if (p->rchild) {
			VisitNode(p->rchild);
		}
	}
	*/

	// stack records the directory // not implement the pointer stack
	/* 
	while(p!=NULL && IsEmpty(&S)){
		if(!p){
			Push(&S, p);
			p->lchild;
		}else{
			Pop(S,p); visit(p);
			p = p->rchild;
		}
	}
	
	*/

}

void LevelOrder(BiTree T)
{
	InitQueue(Q);
	BiTree p;
	EnQueue(Q, T);

	while (!IsEmpty(Q)) {
		DeQueue(Q, p);
		VisitNode(p);
		if (p->lchild)
			EnQueue(Q, p->lchild);
		if (p->rchild)
			EnQueue(Q, p->rchild);
	}

	return;
}
