#include "stdafx.h"
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define KEY_THRESH 100001
#define NODE_MAXN 100000

struct node {
	int address;
	int data;
	int next;
	bool flag;
	node() {
		flag = false;
	}
}Node[NODE_MAXN];

// true stands for b's following a's
bool compare(node a, node b) {
	if (a.flag == true && b.flag == false)
		return true;
	else if (a.flag == true && b.flag == true) {

		return a.data < b.data;
	}
}

int PATA1052() {
	int n, head, address, key, next;
	scanf("%d%d", &n, &head);

	int count = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &address, &key, &next);
		Node[address].address = address;
		Node[address].data = key;
		Node[address].next = next;
		Node[address].flag = true;
		count++;
	}

	if (count == 0) {
		printf("0 -1");
		return 0;
	}

	sort(Node, Node + NODE_MAXN, compare);

	for (int i = 0; i < n - 1; i++) {
		Node[i].next = Node[i + 1].address;
	}
	Node[n - 1].next = -1;

	printf("%d %d\n", n, Node[0].address);
	int i;
	for (i = 0; i < n - 1; i++) {
		printf("%05d %d %05d\n", Node[i].address, Node[i].data, Node[i].next);
	}
	printf("%05d %d %d\n", Node[i].address, Node[i].data, Node[i].next);

	return 0;
}
