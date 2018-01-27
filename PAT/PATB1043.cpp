#include "stdafx.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
//#include <>
#define INPUT_STRING_LENGTH_MAX 10000

static char input[INPUT_STRING_LENGTH_MAX+1];
static char carray[6] = { 'P', 'A', 'T', 'e','s','t' };
static int sum[6] = { 0 };

int PATB1043() {
	freopen("input.txt", "r", stdin);
	gets_s(input);
	int len = strlen(input);
	char c;
	for (int i = 0; i < len; i++) {
		c = input[i];
		for (int j = 0; j < 6; j++) {
			if (carray[j] == c) {
				sum[j]++;
				continue;
			}
		}
	}
	
	bool p;
	do {
		p = false;
		int k = 0;
		while (k < 6) {
			if (sum[k] > 0) {
				printf("%c", carray[k]);
				sum[k]--;
				if (sum[k] > 0)p = true;
			}
			k++;
		}
	} while (p);

	return 0;
}