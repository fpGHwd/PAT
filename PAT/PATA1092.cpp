#include "stdafx.h" // comment
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX_BALL 1000
#define ASCII_48_127 1000
static int balls_shops[ASCII_48_127] = { 0 }, balls_needs[ASCII_48_127] = {0};
static char balls_shop[MAX_BALL], balls_need[MAX_BALL];

int PATA1092() { // int main(){;}
	//freopen("input.txt", "r", stdin);
	bool contain = true;
	gets_s(balls_shop);
	int len1 = strlen(balls_shop);
	for (int i = 0; i < len1; i++) {
		balls_shops[balls_shop[i] - '0']++;
	}
	gets_s(balls_need);
	int len2 = strlen(balls_need);
	for (int i = 0; i < len2; i++) {
		balls_needs[balls_need[i] - '0']++;
	}
	int need = 0, more = 0;
	for (int i = 0; i < ASCII_48_127; i++) {
		if (balls_needs[i]) {
			if (balls_shops[i] < balls_needs[i]) {
				contain = false;
				need += balls_needs[i] - balls_shops[i];
			}
		}
	}
	printf("%s %d", contain ? "Yes" : "No", contain ? (len1 - len2) : need);

	return 0;
} // once AC
