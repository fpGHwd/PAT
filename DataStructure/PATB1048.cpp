#include "stdafx.h"

#define MAX 100

char A[MAX + 1];
char B[MAX + 1];
char ans[MAX + 1];

char tra[13] = { '0','1', '2','3','4','5','6','7','8','9','J','Q','K' };

int PATB1048() {
	scanf("%s %s", A, B);
	int lena, lenb;
	lena = strlen(A);
	lenb = strlen(B);
	int len = (lena > lenb) ? lena : lenb;
	int a = (len > lena) ? (lena - 1) : (len - 1);
	int b = (len > lenb) ? (lenb - 1) : (len - 1);
	int c = (a > b) ? a : b, count =1,d,e;
	while (a >= 0 || b >= 0) { // equals to c >= 0
		if (a < 0)
			d = '0';
		else
			d = A[a];
		if (b < 0)
			e = '0';
		else
			e = B[b];
		if (count % 2 == 0) {
			int j = e - d;
			if (j < 0)
				ans[c] = j + 10 + '0';
			else
				ans[c] = j + '0';
		}
		else
			ans[c] = tra[(d  - '0'+ e - '0')%13]; // - 2*'0', without vs hard to  be checked out
		c--;
		a--;
		b--;
		count++; // hard to be checked out without vs
	}

	for (int i = 0; i < len; i++) {
		printf("%c", ans[i]);
	}

	return 0;
}
