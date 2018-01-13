#include "stdafx.h"
#include <stdio.h>

// initiate integer array
void init_interger_array(void) {
	int a[10] = { 5,3,2,6,8,4 };
	for (int i = 0; i < 10; i++) {
		printf("a[%d] = %d\n", i, a[i]);
	}
}

// bubble
static int bubble_int_array[] = {3,1,4,5,2};
void bubble(int A[], int n) {
	int i,j,temp;
	for (i = 0; i < n - 1; i++) {
		for (j = n-1; j > i; j--) {
			if (A[j - 1] > A[j]) {
				temp = A[j];
				A[j] = A[j - 1];
				A[j-1] = temp;
			}
		}
	}
}

// printf array
void print_array(int A[], int len) {
	printf("The array is:\n");
	for (int i = 0; i < len; i++) {
		printf("%d", A[i]);
	}
	printf("\n");
}

int AlgorithmNote(void)
{
	//init_interger_array();
	print_array(bubble_int_array, 5);
	bubble(bubble_int_array, 5);
	print_array(bubble_int_array, 5);

	return 0;
}