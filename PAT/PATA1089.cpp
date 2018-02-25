#include "stdafx.h"
#include <cstdio>
#include <cstdlib>
#include <cstdlib>
#include <algorithm>
#include <cstring> // memcpy

using namespace std;

#define MAX_N 100

static int N, init[MAX_N], media[MAX_N], temp[MAX_N];

bool isSame(int A[], int B[],int n) {
	for (int i = 0; i < n; i++) {
		if (A[i] != B[i]) {
			return false;
		}
	}
	return true;
}

bool insertSort(int A[], int n) {
	int temp;
	bool flag = false;

	for (int i = 1; i < n; i++) {
		if (i != 1 && isSame(A, media, N)) { // can change location upwards // need not i!= 1 for my judgement here
			flag = true;
		}
		if (A[i] < A[i - 1]) {
			temp = A[i];
			int j; 
			for (j = i - 1; j >= 0 && A[j] > temp; j--) {
				A[j + 1] = A[j];
			}
			A[j+1] = temp; // A[j+1] = temp, here is important
		}
		if (flag) {
			printf("Insertion Sort\n");
			for (int k = 0; k < n; k++) {
				if (k != 0)
					printf(" ");
				printf("%d", A[k]);
			}
			return true;
		}
	}
	return false;
}

void merge(int A[], int n){
	bool flag = false;
	for (int i = 2; i/2<= n; i = 2 * i) { // i>n <-> i/2 <= n
		if (i != 2 && isSame(A, media, n)) { // need i!= 2 here for this way of judgement
			flag = true;
		}
		for (int j = 0; j < n; j+=i) {
			//sort(A + j * i, ((j + 1) * i >= n)?(A+n):(A+(j+1)*i));
			sort(A + j, A + min(j + i, n));
		}
		if (flag) {
			printf("Merge Sort\n");
			for (int k = 0; k < n; k++) {
				if (k != 0)
					printf(" ");
				printf("%d", A[k]);
			}
			return; // break;
		}
	}
}

int PATA1089(void) {
	freopen("input1.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &init[i]);
	}
	memcpy(temp, init, sizeof(init));
	for (int i = 0; i < N; i++) {
		scanf("%d", &media[i]);
	}

	if (!insertSort(temp, N))
		merge(init, N);

	return 0;
}