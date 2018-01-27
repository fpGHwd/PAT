#include "stdafx.h"

int PATB1009() {
	// test case is in a file, so on a file and return value of scanf;
	char s[81][81];
	int count = 0;
	while (scanf("%s",s[count] ) != EOF) { // s in %s stands for string, meaningful with scanf's return value
		count++;
	}

	for (int i = count - 1; i >= 0; i--) {
		printf("%s", s[i]);
		if (i > 0)printf(" ");
	}

	return 0;
}