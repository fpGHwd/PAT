#include "stdafx.h"
#include <cstdio>
#include <set>

using namespace std;

#define MAX_SETS 50

set<int> s[MAX_SETS];

int PATA1063() {
	freopen("input.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	int num;
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		int temp;
		for (int j = 0; j < num; j++) {
			scanf("%d", &temp);
			s[i].insert(temp);
		}
	}

	scanf("%d", &num);
	int a, b;
	for (int i = 0; i < num; i++) {
		scanf("%d%d", &a, &b);
		int count = 0;
		set<int>::iterator it;
		for (it = s[a - 1].begin(); it != s[a-1].end(); it++) {
			if(s[b-1].find(*it) != s[b-1].end())
				count++;
		}
		if (i != 0)
			printf("\n");
		printf("%.1f%%", 100.0 * count / (s[a - 1].size() + s[b - 1].size() - count));
	}

	return 0;
}