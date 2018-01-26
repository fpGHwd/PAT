#include "stdafx.h"
#include <cstdio>
#include <cstring>

#define MAX_BROKEN 128
#define INPUT_MAX 100000+1

static int broken[MAX_BROKEN] = { false };
static char b[MAX_BROKEN + 1];
static char input[INPUT_MAX + 1];

int PATB1033() {
	freopen("input.txt", "r", stdin);
	gets_s(b);
	int len = strlen(b);
	for (int i = 0; i < len; i++) {
		broken[b[i]] = true;
	}
	char c, temp;
	gets_s(input);
	len = strlen(input);
	for (int i = 0; i < len; i++) {
		c = input[i];
		if (c >= 'a' && c <= 'z')temp = c - 'a' + 'A';
		else temp = c;
		if (!broken[temp]) {
			if (broken['+'] == false) {
				printf("%c", c);
			}
			else {
				char d;
				if (c >= 'A' && c <= 'Z') {
					d = c - 'A' + 'a';
				}
				else {
					d = c;
					printf("%c", c);
				}

			}
		}
	}
	return 0;
} // scanf + getchar -> gets -> AC