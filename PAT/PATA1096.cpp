#include "stdafx.h"
#include <cstdio>

static long long k, len;

int PATA1096() {
	freopen("input1.txt", "r", stdin);
	long long n; // timeout -> n long long
	scanf("%lld", &n); 
	long long count, temp; // int temp -> long long temp

	for (long long i = 2; i * i <= n; i++) { // timeout may be here
		long long j = i;
		count = 0;
		temp = n;
		len = 0;
		while (temp%j == 0) {
			temp /= j++;
			count++;
		}
		if (count > len) {
			len = count;
			k = i;
		}
	}

	if (len == 0) { // last point AC: 6 test case 1 point
		printf("1\n%lld", n);
	}
	else {
		printf("%lld\n", len);
		for (long long i = k; i < k + len; i++) {
			if (i != k)printf("*");
			printf("%lld", i);
		}
	}


	return 0;
}
