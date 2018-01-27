#include "stdafx.h"
#include <cstring>

#define M 9999
#define EXP 9999

int PATB1024() {
	char s[M + 1];
	char c1;
	scanf("%s", s);

	if (s[0] == '-')printf("-");

	int e = 0;
	while (s[e] != 'E')e++;
	int exp = 0, len = strlen(s);
	for (int i = e + 2; i < len; i++) {
		exp = exp * 10 + (s[i] - '0');
	}
	if (exp == 0) { // no need
		for (int i = 1; i < e; i++) {
			printf("%c", s[i]);
		}
		return 0;
	}

	if (s[e + 1] == '-') {
		printf("0.");
		for (int i = 0; i < exp - 1; i++) {
			printf("0");
		}
		printf("%c", s[1]);
		for (int i = 3; i < e; i++) {
			printf("%c", s[i]);
		}
	}
	else if (s[e + 1] == '+') {
		for (int i = 1; i < e; i++) {
			if (s[i] == '.')continue;
			printf("%c", s[i]);
			if (i == exp + 2 && e - 3 != exp)
				printf(".");
		}
		for (int i = 0; i < exp - (e - 3); i++) {
			printf("0");
		}
	} // no other else;

	/*
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == 'E')
			e = i;
	}
	*/



	/*
	int sign = 1, sign1 = 1, len1, len2, len;
	if (s[0] == '-'){
		sign = -1;
		c1 = s[1];
		len1= e-2;
	}
	else {
		c1 = s[0];
		//len1 = e - 1 - a;
	}
	if (s[e + 1] == '-') {
		sign = -1;
	}
	else {

	}
	*/
	return 0;
}