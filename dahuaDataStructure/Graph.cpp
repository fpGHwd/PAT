#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>

//G(V,E) // vertex, edge

typedef char VertexType;
typedef int EdgeType;
#define MAXVEX 10
#define INIFINITY 65535

typedef struct {
	VertexType vexs[MAXVEX];
	EdgeType arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

static MGraph *graph;

void test_graph(void) {

	return;
}
