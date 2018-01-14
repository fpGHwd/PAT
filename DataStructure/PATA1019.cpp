#include "stdafx.h"

#define MAX 32

int PATA1019() {
	int n, count = 0, exp, save[32], flag = true;
	scanf("%d %d", &n, &exp);
	while (n) {
		save[count] = n % exp;
		n = n / exp;
		count++;
	}

	if (count % 2 == 1) {
		for (int i = 0; i < count / 2; i++) {
			if (save[i] != save[count - i - 1]) {
				flag = false;
			}
		}
	}

	if (count == 0) { // forget from book
		printf("Yes\n0");
		return 0;
	}

	printf("%s\n", flag ? "Yes" : "No");
	for (int i = count-1; i > 0; i--) {
		printf("%d ", save[i]);
	}
	printf("%d", save[0]);
	return 0;
}