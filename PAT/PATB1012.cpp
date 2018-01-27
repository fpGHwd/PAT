// PATB1012
#include "stdafx.h"
#include <cstdio>

#define MACRO 1000

int PATB1012() {
	int N, A[MACRO], A1 = 0, A2 = 0, count2 = 0, A3 = 0, A4 = 0, count4 = 0, A5 = -1;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
		if (A[i] % 10 == 0)A1 += A[i];
		if (A[i] % 5 == 1) {
			count2++;
			if (count2 % 2 == 0) {
				A2 -= A[i];
			}
			else {
				A2 += A[i];
			}
		}
		if (A[i] % 5 == 2)A3++;
		if (A[i] % 5 == 3) {
			A4 += A[i];
			count4++;
		}
		if (A[i] % 5 == 4 && A[i] > A5) {
			A5 = A[i];
		}
	}
	if (A1 == 0) {
		printf("N ");
	}
	else {
		printf("%d ", A1);
	}
	if (count2 == 0) {
		printf("N ");
	}
	else {
		printf("%d ", A2);
	}
	if (A3 == 0) {
		printf("N ");
	}
	else {
		printf("%d ", A3);
	}
	if (count4 == 0) {
		printf("N ");
	}
	else {
		printf("%.1f ", A4 * 1.0 / count4);
	}

	if (A5 == -1) {
		printf("N");
	}
	else {
		printf("%d", A5);
	}

	return 0;
}