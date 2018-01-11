#include "stdafx.h" // #include <cstdio>

#define N 10
bool ret[N] = { false };

bool judge(long long a, long long b, long long c) {
	long long result;
	result = a + b;
	if (a > 0 && b > 0 && result < 0)
		return true;
	if (a < 0 && b < 0 && result >= 0) // result>0 -> result >= 0
		return false;
	if (result > c)
		return true;
	else
		return false;
}

int PATA1065() {
	int n;
	long long a, b, c;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld%lld%lld", &a, &b, &c); // %lld -> %ll
		ret[i] = judge(a, b, c);

	}
	for (int i = 0; i < n; i++) {
		printf("Case #%d: %s\n", i+1,ret[i] ? "true" : "false");
	}
	
	return 0;
}