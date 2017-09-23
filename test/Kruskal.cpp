#include "stdafx.h"
#include "malloc.h"
#include <stdlib.h>
#include <stdio.h>

#define DATAPATH "D:\\nayowang\\Documents\\Visual Studio 2017\\Projects\\DataStructure\\test\\LinkMatrix.txt"

#define MAXEDGE 100
typedef struct {
	int begin;
	int end;
	int weight;
}Edge;

typedef char VertexType;
typedef int EdgeType;
#define MAXVEX 100
#define INFINITY 65535

typedef struct {
	VertexType vexs[MAXVEX];
	EdgeType arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

static MGraph Kruskal; // static MGraph *Kruskal;

void CreateMGraph(MGraph *G) {
	FILE *fp;
	int status, i, j, k,w;

	//G = (MGraph *)malloc(sizeof(MGraph)); // you are mad

	status = fopen_s(&fp, DATAPATH, "r");
	if (status) {
		printf("Open file(%s) error, please check and try it again\n", DATAPATH);
		exit(1);
	}
	fscanf_s(fp, "%d %d", &G->numVertexes, &G->numEdges);
	printf("\nGet %d vertexes and %d edges\n", G->numVertexes, G->numEdges);
	
	for (i = 0; i < G->numVertexes; i++)
		fscanf_s(fp, "%d", &G->vexs[i]);
	for (i = 0; i < G->numVertexes; i++)
		for (j = 0; j < G->numVertexes; j++)
			G->arc[i][j] = INFINITY;
	printf("Load edges information.");
	for (k = 0; k < G->numEdges; k++) {
		fscanf_s(fp, "%d %d %d", &i, &j, &w);
		printf("\nG->arc[%d][%d] = %d", i, j, w);
		G->arc[i][j] = w;
		G->arc[j][i] = w; // undirected graph, so mirror
	}
	fclose(fp);
}

int Find(int *parent, int f) // 查找连线顶点的尾部下标
{
	while (parent[f] > 0)
		f = parent[f];
	return f;
}

void SqEdges(MGraph *G, Edge *edges) {
	int edge[MAXEDGE], edge_num;
	int i, status;
	char  c;
	FILE *fp;
	
	// read the data from the LinkMatrix.txt
	status = fopen_s(&fp, DATAPATH, "r");
	if (status)
		exit(1);

	i = 2;
	while (i) {
		if ((c = fgetc(fp)) == '\n')
			i--;
	}

	for (i = 0; i < G->numEdges; i++) {
		fscanf_s(fp, "%d %d %d", &edges[i].begin, &edges[i].end, &edges[i].weight);
	}
	fclose(fp);
}

void MiniSpanTree_Kruskal(MGraph *G)
{
	int i, n, m;
	Edge edges[MAXEDGE];
	int parent[MAXVEX];

	SqEdges(G, edges); // G -> edges // to be implementation

	for (i = 0; i < G->numVertexes; i++) {
		parent[i] = 0;
	}
	printf("\n");
	for (i = 0; i < G->numEdges; i++) {
		n = Find(parent, edges[i].begin);
		m = Find(parent, edges[i].end);
		if (n != m) {
			parent[n] = m;
			printf("(%d, %d) %d\n", edges[i].begin, edges[i].end, edges[i].weight);
		}
	}
}

void test_kruskal(void) {
	CreateMGraph(&Kruskal); // create a graph via link matrix
	//if (Kruskal == NULL)
		//exit(1);
	//MiniSpanTree_Kruskal(Kruskal);
	MiniSpanTree_Kruskal(&Kruskal);
	return;
}