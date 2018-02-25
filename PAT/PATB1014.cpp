#include "stdafx.h"
// #include <cstdio>
// #include <cstring>
#include <cstring>

#define MAX 60

bool validA(char c) {
	return (c >= 'A' && c <= 'Z');
}

bool valida(char c) {
	return (c >= 'a' && c <= 'z');
}

bool valid0(char c) {
	return (c >= '0' && c <= '9');
}

char *day[7] = { "MON", "TUE", "WED","THU","FRI","SAT","SUN"}; // WEN -> WED

int PATB1014() { // todo
	char temp[4][MAX + 1];
	for (int i = 0; i < 4; i++) {
		scanf("%s", temp[i]);
	}
	int a, b, c, count = 0;
	for (int i = 0; i < MAX && i< strlen(temp[0]) && strlen(temp[1]); i++) {
		if (temp[0][i] == temp[1][i] && validA(temp[0][i]) ) {
			a = i;
			break;
		}
	}

	for (int i = a+1; i < MAX && i < strlen(temp[0]) && strlen(temp[1]); i++) {//a -> a+1 // understanding is also hard
		if (temp[0][i] == temp[1][i] && (validA(temp[0][i]) || valid0(temp[0][i]))) {
				b = i;
				break;
		}
	}

	for (int i = 0; i < MAX && i< strlen(temp[2]) && strlen(temp[3]); i++) {
		if (temp[2][i] == temp[3][i] && (valida(temp[2][i]) || validA(temp[2][i]))) { // must be 'a' ~ 'z'
			c = i;
			break;
		}
	}

	printf("%s ", day[temp[0][a] - 'A']);
	printf("%02d:%02d", (temp[0][b] >= '0' &&  temp[0][b] <= '9') ? (temp[0][b] - '0') : (temp[0][b] - 'A' + 10), c);

	return 0;
}