#include "stdafx.h" // #include<cstdio>

char r[3] = { 'W','T', 'L' };
int PATA1011(void) {
	float a[3], product =1;
	int b[3];
	for (int i = 0; i < 3; i++) {
		scanf("%f%f%f", &a[0], &a[1], &a[2]);
		if (a[0] > a[1] && a[0] > a[2]) {
			b[i] = 0;
		}
		else if(a[1] > a[0] && a[1] > a[2]) {
			b[i] = 1;
		}
		else {
			b[i] = 2;
		}
		product *= a[b[i]];
	}
	printf("%c %c %c %.2f\n", r[b[0]], r[b[1]], r[b[2]], (product * 0.65 -1)*2);

	return 0;
}
