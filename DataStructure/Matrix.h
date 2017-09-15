#pragma once

#include "stdafx.h"

typedef int ElemType;
#define MaxSize 100

/*operations*/
// Value 
// Assign
// ADisp

// xishu matrix, tuple node 
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
