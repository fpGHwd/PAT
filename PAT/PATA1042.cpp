// PATA1042
#include "stdafx.h"
#include <cstdio>

#define N 54
static char S[54][2] = { 0 };

void initiate(void) {
	for (int i = 0; i < N; i++) {
		if (i <= 12) {
			S[i][0] = 'S';
			S[i][1] = i % 13 + '1';
		}
		else if (13 <= i && i <= 25) { // 13 <= i <= 25 
			S[i][0] = 'H';
			S[i][1] = i % 13 + '1';
		}
		else if (26 <= i && i <= 38) {
			S[i][0] = 'C';
			S[i][1] = i % 13 + '1';
		}
		else if (39 <= i && i <= 51) {
			S[i][0] = 'D';
			S[i][1] = i % 13 + '1';
		}
		else {
			if (i == 52) {
				S[i][0] = 'J';
				S[i][1] = '1';
			}
			else {
				S[i][0] = 'J';
				S[i][1] = '2';
			}
		}
	}
}

void printf_card(int i) {
	char c;
	if (i <= 12) {
		c = 'S';
	}
	else if (13 <= i && i <= 25) { // 13 <= i <= 25 
		c = 'H';
	}
	else if (26 <= i && i <= 38) {
		c = 'C';
	}
	else if (39 <= i && i <= 51) {
		c = 'D';
	}
	else {
		c = 'J';
	}
	printf("%c%d", c, i % 13 + 1);
}

void printfS(void) {
	for (int i = 0; i < N - 1; i++) {
		printf("%c%d ", S[i][0], S[i][1] - '1' + 1);
	}
	printf("%c%d", S[N - 1][0], S[N - 1][1] - '1' + 1);
}

static int ini_order[54];
void initiate_order(void) {
	for (int i = 0; i < N; i++) {
		ini_order[i] = i;
	}
}

void order(int i_order[], int od[], int len) {
	int after[N];
	for (int i = 0; i < len; i++) {
		after[od[i] - 1] = i_order[i];
	}
	for (int i = 0; i < len; i++) {
		i_order[i] = after[i];
	}
}

void printf_after_order(int i_order[], int len) {
	for (int i = 0; i < N - 1; i++) {
		printf_card(ini_order[i]);
		printf(" ");
	}
	printf_card(ini_order[N - 1]);
}

int PATA1042() {

	//initiate();
	//printfS();
	int given_order[54], n;
	initiate_order();
	scanf("%d", &n);
	for (int i = 0; i < N; i++) {
		getchar();
		scanf("%d", &given_order[i]);
	}
	for (int i = 0; i < n; i++) {
		order(ini_order, given_order, 54);
	}
	printf_after_order(ini_order, 54);

	return 0;
}