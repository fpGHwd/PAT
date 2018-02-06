#include "stdafx.h"
#include <cstdio>

#define MAX_NUMBER 1000000000
#define MAN_N 100000

static int A[MAN_N], left_min_max[MAN_N], right_max_min[MAN_N], pivots[MAN_N];

int PATA1101() {
	freopen("input.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}

	left_min_max[0] = 0;
	for (int i = 1; i < n; i++) {
		if (A[i-1] > left_min_max[i-1]) {
			left_min_max[i] = A[i - 1];
		}
		else {
			left_min_max[i] = left_min_max[i - 1];
		}
	}

	right_max_min[n - 1] = MAX_NUMBER + 1;
	for (int i = n - 2; i >= 0; i--) {
		if (A[i + 1] < right_max_min[i + 1]) {
			right_max_min[i] = A[i + 1];
		}
		else {
			right_max_min[i] = right_max_min[i + 1];
		}
	}

	int count = 0;
	for (int i = 0; i < n; i++) {
		if (A[i] > left_min_max[i] && A[i] < right_max_min[i]) {
			pivots[count++] = A[i];
		}
	}

	printf("%d\n", count); // \n
	if(count == 0)printf("\n"); // test case 2 not pass // print next line when count == 0;
	for (int i = 0; i < count; i++) {
		if (i != 0)printf(" ");
		printf("%d", pivots[i]);
	}


	return 0;
}