// DataStructure.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "QuickSort.h"

// DeleteReconstruct
void testDeleteReconstruct() {

}

typedef struct int_array {
	int data[4];
}test_type;

int main()
{
	/*
	int n = 2000;
	int count, k, j;

	count = 0;
	for (k = 1; k <= n; k *= 2) {
		for (j = 1; j <= n; j++) {
			count++;
			printf("count is %d\n", count);
		}
	}
	*/

	test_type abcd[10];
	test_type *a = abcd;
	a++;
	printf("%d\n", a - abcd);
	a++;
	printf("%d\n", a - abcd);
	a++;
	printf("%d\n", a - abcd);
	a++;
	printf("%d\n", a - abcd);

	//test_quick_sort();

	getchar();
    return 0;
}



