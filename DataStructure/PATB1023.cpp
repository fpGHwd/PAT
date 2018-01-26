#include "stdafx.h"
#include <cstdio>

#define NUMBERS_COUNT_MAX 50
static int store_count[10] = {0};

int PATB1023() {
	freopen("input.txt", "r", stdin);
	int temp, i = 0;
	while (scanf("%d", &temp) != EOF && i != 10) {
		store_count[i++] = temp;
	}

	for (int i = 0; i < 10; i++) {
		if (i != 0 && store_count[i] != 0) {
			printf("%d", i);
			store_count[i]--;
			break;
		}
	}

	for (int i = 0; i < 10; i++) {
		while(store_count[i] != 0) {
			printf("%d", i);
			store_count[i]--;
		}
	}

	return 0;
}