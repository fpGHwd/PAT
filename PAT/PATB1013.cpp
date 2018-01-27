// PAT B1013
#include "stdafx.h"
#include <cstdio>
#include <cstdlib>
#include <cmath>

// prime M<=N<=10^4
#define MAX 105000 

static int prime[MAX] = { 0 }, pNum = 0;
static bool p[MAX] = { 0 };

bool isPrime(int n) {
	int sqr = (int)sqrt(1.0*n);
	for (int i = 2; i < n; i++) {
		if (n%i == 0)
			return false;
	}
	return true;
}

void getPrime(void) {
	int i;

	for (i = 2; i <= MAX; i++) {
		if (isPrime(i)) {
			prime[pNum++] = i;
			p[i] = true;
		}
	}
}

const int max_prime = 10001;
const int max_num = 105000;
int prime1[MAX] = { 0 }, pNum1 = 0;
bool p1[max_num] = { 0 };
void getPrime1(void) {
	int i, j;
	for (i = 2; i < max_num; i++) {
		if (p1[i] == false) {
			prime1[pNum1++] = i;
			for (j = i + i; j < max_num; j += i) {
				p1[j] = true;
			}
		}
	}
}

int PATB1013() {
	int m, n, count = 0;
	scanf("%d%d", &m, &n);
	getPrime1();
	printf("pNum1 = %d\n", pNum1);
	for (int i = m; i <= n && i < pNum1; i++) {
		printf("%d", prime1[i - 1]);
		count++;
		if (count % 10 != 0 && i < n)printf(" ");
		else printf("\n");
	}
	//printf("false = %d, true = %d\n", false, true);
	return 0;
}
