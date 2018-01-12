#include "stdafx.h" // #include <cstdio>

#define PAIRMAX 100

int input[PAIRMAX][2] = { 0 };
int output[PAIRMAX][2] = { 0 };

int PATB1010(void) { // int main(){}
	int i = 0;
	while (scanf("%d%d", &input[i][0], &input[i][1]) != EOF)i++; // EOF
	int count = 0;
	for (int j = 0; j < i; j++) {
		if (input[j][1] != 0) {
			output[j][0] = input[j][0] * input[j][1];
			output[j][1] = input[j][1] - 1;
			count++;
		}
		else {
			output[j][0] = 0;
			output[j][1] = 0;
		}
	}

	int j;
	for (j = 0; j < count-1; j++) {
		printf("%d %d", output[j][0], output[j][1]);
		printf(" ");
	}
	printf("%d %d", output[count-1][0], output[count-1][1]);

	return 0;
}