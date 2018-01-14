#include "stdafx.h"

#define DMIN 2
#define DMAX 10
#define STRUCTMAX 32

int save[STRUCTMAX];

int PATB1022() {
	int a, b,c,d,exp, count = 0;
	scanf("%d%d%d", &a, &b, &exp);
	c = a + b;
	while (c) {
		save[count] = c % exp;
		c = c / exp;
		count++;
	}

	if (count == 0) {
		printf("0");
		return 0;
	}
	for (int i = count; i > 0; i--) {
		printf("%d", save[i - 1]);
	}

	return 0;
}