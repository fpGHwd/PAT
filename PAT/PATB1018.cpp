// PATB1018
#include "stdafx.h"
#include <cstdio>

int PATB1018() {
	int N, A[3][3] = { 0 }, B[3][3] = { 0 }; // C-J-B; W-E-L
	scanf("%d", &N);
	char a, b;
	int j;
	for (int i = 0; i < N; i++) {
		getchar();
		scanf("%c %c", &a, &b);
		if (a == b) {
			if (a == 'C')j = 0;
			else if (a == 'J')j = 1;//
			else j = 2;
			A[j][1]++;
			B[j][1]++;
		}
		else { // a!= b
			if (a == 'C') {
				if (b == 'J') {
					A[0][0]++;
					B[1][2]++;
				}
				else { // b== 'B'
					A[0][2]++;
					B[2][0]++;
				}
			}
			else if (a == 'J') {
				if (b == 'C') {
					A[1][2]++;
					B[0][0]++;
				}
				else { // b == 'B'
					A[1][0]++;
					B[2][2]++;
				}
			}
			else { // a == B
				if (b == 'C') {
					A[2][0]++;
					B[0][2]++;
				}
				else {// b=='J'
					A[2][2]++;
					B[1][0]++;
				}
			}
		}
	}

	printf("%d %d %d\n", A[0][0] + A[1][0] + A[2][0], A[0][1] + A[1][1] + A[2][1], A[0][2] + A[1][2] + A[2][2]);
	printf("%d %d %d\n", B[0][0] + B[1][0] + B[2][0], B[0][1] + B[1][1] + B[2][1], B[0][2] + B[1][2] + B[2][2]);
	int m = 0, n = 0;
	char c[] = { 'C', 'J', 'B' };
	for (int i = 0; i < 3; i++) {
		if (A[i][0] > A[m][0] || (A[i][0] == A[m][0] && c[i] < c[m]))m = i; // = -> ==
		if (B[i][0] > B[n][0] || (B[i][0] == B[n][0] && c[i] < c[n]))n = i; // = -> ==
	}
	printf("%c %c", c[m], c[n]);

	return 0;
}
