#pragma once

#include "stdafx.h"

typedef int ElemType;

typedef struct node {
	ElemType data; // node data
	int ltag, rtag; // tag for thread
	struct node *lchild; // pointer of left child or thread
	struct node *rchild; // pointer of right child or thread
}TBTNode;
