// PATB1008
#include "stdafx.h"
#include <cstdio>

#define MAX 100

int PATB1008() {
	int n, m, array[MAX], i;
	scanf("%d%d", &n, &m);
	m = m % n; // timeout
	for (int i = 0; i < n; i++) {
		scanf("%d", &array[i]);
	}

	for (i = n - m; i%n != (n - m - 1) % n; i++) {
		printf("%d ", array[i%n]);
	}
	printf("%d", array[i%n]);

	return 0;
}