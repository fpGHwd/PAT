#include "stdafx.h"
#include <cstdio>
#include <cstring>

#define MAX_LENGTH 100000

static char s[MAX_LENGTH+1];
static int p_num[MAX_LENGTH + 1], t_num[MAX_LENGTH + 1];

int PATA1093() {
	freopen("input.txt", "r", stdin);
	gets_s(s);
	int len = strlen(s);
	p_num[0] = 0;
	for (int i = 1; i < len; i++) {
		if (s[i - 1] == 'P') {
			p_num[i] = p_num[i - 1] + 1;
		}
		else {
			p_num[i] = p_num[i - 1];
		}
	}

	t_num[len - 1] = 0;
	for (int i = len - 2; i>= 0; i--) {
		if (s[i+1] == 'T') {
			t_num[i] = t_num[i + 1] + 1;
		}
		else {
			t_num[i] = t_num[i + 1];
		}
	}

	int sum = 0;
	for (int i = 0; i < len; i++) {
		if (s[i] == 'A') {
			sum += p_num[i] * t_num[i];
		}
	}

	printf("%d", sum % 1000000007);

	return 0;
}
