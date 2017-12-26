#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define MAXV 10
typedef int VertexType;

typedef struct ArcNode {
	VertexType adjvex;
	struct ArcNode *nextarc;
}ArcNode;

typedef struct {
	VertexType adjvex;
	ArcNode *firstarc;
}VexList;

typedef struct {
	VexList adjlist[MAXV];
	int vexnum, arcnum;
}ALGraph;

static const int initinfo[][2] = { 0,2,0,1,1,3,2,3,1,2,2,5,2,4,4,5 };
static int arcs = 8;
static int vexs = 6;

static ALGraph G;
void InitiateAdjGraph(const int init[][2]) {
	int i = 0;
	ArcNode *a, *p;

	for (i; i < arcs; i++) {
		a = (ArcNode*)malloc(sizeof(ArcNode));
		a->adjvex = init[i][1];
		a->nextarc = NULL;
		p = G.adjlist[init[i][0]].firstarc;
		if (p) {
			while (p->nextarc != NULL)p = p->nextarc;
			p->nextarc = a;
		}
		else {
			G.adjlist[init[i][0]].firstarc = a;
		}
		a = (ArcNode*)malloc(sizeof(ArcNode));
		a->adjvex = init[i][0];
		a->nextarc = NULL;
		p = G.adjlist[init[i][1]].firstarc;
		if (p) {
			while (p->nextarc != NULL)p = p->nextarc;
			p->nextarc = a;
		}
		else {
			G.adjlist[init[i][1]].firstarc = a;
		}
	}
	G.vexnum = vexs;
	G.arcnum = arcs;

	printf("G has been initiated.\n");

	return;
}

// print all DFS paths
static int visited[MAXV] = { 0 };
void DFSAllPath(ALGraph G, int v, int path[], int d) {
	ArcNode *p;
	int i;

	visited[v] = 1; // visited
	path[d++] = v;

	if (d == G.vexnum) {
		for (i = 0; i < G.vexnum; i++)
			printf("%02d ", path[i]);
		printf("\n");
	}

	p = G.adjlist[v].firstarc;
	while (p) {
		if (visited[p->adjvex] == 0)
			DFSAllPath(G, p->adjvex, path, d);
		p = p->nextarc;
	}
	visited[v] = 0; // restore environment
}

void printfvex(int v) {
	printf("%02d ", v);
}

void DFS(ALGraph G, int v) {
	ArcNode *p;
	printfvex(v);
	visited[v] = 1;
	p = G.adjlist[v].firstarc;
	while (p) {
		if (visited[p->adjvex] == 0)
			DFS(G, p->adjvex);
		p = p->nextarc;
	} // while
} // DFS

void graph2test()/*(int argc, char **argv)*/ {
	InitiateAdjGraph(initinfo);
	int v = 0, path[MAXV] = { 0 };

	DFSAllPath(G, v, path, 0);
	//DFS(G, v);
	getchar();
	return;
}
