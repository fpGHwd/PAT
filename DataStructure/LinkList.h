#pragma once


// link list
typedef int ElemType;

typedef struct LinkNode {
	ElemType data;
	struct LinkNode *next;
};

