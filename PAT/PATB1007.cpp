#include "stdafx.h"
#include <cmath>
#include <cstdio>

using namespace std;

static bool isPrime(int k) {
	if (k <= 1)return false;
	int sqr = (int)sqrt(1.0 * k);
	for (int i = 2; i <= sqr;i++) {
		if (k%i == 0)return false;
	}
	return true;
}

int PATB1007() {
	freopen("input.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	bool last2 = false, last = false, now; // here is not very happy, but AC once // substance is a queue
	int count = 0;
	for (int i = 0; i <= n; i++) {
		now = isPrime(i);
		if (now && last2)
			count++;
		last2 = last;
		last = now;
	}

	printf("%d", count);
	return 0;
}
