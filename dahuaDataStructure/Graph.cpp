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


// weight
typedef struct EdgeNode {
	int adjvex;
	EdgeType weight;
	struct EdgeNode *next;
}EdgeNode;

typedef struct VertexNode {
	VertexType data;
	EdgeNode *firstedge;
}VertexNode, AdjList[MAXVEX];

typedef struct {
	AdjList adjList;
	int numVertexes, numEdges;
}GraphAdjList;

GraphAdjList *adjacentlistgraph;
void CreateALGraph(GraphAdjList **G) {
	FILE *fp;
	int s,m,k, x,y,w;
	char c;
	EdgeNode *e;

	*G = (GraphAdjList*)malloc(sizeof(GraphAdjList));
	m = 8;
	while (m--)
		(*G)->adjList[m].firstedge = NULL;

	if((s = fopen_s(&fp, PRIVATEDATA, "r") != 0))
		exit(1);

	fscanf_s(fp, "%d %d", &(*G)->numVertexes, &(*G)->numEdges); // vertex and edges

	// nodes
	do { fscanf_s(fp, "%c", &c); } while (c != 'A');
	(*G)->adjList[0].data= c;
	m = 8;
	while (m--)
		fscanf_s(fp, "%c", &((*G)->adjList[8-m].data));

	// edges
	for (k = 0; k < (*G)->numEdges; k++) {
		fscanf_s(fp, "%d %d %d", &x, &y, &w);
		e = (EdgeNode *)malloc(sizeof(EdgeNode));
		e->weight = w;
		e->adjvex = x;
		e->next = (*G)->adjList[y].firstedge;
		(*G)->adjList[y].firstedge = e;
		e = (EdgeNode *)malloc(sizeof(EdgeNode));
		e->weight = w;
		e->adjvex = y;
		e->next = (*G)->adjList[x].firstedge;
		(*G)->adjList[x].firstedge = e;
	}

	fclose(fp);
}

static int visited[MAXVEX];
// todo: DFS in matrix graph
void DFS(MGraph *G, int i) {
	int j;
	visited[i] = 1;
	printf("%c ", G->vexs[i]);
	for (j = 0; j< G->numVertexes;j++)
	{
		if (G->arc[i][j] == 1 && !visited[j])
			DFS(G, j);
	}
}

void DFSTraverse(MGraph *G) {
	int i = 0;

	while (i++ < 8)
		visited[i] = 0;

	// visit all vertex
	i = 0;
	do {
		if (!visited[i])
			DFS(G, i);
	} while (++i < 8);

}

void test_graph(void) {

	//CreateGraph(&graph); // create a graph via matrix

	//CreateALGraph(&adjacentlistgraph); // a graph via adjacent list graph

	// test matrix graph traverse
	CreateGraph(&graph);
	DFSTraverse(graph);

	printf("\n");
}
