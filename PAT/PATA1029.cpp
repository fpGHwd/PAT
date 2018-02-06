#include "stdafx.h"
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX_N 1000000

static int A[2 * MAX_N];

int PATA1029() {
	freopen("input.txt", "r", stdin);
	int N, M;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	scanf("%d", &M);
	for (int i = N; i < M + N; i++) {
		scanf("%d", &A[i]);
	}

	sort(A, A + M + N);
	printf("%d", A[(M + N) / 2 - (((M+N)%2 == 0)?1:0)]);

	return 0;
}