#include "stdafx.h"
#include<cmath>

#define N 1000
// 1+3+...+n
// 1 1
// 3 7
// 5 17

int line(int asterisk, int &remaining) {
	if(asterisk == 0)
		return 0;
	else {
		int k =  int(pow(2 * (asterisk + 1), 0.5)) - 1;
		if (k % 2 == 0) {
			k = k - 1;
		}
		remaining = asterisk - (k + 1) * (k + 1) / 2 + 1;
		return k;
	}
}

int PATB1027(void) {
	int re,n, k;
	char ch;
	scanf("%d %c", &n, &ch);
	k = line(n, re);
	if (k == 0) {
		printf("0");
		return 0;
	}
		
	int b, a,c;
	for (int i = 0; i< k; i++) {
		if (i <= k / 2) {
			a = k-2*i;
			b = i;
		}
		else { // i> k/2
			a = 1 + 2 * (i - k/2);
			b = k - i - 1;
		}
		c = b;
		while (c--)printf("#");
		while (a--)printf("%c",ch);
		printf("\n");

	}
	printf("%d", re);
	return 0;
}