#include "stdafx.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX_INPUT_STRING 1000+1
#define MAX_ASCII (1<<7) // here is interesting // (2<<7-1) = 1<<7 = 127 = (2<<(7-1))

static char input[MAX_INPUT_STRING];
static int statistic[MAX_ASCII] = {0};

int PATB1042() {
	freopen("input.txt", "r", stdin);
	gets_s(input);
	int len = strlen(input);
	char c;
	for (int i = 0; i < len; i++) {
		c = input[i];
		if (c >= 'A' && c <= 'Z') {
			c = c - 'A' + 'a';
		}
		if (c >= 'a' && c <= 'z') {
			statistic[c]++;
		}
	}

	int max = 'a';
	for (int i = 'a'; i <= 'z' + 1; i++) {
		if (statistic[i] > statistic[max])max = i;
	}

	printf("%c %d", max, statistic[max]);

	return 0;
}
