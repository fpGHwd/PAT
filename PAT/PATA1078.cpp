#include "stdafx.h"
#include <cmath>
#include <cstdio>

#define MAX_HASH 10000

static bool isPrime(int k) {
	if (k <= 1)return false;
	int sqr = (int)sqrt(1.0 * k);
	for (int i = 2; i <= sqr; i++) { // i = 2  // or i*i <= k
		if (k%i == 0)return false;
	}
	return true;
}

static int HashTable[MAX_HASH] = { 0 };

int PATA1078() {
	freopen("input.txt", "r", stdin);
	int MSize, N;
	scanf("%d%d", &MSize, &N);

	int p;
	if (!isPrime(MSize)) // redefine
		for (int i = MSize + 1; i; i++) {
			if (isPrime(i)) {
				p = i;
				break;
			}
		}
	else
		p = MSize;

	int temp;
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		int temp1 = temp, k = 0;
		while (HashTable[temp1 % p] != 0 && k < p) { // temp1 % p < MSize
			temp1 = (temp + k * k)% p; // (temp1 + k * k)%p -> (temp + k*k)%p
			k = k + 1;
		}
		if (i != 0)
			printf(" ");
		if (k == p) {
			printf("-");
		}
		else {
			HashTable[temp1 % p] = temp;
			printf("%d", temp1 % p);
		}
			
	}

	return 0;
}
