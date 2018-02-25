#include "stdafx.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdlib>

#define S_G 17
#define K_S 29

int PATA1058() {
	int a, b, c, d,e,f;
	scanf("%d.%d.%d", &a, &b, &c);
	scanf("%d.%d.%d", &d, &e, &f);
	c = c + f;
	b = b + e + c / K_S;
	c = c % K_S;
	a = a + d + b / S_G;
	b = b % S_G;
	printf("%d.%d.%d", a, b, c);

	return 0;
}