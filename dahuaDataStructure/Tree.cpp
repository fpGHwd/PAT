#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX_TREE_SIZE 100

typedef int TElemType; // node data

typedef struct PTNode { // node 
	TElemType data;
	int parent;
}PTNode;

typedef struct { // tree struct
	PTNode nodes[MAX_TREE_SIZE];
	int r, n; // root location and node-number
}PTree;

void TreeTest(void) {

	return;
}