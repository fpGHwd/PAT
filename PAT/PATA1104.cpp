#include "stdafx.h"
#include <cstdio>

#define MAX_N 100000

//static double A[MAX_N]; // float -> double

int PATA1104() {
	freopen("input.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	double sum = 0,v;
	for (int i = 0; i < n; i++) {
		scanf("%lf", &v); // f-> lf
		sum += (i + 1)*(n - i) * v; // (i+1)*(n-i)*v -> v*(i+1)*(n-i), here is important
	}

	printf("%.2lf\n", sum); // .2lf-> .2f

	return 0;
}
