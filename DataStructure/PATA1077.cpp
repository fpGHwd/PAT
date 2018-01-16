#include "stdafx.h" // #include <cstdio>
#include <cstdlib>
// #include <cstring>

#define N 100
#define CHARACTERS_MAX 256

char D[N][CHARACTERS_MAX];

int PATA1077(void) { // int main(){;}
	int n, len, len_min;
	char temp;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		gets_s(D[i]); // not read \n  // gets_s -> gets
		len = strlen(D[i]);
		if (i == 0)len_min = len;
		else if (len_min > len)len_min = len; // get len_min // valuable info
		for (int j = 0; j < len/2; j++) {
			temp = D[i][j];
			D[i][j] = D[i][len - 1 - j];
			D[i][len - 1 - j] = temp;
		}
	}

	int idx = 0;
	bool flag = true;
	while (idx < len_min) {
		temp = D[0][idx];
		for (int i = 1; i < n; i++) { // len_min -> n
			if (temp != D[i][idx]) {
				flag = false;
				break;
			}
		}
		if (flag)
			idx++;
		else
			break;
	}
	if (idx != 0) {
		for (int i = idx - 1; i >= 0; i--) {
			printf("%c", D[0][i]);
		}
	}
	else {
		printf("nai");
	}

	return 0;
}