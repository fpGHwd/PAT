#include "stdafx.h"
#include<cstring>

using namespace std;
#define MAXCHARNUM 80

int PATA1031(void) {
	char s[MAXCHARNUM + 1];
	int len;
	scanf("%s", s);
	len = strlen(s);
	int a, b, c;
	a = (len+2) / 3 -1;
	b = len - 2*a;
	for (int i = 0; i < a; i++) {
		printf("%c", s[i]);
		for (int j = 0; j < b - 2; j++) {
			printf(" ");
		}
		printf("%c\n", s[len - i-1]);
	}
	for (int i = 0; i < b; i++) {
		printf("%c", s[a+i]);
	}

	return 0;
}