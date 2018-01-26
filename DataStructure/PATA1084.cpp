#include "stdafx.h"
#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAX 80+1

static char all[MAX], valid[MAX];
static int broken[128] = { 0 }, n = 0; // broken == hashTable

int PATA1084() {
	freopen("input.txt", "r", stdin);
	gets_s(all); // here gets_s, if scanf(%s), point 4 cannot AC
	gets_s(valid);

	int idx1 = 0, idx2 = 0;
	int len1 = strlen(all), len2 = strlen(valid);

	char c;
	while (idx1 < len1 && idx2 < len2) {
		while (all[idx1] != valid[idx2]) {
			c = all[idx1];
			if (c >= 'a' && c <= 'z')c = c - 'a' + 'A';
			if (broken[c] == false) {
				printf("%c", c);
				broken[c] = true;
			}
			idx1++;
		}
		idx1++;
		idx2++;
	}

	return 0;
}