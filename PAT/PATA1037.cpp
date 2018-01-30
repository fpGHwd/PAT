#include "stdafx.h"
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define MAX 100000
#define VALUES_MAX (1<<30)

static int coupon[MAX + 1] = { 0 }, product[MAX + 1] = { 0 }, a, b;

static bool cmp(int a, int b) {
	return a < b;
}

int PATA1037() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &a);
	int temp;
	for (int i = 1; i <= a; i++) {
		scanf("%d", &temp);
		coupon[i] = temp;
		if (temp < 0) {
			coupon[0]++;
		}
	}
	scanf("%d", &b);
	for (int i = 1; i <= b; i++) {
		scanf("%d", &temp);
		product[i] = temp;
		if (temp < 0) {
			product[0]++;
		}
	}

	sort(coupon+1, coupon+a + 1, cmp);
	sort(product+1, product+b + 1, cmp);

	int i= 1, j=1, ans = 0;
	while (i <= a && j <= b && coupon[i] < 0  && product[i]  <  0) {
		ans += coupon[i] * product[j];
		i++;
		j++;
	}

	i = a;
	j = b;
	while (i >= 1 && j >= 1 && coupon[i] > 0 &&  product[j] > 0) {
		ans += coupon[i] * product[j];
		i--;
		j--;
	}

	printf("%d", ans);

	return 0;
}