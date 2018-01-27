#include "stdafx.h"
#include <cstdio>
#include <cstdlib>

// find the starting position of the common suffix
#define size 100010

struct Node {
	char data;
	int next;
	bool flag;
	Node() {
		flag = false;
	}
}node[size];

int first, second, n;

void get(void) {
	char c;
	int address, next;
	scanf("%d%d%d", &first, &second, &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %c %d", &address, &c, &next); // need blank
		node[address].data = c;
		node[address].next = next;
	}
}

int PATA1032() {

	get();

	int a = first;
	while (a != -1) {
		node[a].flag = true;
		a = node[a].next;
	}

	a = second;
	while (a != -1 && node[a].flag != true) {
		a = node[a].next;
	}

	if (a == -1 && node[a].flag != true)
		printf("-1");
	else
		printf("%05d", a);


	return 0;
}