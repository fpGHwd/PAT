#include "stdafx.h" // #include <cstdio>

#define K 1000

struct term {
	float coefficient; // coefficient
	int exponent; // exponent
	term() {
		coefficient = 0;
		exponent = 0;
	}
}a[K],answer[2*K];

int PATA1009(void) { // int main(){}
	int d, e; // result nonzero terms
	scanf("%d", &d);
	for (int i = 0; i < d; i++) {
		scanf("%d %f", &a[i].exponent, &a[i].coefficient);
	}
	scanf("%d", &e);
	float f;
	for (int i = 0; i < e; i++) {
		scanf("%d %f", &e, &f);
		for (int j = 0; j < d; j++) { // d
			answer[e + a[j].exponent].coefficient += f * a[j].coefficient;
			answer[e + a[j].exponent].exponent = e + a[j].exponent;
		}
	}
	int count = 0;
	for (int i = 0; i <= 2 * K; i++) {
		if (answer[i].exponent != 0)count++;
	}
	
	if (count)
		printf("%d ", count);
	else
		printf("0");
	for (int i = 2*K-1; i > 0; i--) { // count -> i
		if (answer[i].coefficient)
			printf("%d %.1f ", answer[i].exponent, answer[i].coefficient);
	}
	if (answer[2*K - 1].coefficient)
		printf("%d %.1f", answer[2*K- 1].exponent, answer[2*K - 1].coefficient);
	return 0;
}