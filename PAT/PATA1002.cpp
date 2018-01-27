#include "stdafx.h" // #include <cstdio>

#define K 10
struct term1 {
	float coefficient; // coefficient
	int exponent; // exponent
	int flag;
	term1() {
		coefficient = 0;
		exponent = 0;
		flag = false;
	}
}a[K], b[K], c[K];
bool flag1[K] = { false }, flag2[K] = { false };

int PATA1002(void) { // int main(){}
	int d, e; // result nonzero terms
	scanf("%d", &d);
	getchar();
	for (int i = 0; i < d; i++) {
		scanf("%d %f", &a[i].exponent, &a[i].coefficient);
		flag1[i] = true;
		getchar(); // blank
	}
	scanf("%d", &e);
	getchar();
	for (int i = 0; i < e; i++) {
		scanf("%d %f", &b[i].exponent, &b[i].coefficient);
		flag2[i] = true;
		getchar(); // blank
	}

	int i1 = 0, i2 = 0, count = 0;
	while (d > i1  && e > i2) {
		if (a[i1].exponent > b[i2].exponent) {
			c[count].exponent = a[i1].exponent;
			c[count].coefficient = a[i1].coefficient;
			i1++;
			count++;
		}
		else if(a[i1].exponent == b[i2].exponent) {
			if ((a[i1].coefficient + b[i2].coefficient) != 0) {
				c[count].exponent = a[i1].exponent;
				c[count].coefficient = a[i1].coefficient + b[i2].coefficient;
				count++; // count is important
			}
			i1++;
			i2++;
		}
		else {
			c[count].exponent = b[i2].exponent;
			c[count].coefficient = b[i2].coefficient;
			i2++;
			count++;
		}
	}

	while (d > i1) {
		c[count].exponent = a[i1].exponent;
		c[count].coefficient = a[i1].coefficient;
		i1++;
		count++;
	}

	while (e > i2) {
		c[count].exponent = b[i2].exponent;
		c[count].coefficient = b[i2].coefficient;
		i2++;
		count++;
	}

	if (count == 0) {
		printf("0");
		return 0;
	}
	else {
		printf("%d ", count);
	}
	
	for (int i = 0; i < count-1; i++) { // count -> i
		if(c[i].coefficient)
			printf("%d %.1f ", c[i].exponent, c[i].coefficient);
	}
	if (c[count-1].coefficient)
		printf("%d %.1f", c[count-1].exponent, c[count-1].coefficient);
	return 0;
}	