#include "stdafx.h"
#include <cstdio>
#include <cmath>

using namespace std; // abs() function

int PATA1008() {
	freopen("input.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	int ans = 0, last = 0, stop;
	for (int i = 0; i < n; i++) {
		scanf("%d", &stop);
		if (stop > last) {
			ans += (stop - last) * 6 + 5;
		}
		else {
			ans += abs(stop - last) * 4 + 5; // last - stop is OK
		}
		last = stop;
	}

	printf("%d", ans);

	return 0;
}