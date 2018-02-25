#include "stdafx.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define BASE 10

int PATB1021(void) {
	int ret[BASE] = { 0 }; // initiate to 0
	char s[1001];
	gets_s(s); // C just gets(char *s);

	int len = strlen(s);
	for (int i = 0; i < len; i++) {
		ret[s[i] - '0']++; // standard
	}

	for (int i = 0; i <BASE; i++) { // 9 -> BASE
		if (ret[i]) {
			printf("%d:%d\n", i, ret[i]);
		}
	}

	return 0;
}