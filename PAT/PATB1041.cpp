#include "stdafx.h" // #include<cstdio>
#include <cstdio>


#define N 1000

struct student {
	long long id;
	int test;
}D[N];

int PATB1041(void) {
	int n,tr,te;
	long long temp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld%d%d", &temp, &tr, &te);
		D[tr].id = temp;
		D[tr].test = te;
	}

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &te);
		printf("%lld %d\n", D[te].id, D[te].test); // %ld -> %lld
	}
	return 0;
}