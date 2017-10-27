#include "stdafx.h"
#include "Tree.h"

static BiTNode* binarytree;
// todo: move the string to create tree here

void InitATreeInParent(void)
{
	// todo: use a common expression of a array
}

// create a tree via "A(B(D(,G)),C(E,F))"
void CreateBTree(BiTNode *&b, char *str)
{
	char ch;
	int j = 0;
	int k = 1; // indicate if right node

	int top = -1;
	BiTNode *St[MaxSize], *p;

	ch = str[j];
	while (ch != '\0') { // a valid character
		switch(ch) {
		case '(': // in son domain
			k = 1;// reset k
			St[++top] = p;
			break;
		case ')': // out son domain
			top--;
			break;
		case ',': // has right child // if no right child, there is no ',' in the str
			k = 2;
			break;
		default: // a node character
			p = (BiTNode *)malloc(sizeof(BiTNode));// save a node in the first
			p->data = ch;
			p->lchild = p->rchild = NULL; // it's OK
			if (b == NULL) {
				b = p;
			}
			else { // if root node exists
				if (k == 1) {
					St[top]->lchild = p;
				}
				else if(k == 2) {
					St[top]->rchild = p;
				}
			}

			break;
	}
		ch = str[++j];
	}
}

void DestroyTree(BiTNode *&b)
{
	if (b == NULL)
		return;
	DestroyTree(b->lchild);
	DestroyTree(b->rchild);
	free(b);
}

// find a pointer in the tree with data(x)
BiTNode *FindNode(BiTNode *b, ElemType x) {
	BiTNode *p;

	if (b == NULL)
		return NULL;

	if (b->data == x)
		return b;
	else {
		p = FindNode(b->lchild, x);
		if (p != NULL)
			return p;
		else
			return FindNode(b->rchild, x);
	}
}

BiTNode * LchildNode(BiTNode *p)
{
	if (p == NULL)
		return NULL;
	else
		return p->lchild;
}

BiTNode * RchildNode(BiTNode *p)
{
	if (p == NULL)
		return NULL;
	else
		return p->rchild;
}

int BTHeight(BiTNode *b)
{
	int i,j;

	if (b == NULL)
		return 0;
	i = BTHeight(b->lchild);
	j = BTHeight(b->rchild);
	return (i > j) ? (i + 1) : (j + 1); // it's ok
}

void DispBTree(BiTNode *b) // it's not like code in textbook
{
	if (b != NULL)
		printf("%c", b->data);
	if (b->lchild != NULL || b->rchild != NULL) {
		printf("(");
		if(b->lchild) // b->lchild != NULL
			DispBTree(b->lchild);
		if (b->rchild) { // it should be b->rchild != NULL
			printf(",");
			DispBTree(b->rchild);
		}
		printf(")");
	}
}

void VisitNode(BiTNode *n)
{
	if(n!= NULL)
		printf("%c", n->data);
}

void PreOrder(BiTNode *b)
{
	if (b != NULL) {
		VisitNode(b);
		PreOrder(b->lchild);
		PreOrder(b->rchild);
	}
}

void InOrder(BiTNode *b)
{
	if (b != NULL) {
		InOrder(b->lchild);
		VisitNode(b);
		InOrder(b->rchild);
	}
}

void PostOrder(BiTNode *b) {
	if (b != NULL) {
		PostOrder(b->lchild);
		PostOrder(b->rchild);
		VisitNode(b);
	}
}

#include "Stack.h"
void InOrderNoneRecurrsion(BiTNode *b)
{
	InitStack(&S);
	BiTNode *p = b;

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

void LevelOrder(BiTNode *b)
{
	/*
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
	*/
}

// create a tree via "A(B(D(,G)),C(E,F))"
void test_create_tree(void) {
	char *treestr = "A(B(D(,G)),C(E,F))";
	CreateBTree(binarytree, treestr); // create a tree
									  //DestroyTree(binarytree); // destory a tree
	char findchar = 'E';
	BiTNode *p = FindNode(binarytree, findchar); // pointer value is correct 0x949fco for node 'E'
	int h = BTHeight(binarytree);// test height of the tree // the tree height is 4
	DispBTree(binarytree); // test ok
	printf("\n");
	printf("preorder traversal:\n");
	PreOrder(binarytree); // test 
	printf("\n");
	printf("inorder traversal:\n");
	InOrder(binarytree);
	printf("\n");
	printf("postorder traversal:\n");
	PostOrder(binarytree);
	printf("\n");
}
