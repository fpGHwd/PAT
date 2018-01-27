//PAT B1046
#include "stdafx.h"
#include <cstdio>
#include <cstdlib>

#define MAX 100

int PATB1046() {
	int n;
	int a, b, a1, b1, n1 = 0, n2 = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d%d", &a, &b, &a1, &b1);
		if (b == a + a1 && b1 != a1 + a) {
			n2++;
		}
		else if (b != a + a1 && b1 == a1 + a) {
			n1++;
		}
	}

	printf("%d %d", n1, n2);
	return 0;
}