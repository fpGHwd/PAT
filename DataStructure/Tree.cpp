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

int NodesSum(BiTNode *b)
{
	if (b == NULL)
		return 0;
	else
		return NodesSum(b->lchild) + 1 + NodesSum(b->rchild);
}

void DispLeaf(BiTNode *b)
{
	if (b == NULL)
		return;
	if (b->lchild == NULL && b->rchild == NULL)
		VisitNode(b);
	DispLeaf(b->lchild);
	DispLeaf(b->rchild);

}

int NodeLevel(BiTNode *b, ElemType x, int h)
{
	int l;

	if (b == NULL)
		return 0; // ?
	if (b->data == x)
		return h;
	else {
		l = NodeLevel(b->lchild, x, h + 1);
		if (l != 0)
			return l;
		else
			return NodeLevel(b->rchild, x, h + 1);
	}
}

void Lnodenum(BiTNode *b, int h, int k, int &n)
{
	if (b == NULL)
		return;
	else {
		if (h == k) n++;
		else if (h < k) {
			Lnodenum(b->lchild, h + 1, k, n);
			Lnodenum(b->rchild, h + 1, k, n);
		}
	}
}

bool Like(BiTNode *b1, BiTNode *b2)
{
	if (b1 == NULL && b2 == NULL)
		return true;
	else if (b1 == NULL || b2 == NULL)
		return false;
	else {
		return (Like(b1->lchild, b2->lchild) && Like(b1->rchild, b2->rchild));
	}
}

bool Ancestor(BiTNode *b, ElemType x)
{
	if (b == NULL)
		return false;
	else if ((b->lchild != NULL && b->lchild->data == x) || (b->rchild != NULL && b->rchild->data == x)) {
		printf("%c", b->data);
		return true;
	}
	else if (Ancestor(b->lchild, x) || Ancestor(b->rchild, x)) {
		printf("%c", b->data);
		return true;
	}
	else
		return false;
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

typedef struct {
	BiTNode *data[MaxSize];
	int front, rear;
}SqQueue;

void InitQueue(SqQueue &qu) {
	
	qu.front = 0;
	qu.rear = 0;
}

bool QueueEmpty(SqQueue qu) {
	if (qu.front == qu.rear)
		return true;
	else
		return false;
}

bool QueueFull(SqQueue qu) {
	if((qu.rear+1)%MaxSize == qu.front)//if ((qu.front + 1) % MaxSize == qu.rear) 
		return true;
	else 
		return false;
}

void Enqueue(SqQueue &qu, BiTNode *n) {
	if (!QueueFull(qu)) {
		qu.data[qu.rear] = n;
		qu.rear = (qu.rear + 1) % MaxSize;
	}
	else
		return;
}

void Dequeue(SqQueue &qu, BiTNode *&n) {
	if (!QueueEmpty(qu)) {
		n = qu.data[(qu.front)];
		qu.front = (qu.front + 1) % MaxSize;// qu.front == (qu.front + 1) % MaxSize;
	}
}

void LevelOrder(BiTNode *b)
{
	SqQueue qu;
	BiTNode *p;
	
	InitQueue(qu);
	if (b == NULL) // not necessary
		return;
	Enqueue(qu, b);
	
	while (!QueueEmpty(qu)) { // condition for common loop
		Dequeue(qu, p);
		printf("%c", p->data); // this is the core
		if (p->lchild != NULL)
			Enqueue(qu, p->lchild);
		if (p->rchild != NULL)
			Enqueue(qu, p->rchild);
	}
}

// pre = ABDGCEF // in = DGBAECF
BiTNode* CreatBT1(char *pre, char *in, int n)
{
	int k;
	char *ch;
	BiTNode *b;

	if (n <= 0)
		return NULL;
	else
		b = (BiTNode*)malloc(sizeof(BiTNode));
	b->data = *pre;
	for (k = 0; k < n; k++) { // why cannot: for(k = 0; k<n; k++)if(*(in + k) == b->data)break;
		if ((*(in + k)) == b->data)
			break;
	}
	b->lchild = CreatBT1(pre + 1, in, k);
	b->rchild = CreatBT1(pre + k + 1, in + k + 1, n - k - 1);
	
}

// create a tree via "A(B(D(,G)),C(E,F))"
void test_create_tree(void) {
	char *treestr = "A(B(D(,G)),C(E,F))";
	CreateBTree(binarytree, treestr); // create a tree

	/*
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
	*/

	/*
	int num = NodesSum(binarytree);// test number sum // test ok // result: 7
	DispLeaf(binarytree);// display leaf nodes // result: GEF
	int l = NodeLevel(binarytree, 'E', 1); // 3
	l = NodeLevel(binarytree, 'A', 1); // 1
	l = NodeLevel(binarytree, 'D', 1); // 3
	l = NodeLevel(binarytree, 'G', 1); // 4

	int n = 0;
	Lnodenum(binarytree, 1, 1, n); // 1
	printf("n = %d\n", n);
	n = 0;
	Lnodenum(binarytree, 1, 2, n); // 2
	printf("n = %d\n", n);
	n = 0;
	Lnodenum(binarytree, 1, 3, n); // 3
	printf("n = %d\n", n);
	n = 0;
	Lnodenum(binarytree, 1, 4, n); // 1
	printf("n = %d\n", n);

	Ancestor(binarytree, 'G'); // DBA
	printf("\n", n);

	LevelOrder(binarytree); // ABCDEFG ok
	printf("\n", n);
	*/

	// test creattree1
	char *pre = "ABDGCEF"; // 
	char *in = "DGBAECF";
	BiTNode *b = CreatBT1(pre, in, 7);

}
