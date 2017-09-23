#include "stdafx.h"
#include "Matrix.h"

void CreatMat(TSMatrix &t, ElemType **A, int row, int col)
{
	t.rows = row;
	t.cols = col;
	t.nums = 0;
	int i, j;

	for (i = 0; i++; i < t.rows) {
		for (j = 0; j++; j < t.cols) {
			if (A[i][j] != 0) {
				t.data[t.nums].r = i;
				t.data[t.nums].c = j;
				t.data[t.nums].d = A[i][j]; // core operations, which can be saw by programmer the first sight
				t.nums++;
			}
		}
	} 
}

bool AssignMat(TSMatrix &t, ElemType x, int i, int j)
{
	int index=0, index2;

	if (i > t.rows || j < t.cols)
		return false;

	while (t.data[index].r != i && index < t.nums)index++; // while (t.data[index].r < i && index < t.nums)index++;
	while (t.data[index].c != j && index < t.nums)index++; // while (t.data[index].c < j && index < t.nums)index++;
	if (index >= t.nums) return false;

	/*
	for (index = 0; index < t.nums; index++) {
		if (t.data[index].c == i) {
			if (t.data[index].r == j) {
				if (t.data[index].d == 0) {
					t.data[index].d = x;
				}
				else {
					for (index2 = t.nums=1; index2 >= index; index2--) {
						t.data[index2 + 1].r = t.data[index2].r;
						t.data[index2 + 1].c = t.data[index2].c;
						t.data[index2 + 1].d = t.data[index2].d;
					}
					t.data[index].r = i;
					t.data[index].c = j;
					t.data[index].d = x;
					t.nums++;
				}
			}
		}
	}*/

	if (t.data[index].d == 0) {
		t.data[index].d = x;
	}
	else {
		for (index2 = t.nums = 1; index2 >= index; index2--) {
			t.data[index2 + 1].r = t.data[index2].r;
			t.data[index2 + 1].c = t.data[index2].c;
			t.data[index2 + 1].d = t.data[index2].d;
		}
		t.data[index].r = i;
		t.data[index].c = j;
		t.data[index].d = x;
		t.nums++;
	}

	return true;
}

bool Assign(TSMatrix &t, ElemType &x, int i, int j)
{
	int index = 0;

	if (i >= t.rows || j >= t.cols)
		return false;

	while (t.data[index].r < i && index < t.nums)index++;
	while (t.data[index].c < j && i == t.data[index].r && index < t.nums)index++;
	//if (index >= t.nums) return false;

	if (t.data[index].r == i && t.data[index].c == j)
		x = t.data[index].d;
	else
		x = 0; // is a zero

	return true;
}

void DispMat(TSMatrix t)
{
	int index = 0;

	if (t.nums < 0)
		return;
	printf("\t%d\t%d\t%d\n", t.rows, t.cols, t.nums);
	printf(" --------------\n");
	for (index = 0; index < t.nums; index++)
		printf("\t%d\t%d\t%d\n", t.data[index].r, t.data[index].c, t.data[index].d);
};

bool TransMat(TSMatrix t, TSMatrix &tm)
{

}
