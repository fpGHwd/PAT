#include "stdafx.h"
#include "malloc.h"


int array[] = { 7,8,4,1,3,9,2, 5, 6, };
// int arrary[] = { 7,8,4,1,3,9,2 };

void bubblesort(int arr[], int n);
void print();


void test_bubblesort()
{
	/*
	int i = 10;
	int A[10];
	for (int j = 0; j < 10; j++) {
		A[j] = i;
	}
	BTNode *p;
	createTree(p, A, 1);

    return 0;
	*/

	//bubblesort(arrary, 7);
	bubblesort(array, 9);
	//system("pause");
	getchar();
}





// 7 8 4  1 3 9 2 



//int arrary[] = { 7,8,4,1,3,9,2 };

void bubblesort(int arr[], int n) {
	int i;
	int temp;
	int j;
	int k;

	i = n;
	j = -1;
	while (i > j) { // i != j
		for (k = j + 1; k < i - 1; k++) {
			if (arr[k] > arr[k + 1]) {
				temp = arr[k];
				arr[k] = arr[k + 1];
				arr[k + 1] = temp;
			}
			else {
				// do nothing;
			}
		}
		print();
		i--;

		for (k = i - 1; k > j + 1; k--) {
			if (arr[k] < arr[k - 1]) {
				temp = arr[k - 1];
				arr[k - 1] = arr[k];
				arr[k] = temp;
			}
		}
		j++;
		print(); // not reasonable
	}


	/*
	for(i=1;i<=n;i++){
	for(j - i/2 -1; j< n -1 - i/2-1; j++);
	for(;;);
	}
	*/

}

void print() {
	int k;
	//for (k = 0; k < 7; k++) {
	for (k = 0; k < 9; k++) {
		printf(" %d", array[k]);
	}
	printf("\n");
}
