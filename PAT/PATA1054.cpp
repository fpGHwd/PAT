#include "stdafx.h"
#include <cstdio>
#include <cstdlib>
#include <map>

using namespace std;

static map<int, int> ans;

int PATA1054() {
	int m, n, temp;
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &temp);
			if (ans.find(temp) != ans.end())ans[temp]++;
			else
				ans[temp] = 1;
		}
	}

	int k = 0, max = 0;
	for (map<int, int>::iterator it = ans.begin(); it != ans.end(); it++) {
		if (it->second > max) {
			k = it->first;
			max = it->second;
		}
	}
	printf("%d", k);

	return 0;
}