#include "stdafx.h"
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX_COURSES 2500
#define MAX_STUDENTS 40000

static char students[MAX_STUDENTS][5];
vector<int> ans[MAX_COURSES+1];

static bool cmp(int a, int b) {
	return strcmp(students[a], students[b]) < 0;
}

int PATA1047() {
	freopen("input.txt", "r", stdin);
	int s, c;
	scanf("%d%d", &s, &c);

	for (int i = 0; i < s; i++) {
		scanf("%s", students[i]);
		int co;
		scanf("%d", &co);
		int idx;
		for (int j = 0; j < co; j++) {
			scanf("%d", &idx);
			ans[idx].push_back(i);
		}
	}

	for (int i = 1; i <= c; i++) {
		if (i != 1)
			printf("\n");
		printf("%d %d", i, ans[i].size());
		sort(ans[i].begin(), ans[i].end(), cmp); // cmp here is important
		for (int j = 0; j < ans[i].size(); j++) {
			printf("\n%s", students[ans[i][j]]);
		}
	}

	return 0;
}
