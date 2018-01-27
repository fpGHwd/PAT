#include "stdafx.h"
#include <cstring>

#define ACCOUNT_MAX 1000 // N <= 1000
#define NAME_MAX 10

struct record{
	char name[NAME_MAX + 1], passwd[NAME_MAX +1];
}D[ACCOUNT_MAX];

bool modify(char *s) {
	int len = strlen(s);
	bool flag = false;
	for (int i = 0; i < len; i++) {
		switch(s[i]) {
		case '1':s[i] = '@'; flag = true; break;
		case '0':s[i] = '%'; flag = true; break;
		case 'l':s[i] = 'L'; flag = true; break;
		case 'O':s[i] = 'o'; flag = true; break;
		default:break;
		}
	}
	return flag;
}

int PATA1035() {

	int n, count= 0;
	struct record temp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s %s", temp.name, temp.passwd);
		if (modify(temp.passwd)) { // D[i].passwd -> temp.passwd
			D[count++] = temp; // assign vs memcpy
		}
	}

	if (count == 0) {
		printf("There %s %d %s and no account is modified\n", (n == 1) ? "is" : "are", n, (n == 1) ? "account" : "accounts");
	}
	else {
		//printf("There %s %d %s and %d %s is modified\n", (n == 1) ? "is" : "are", n, (n == 1) ? "account" : "accounts", count, (count == 1) ? "account" : "accounts");

		printf("%d\n", count);
		for (int i = 0; i < count; i++) {
			printf("%s %s\n", D[i].name, D[i].passwd);
		}
	}

	return 0;
}