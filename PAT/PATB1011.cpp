//PAT1011
#include "stdafx.h"
#include <cstdio>

#define MAX 10

int PATB1011() {
	long long a[MAX], b[MAX], c[MAX];
	bool judge[MAX];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
	}
	for (int i = 0; i < n; i++) {
		printf("Case #%d: %s\n", i + 1, (a[i] + b[i] > c[i]) ? "true" : "false");
	}
	return 0;
}
