// PAT A1059
// N=p1^k1*p2^k2*...*pn^kn
#include "stdafx.h"
#include <cstdio>
#include <cmath>

// isPrime(n) 
static bool isPrime(int n) {
	if (n <= 1)return false;
	int sqr = (int)sqrt(1.0*n);
	for (int i = 2; i <= sqr; i++)
		if (n%i == 0)return false;
	return true;
}

// maxn = maxn(n)
const int maxn = 65536 + 1;
static int prime[maxn], pNum = 0;
static bool p[maxn] = { 0 };
void Find_Prime(void) {
	int i;
	for (i = 2; i < maxn; i++)
		if (isPrime(i)) {
			prime[pNum++] = i;
			p[i] = true;
		}
}

struct factor {
	int x, cnt;
}fac[10];
int fNum = 0;

// fac = Factor(n)
void Factor(int n) {
	Find_Prime();
	int temp = n;

	if (n == 1) {
		printf("1=1");
		return;
	}

	int sqr = sqrt(1.0 * n); // sqr = sqrt(n)
	for (int i = 0; i < pNum && prime[i] <= sqr; i++) {
		if (n%prime[i] == 0) {
			fac[fNum].x = prime[i];
			fac[fNum].cnt = 0;
			while (n % prime[i] == 0) {
				fac[fNum].cnt++;
				n /= prime[i];
			}
			fNum++;
		}
		if (n == 1)break;
	}
	if (n != 1) {
		fac[fNum].x = n;
		fac[fNum].cnt = 1;
		fNum++;
	}

	int j = 0;
	printf("%d=", temp);
	while (j < fNum) {
		printf("%d", fac[j].x);
		if (fac[j].cnt > 1)printf("^%d", fac[j].cnt);
		if (j < fNum - 1)printf("*");
		j++;
	}
}

int PATA1059() {
	int n;
	scanf("%d", &n);
	Factor(n);
	return 0;
}
