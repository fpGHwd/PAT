#pragma once

#include "stdafx.h"

typedef int ElemType;
#define MaxSize 100

/*operations*/
// Value 
// Assign
// ADisp

// sparse matrix, tuple node 
// i, j, a(i,j)

typedef struct{
	int r;
	int c;
	ElemType d;
}TupNode; // non-0 element

typedef struct {
	int rows;
	int cols;
	int nums;
	TupNode data[MaxSize];
}TSMatrix; // whole matrix

/*
A 6*7 =		0 0 1 0 0 0 0
			0 2 0 0 0 0 0
			3 0 0 0 0 0 0
			0 0 0 5 0 0 0
			0 0 0 0 6 0 0
			0 0 0 0 0 7 4
*/
void CreatMat(TSMatrix &t, ElemType **A, int row, int col); // create matrix
bool AssignMat(TSMatrix &t, ElemType x, int i, int j);
bool Assign(TSMatrix &t, ElemType &x, int i, int j);
void DispMat(TSMatrix t);
bool TransMat(TSMatrix t, TSMatrix &tm);

/* cross link list to save matrix */

#define M 3 // row
#define N 4 // column
#define Max ((M)>(N)?(M):(N)) // column max 
typedef struct mtxn{
	int row;
	int col;
	struct mtxn *right, *down;
	union {
		int value;
		struct mtxn *link;
	}tag;
}MatNode;
/*operation will not be inducted*/
