#include "stdafx.h"

#define MAXV 20
#define INFINITY 65535
#define InfoType char

typedef struct {
	int no;
	InfoType info;
}VertexType;

typedef struct {
	int edges[MAXV][MAXV];
	int n, e; // vertex number and edges number;
	VertexType vertexs[MAXV]; // vertexs
}MatGraph;