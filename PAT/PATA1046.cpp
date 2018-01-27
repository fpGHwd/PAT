#include "stdafx.h" // #include <cstdio>

#define MAX 10000

#define MMAX 10001
#define NMAX 100001

int D[NMAX] = { 0 }, R[NMAX] = { 0 };
int sum = 0;
void distance(int a, int b, int i) {
	int ret;
	if (a > b) {
		int tmp = a;
		a = b;
		b = tmp;
	}
	ret = D[b - 2] - ((a >= 2)? D[a - 2]: 0); // ?:->()
	R[i] = ((ret < (sum - ret)) ? ret : (sum - ret));
}

void PATA1046(void) { // int main(){}
	int m, n,d;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		getchar();
		scanf("%d", &d);
		sum += d;
		D[i] = sum;
		
	}
	scanf("%d", &m);
	int a, b;
	for (int i = 0; i < m; i++) {
		getchar();
		scanf("%d%d", &a, &b);
		distance(a, b, i);
	}
	for (int i = 0; i < m; i++) {
		printf("%d\n", R[i]);
	}

	return;
}