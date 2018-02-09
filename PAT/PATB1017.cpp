#include "stdafx.h"
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_HASH_VALUE 26*26*26*10+1  // vector of substance is put things into structure
vector<int> result[MAX_HASH_VALUE];

int index(char *name) {
	int res = 0;
	for (int i = 0; i < 4; i++) {
		if (i != 3)
			res = res *26 + (name[i] - 'A');
		else
			res = res *10 + (name[i] - '0');
	}
	return res;
}

int PATB1017() {
	freopen("input.txt", "r", stdin);
	int r, c;
	scanf("%d%d", &r, &c);

	for (int i = 0; i < c; i++) {
		int idx, stu;
		scanf("%d%d", &idx, &stu);
		for (int j = 0; j < stu; j++) {
			char temp[5];
			scanf("%s", temp);
			int h = index(temp);
			result[h].push_back(idx);
		}
	}

	for (int i = 0; i < r; i++) {
		char temp[5];
		scanf("%s", temp);
		if (i != 0)
			printf("\n");
		printf("%s", temp);
		int h = index(temp);
		sort(result[h].begin(), result[h].end());
		int k = result[h].size();
		printf(" %d", k);
		for (int j = 0; j < k; j++) {
			printf(" %d", result[h][j]);
		}
	}

	return 0;
}