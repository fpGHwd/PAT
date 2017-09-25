#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>

#define DATAPATH "D:\\nayowang\\Documents\\Visual Studio 2017\\Projects\\DataStructure\\test\\data.txt"
#define PRIVATEDATA "d:\\nayowang\\Documents\\Visual Studio 2017\\Projects\\DataStructure\\dahuaDataStructure\\PrivateData.txt"

//G(V,E) // vertex, edge

typedef char VertexType; // typedef char VertexType
typedef int EdgeType;
#define MAXVEX 10
#define INIFINITY 65535

typedef struct {
	VertexType vexs[MAXVEX];
	EdgeType arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

static MGraph *graph;

void CreateGraph(MGraph **G) {

	int i, j, k, m, n;
	int x, y, cost;
	int chx, chy;
	char c;

	FILE *fp;
	int s;

	*G = (MGraph*)malloc(sizeof(MGraph));

	if ((s = fopen_s(&fp, PRIVATEDATA, "r")) != 0)
		exit(1);

	// vertex and edge
	fscanf_s(fp, "%d %d", &m, &n);
	for (i = 0; i < m; i++)
		for (j = 0; j < m; j++)
			(*G)->arc[i][j] = INIFINITY;
	(*G)->numVertexes = m;
	(*G)->numEdges = n;

	// nodes
	do { fscanf_s(fp, "%c", &c); }while (c != 'A');
	(*G)->vexs[0] = c;
	m = 8;
	while (m--)
		fscanf_s(fp, "%c", &((*G)->vexs[8-m]));

	// edges
	for (k = 0; k < n; k++){
		fscanf_s(fp, "%d %d %d", &chx, &chy, &cost);
		(*G)->arc[chy][chx] = (*G)->arc[chx][chy] = cost;
	}

	fclose(fp); // close file
}

void test_graph(void) {

	CreateGraph(&graph); // create a graph

	printf("\n");
}
