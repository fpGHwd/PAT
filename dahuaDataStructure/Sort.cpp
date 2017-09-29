#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

typedef struct {
	int r[MAXSIZE + 1]; // r[0] is a sentinel
	int length;
}SqList;

void swap(SqList *L, int i, int j) {
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

void BubbleSort0(SqList *L) {

}

void TestSort(void) {
	int array[MAXSIZE + 1] = { 3,2,7,5,6,9,1,4,0,8 };
	SqList S;

	int i;
	S.r[0] = array[0];
	for (i = 0; i < 10; i++) {
		S.r[i + 1] = array[i];
	}
	S.length = i;
	//memcpy(S.r,array,sizeof(array));
	//S.length = sizeof(array) / sizeof(int);

	BubbleSort0(&S);

	return;
}
