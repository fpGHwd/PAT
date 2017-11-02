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
	int n, e;
	VertexType vertexs[MAXV];
}MatGraph;  // matrix graph

typedef struct Node {
	int adjvex; // can be adjvex or VertexType(detailed not recommended)
	struct Node *nextarc;
	int weight;
}ArcNode; // arc node
typedef struct {
	InfoType info;
	ArcNode *firstarc; //not to define ArcNode before defining VNode which will confuse
}VNode; // vertex node
typedef struct {
	VNode adjlist[MAXV]; // maximum vertexs number
	int n, e;
}AdjGraph;

/************************************************************************/
/* v is the first node to visit                                         */
/************************************************************************/
static int visited[MAXV];
void DFS(AdjGraph *G, int v) {
	ArcNode *p;
	
	int i;
	for (i = 0; i < MAXV; i++) {
		visited[i] = 0;
	}// initiate visited array

	printf(" %d", v);// visit this vertex
	visited[v] = 1;// visited this vertex

	p = G->adjlist[v].firstarc;
	while (p != NULL) { // arc node
		if (visited[p->adjvex] != 1/*not visit this adjvex*/)
			DFS(G, p->adjvex);
		p = p->nextarc;
	}
}

void BFS(AdjGraph *G, int v) { // tempt queue to save the node 
	int i, w;
	for (i = 0; i < MAXV; i++) {
		visited[i] = 0;
	} // initiated the visited array

	ArcNode *p;
	int qu[MAXV], front = 0, rear = 0;
	qu[rear] = v; rear = (rear + 1) % MAXV;//EnQueue(qu, v);

	if (visited[v] != 1) { // visited
		printf(" %d", v);
	}
	visited[v] = 1;

	p = G->adjlist[v].firstarc;
	while (front != rear) {
		w = qu[front];// dequeue
		front = (front + 1) % MAXV;

		p = G->adjlist[w].firstarc; 
		while (p != NULL) {
			if (visited[p->adjvex] == 0) {
				printf(" %d", p->adjvex);
				visited[p->adjvex] = 1;
				qu[rear] = v; rear = (rear + 1) % MAXV;//EnQueue(qu, v);
			}
			p = p->nextarc;
		}
			
	}// can dequeue


}