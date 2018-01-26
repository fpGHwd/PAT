#include "stdafx.h"
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define MAX_COINS_NUM 100000
#define VALUE_MAX 1000
// use two pointers method
static int coins[MAX_COINS_NUM], coins_num, value;

static bool cmp(int a, int b) {
	return a < b;
}

int PATA1048() {
	freopen("input1.txt", "r", stdin);
	scanf("%d%d", &coins_num, &value);
	for (int i = 0; i < coins_num; i++) {
		scanf("%d", &coins[i]);
	}
	sort(coins, coins + coins_num, cmp);
	int front = 0, back = coins_num - 1;
	while (front != back) {
		if (coins[front] + coins[back] == value) {
			break;
		}
		else if (coins[front] + coins[back] < value) {
			front++;
		}
		else {
			back--;
		}
	}

	if (front == back) {
		printf("No Solution");
	}
	else {
		printf("%d %d", coins[front], coins[back]);
	}

	return 0;
}
