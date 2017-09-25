#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static char *S = "GOODGOOGLE";
static char *T = "GOOGLE";

int Index(char *s, char *t, int pos) // pos: default = 0, find flag
{// s = search, t = 
	int i = pos,j = 1;
	while (i <= strlen(s)-1 && j <= strlen(t)-1) { // s[0] = length, T[0] = length
		if (S[i] == T[j]) {
			++j; ++i;
		}
		else {
			i = i - j + 1;
			j = 0;
		}
	}
	if (j >= strlen(t))
		return i - strlen(t);
}

void TestString(void) {
	int i = Index(S, T, 0); // ok
	printf("\n");
}