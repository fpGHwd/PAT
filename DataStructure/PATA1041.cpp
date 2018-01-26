#include "stdafx.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 10000
#define PEOPLES 100000

static int store[MAX + 1] = { 0 }, numbers[PEOPLES] = {0};

int PATA1041() {
	freopen("input1.txt", "r", stdin);
	int n, temp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		numbers[i] = temp;
		store[temp]++;
	}

	int idx=-1;
	for (int i = 0; i < n; i++) {
		if (store[numbers[i]] == 1) {
			idx = i;
			break;
		}
	}
	if (idx == -1)
		printf("None");
	else
		printf("%d", numbers[idx]);

	return 0;
}