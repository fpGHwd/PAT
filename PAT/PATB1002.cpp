#include "stdafx.h"
#include <cstring>

#define MAX 100

char PY[][5] = { "ling", "yi", "er", "san", "si","wu","liu","qi","ba","jiu" };

int PATB1002() {
	char s[MAX];
	scanf("%s", s);
	int len = strlen(s), sum = 0;
	for (int i = 0; i < len; i++) {
		sum += s[i] - '0';
	}
	int py[3], count = 0;
	while (sum) {
		py[count++] = sum % 10;
		sum = sum / 10;
	}
	for (int i = count-1; i >= 0; i--) { // i++ -> i--
		if (i != 0)
			printf("%s ", PY[py[i]]);
		else
			printf("%s", PY[py[i]]);
	}
	return 0;
}
