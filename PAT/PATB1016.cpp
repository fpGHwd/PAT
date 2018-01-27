// PATB1016
#include "stdafx.h"
#include <cstdio>

int PATB1016() {
	long long a, b, c = 0, d = 0;
	int n1, n2, n3 = 0, n4 = 0;
	scanf("%lld%lld%lld%lld", &a, &n1, &b, &n2);
	while (a) {
		if (a % 10 == n1) {
			n3++;
		}
		a /= 10;
	}
	while (b) {
		if (b % 10 == n2) {
			n4++;
		}
		b /= 10;
	}
	while (n3--) {
		c = c * 10 + n1;
	}
	while (n4--) {
		d = d * 10 + n2;
	}
	printf("%lld", c + d);
	return 0;
}
