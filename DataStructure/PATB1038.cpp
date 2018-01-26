#include "stdafx.h"
#include <cstdio>

#define SCORE_THRESHOLD 100

static int scores[SCORE_THRESHOLD] = { 0 }, N;

int PATB1038() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	int temp;
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		scores[temp]++;
	}
	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &temp);
		printf("%d", scores[temp]);
		if (i != k - 1)printf(" ");
	}

	return 0;
}
