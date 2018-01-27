#include "stdafx.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX_STRING_LENGTH 10000
#define ASCII_NUMBER (1<<7)

static char ascii[ASCII_NUMBER] = { 0 };
static char S1[MAX_STRING_LENGTH + 1], S2[MAX_STRING_LENGTH+1];

int PATA1050() {
	freopen("input.txt", "r", stdin);
	gets_s(S1);
	gets_s(S2);
	int len = strlen(S2);
	for (int i = 0; i < len; i++) {
		ascii[S2[i]] = 1;
	}
	
	len = strlen(S1);
	for (int i = 0; i < len; i++) {
		if (!ascii[S1[i]])printf("%c", S1[i]);
	}

	return 0;
}