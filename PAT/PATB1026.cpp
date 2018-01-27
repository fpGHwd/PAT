// PAT B1026
#include "stdafx.h"
#include <cstdio>

#define CLK_TCK 100

int PATB1026() {
	unsigned c1, c2;
	scanf("%d%d", &c1, &c2);
	unsigned n = (c2 - c1) / CLK_TCK;
	if ((c2 - c1) * 1.0 / CLK_TCK - n >= 0.5)n = n + 1; // = 
	printf("%02d:%02d:%02d", n / 3600, n % 3600 / 60, n % 60);
	return 0;
}
