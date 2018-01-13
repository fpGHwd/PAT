#include "stdafx.h" // #include <cstdio>

#define K 1000 // 0<=NK<=1000

struct term {
	double coe; // coefficient
	int exp; // exponent
	term() {
		coe = 0.0;
		exp = 0;
	}
}a[10]; // 0<=K<=10

double ans[2*K+1]; // 0<=NK<=1000
int PATA1009(void) { // int main(){}
	int m, n; // result nonzero terms
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %lf", &a[i].exp, &a[i].coe); // %f -> %lf
	}
	scanf("%d", &n);
	int exp;
	double cof;
	for (int i = 0; i < n; i++) {
		scanf("%d %lf", &exp, &cof);
		for (int j = 0; j < m; j++) { // d
			ans[exp + a[j].exp] += cof * a[j].coe;
			//ans[e + a[j].exp].exp = e + a[j].exp;
		}
	}
	int count = 0;
	for (int i = 0; i <= 2 * K; i++) { // i <= 2*K -> i < 2*K or i<= 2*K -1 //  i<2*K -> i<=2*K
		if (ans[i] != 0.0)count++;
	}
	
	printf("%d", count);
	for (int i = 2*K; i >=0; i--) { // count -> i // 0 ~ 2*K
		if (ans[i] != 0.0)
			printf(" %d %.1f", i, ans[i]); // direction and the blank
	}
	return 0;
}