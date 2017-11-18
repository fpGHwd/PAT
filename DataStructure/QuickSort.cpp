#include "QuickSort.h"
#include "stdafx.h"

typedef char InfoType;

typedef struct sort {
	int key;
	InfoType info;
}ElemType;


void quick_sort(int a[], int l, int r)
{
	if (l < r)
	{
		int i, j, x;

		i = l;
		j = r;
		x = a[i];
		while (i < j)
		{
			while (i < j && a[j] > x)
				j--;
			if (i < j)
				a[i++] = a[j];

			while (i < j && a[i] < x)
				i++;
			if (i < j)
				a[j--] = a[i];
		}
		a[i] = x;
		quick_sort(a, l, i - 1);
		quick_sort(a, i + 1, r);
	}
}

/*
void test_quick_sort(void) {
	int a[20] = {23,34,56,3,12,67,8,42,64,34,7,34,23,5,23,44,33,25,61,43};
	int i;
	printf("the origin array: is: |");
	for (i = 0; i < 20; i++) {
		printf("%d | ", a[i]);
	}
	printf("\n");
	quick_sort(a, 0, 19);
	printf("the quick_sorted array: is: |");
	for (i = 0; i < 20; i++) {
		printf("%d | ", a[i]);
	}
	printf("\n");
}
*/

// pivot in insert sort
void InsertSort(ElemType A[], int n) {
	int i,j;
	for (i = 2; i < n; i++) {
		if (A[i].key < A[i - 1].key) {
			A[0] = A[i]; // A[0] is the pivot
			for (j = i - 1; A[0].key > A[j].key; j--) {
				A[j + 1] = A[j];
			}
			A[j + 1] = A[0];
		}
	}
}

// swap content is OK
void Swap(ElemType *a, ElemType *b) {
	ElemType temp = *a;
	*a = *b;
	*b = temp;
}
// swap pointer cannot be used in Sequence-save-type
void SwapPointer(ElemType **a, ElemType **b) {
	ElemType *temp = *a;
	*a = *b;
	*b = temp;
}

int Partition(ElemType A[], int low, int high) {
	ElemType pivot = A[low];
	while (low < high) { // this condition is forget
		while (low < high && A[high].key > pivot.key) high--;
		//Swap(A + low, A + high);
		A[low].key = A[high].key;
		while (low < high && A[low].key < pivot.key)low++;
		A[high].key = A[low].key;
	}
	A[low] = pivot;
	return low;
}

int Partition2(ElemType A[], int low, int high) {
	int rand_index = low + rand() % (high - low + 1);
	Swap(A+rand_index, A+low);
	int i = low, j;
	for (j = low+1; j < high; j++) {
		if (A[j].key < A[low].key)
			Swap(A + j, A + (++i));
	}
	Swap(A + i, A + low);
	return i;
}

void QuickSort(ElemType A[], int low, int high) {
	if (low < high) {
		int index = Partition(A, low, high);
		QuickSort(A, low, index - 1);
		QuickSort(A, index + 1, high);
	}
}

void TestQuickSort(void) {
	int a[20] = { 23,34,56,3,12,67,8,42,64,32,7,38,24,5,26,44,33,25,61,43 };
	ElemType A[20];
	for (int i = 0; i < 20; i++) {
		A[i].key = a[i];
	}
	QuickSort(A, 0, 19);
	for (int i = 0; i < 20; i++) {
		printf("%d,", A[i].key); // 3,5,7,8,12,23,24,25,26,32,33,34,38,42,43,44,56,61,64,67,
	}
}