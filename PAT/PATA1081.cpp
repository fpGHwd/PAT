#include "stdafx.h"
#include <cstdio>

#define N_MAX 100


static struct fractal {
	long long up, down;
};
/*
static void format(struct fractal a) { // no need
	if (a.down < 0) {
		a.down = -a.down;
		a.up = -a.up;
	}
}
*/

static int gcd(long long a, long long b) {
	return (b == 0) ? a : gcd(b, a%b); // not apparent understanding
}

static int lcm(long long a, long long b) {
	return a * b / gcd(a, b);
}

static void reduction(struct fractal &a) { // &
	long long n = gcd(a.up > 0?a.up:-a.up , a.down);
	if (n != 0) {
		a.up = a.up / n;
		a.down = a.down / n;
	}
}

static struct fractal add(struct fractal a, struct fractal b) {
	struct fractal ans;
	ans.down = lcm(a.down, b.down);
	ans.up = a.up * ans.down / a.down + b.up * ans.down / b.down;
	reduction(ans);
	return ans;
}

static void show(struct fractal a) {
	if (a.up == 0)
		printf("0");
	else {
		if (a.up < 0) {
			printf("-");
			a.up = -a.up;
		}
		if (a.up >= a.down) {
			printf("%lld", a.up / a.down);
			if (a.up % a.down) {
				printf(" %lld/%lld", a.up%a.down, a.down);
			}
		}
		else {
			printf("%lld/%lld", a.up%a.down, a.down);
		}
	}
}

int PATA1081() {
	freopen("input1.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	struct fractal ans, temp;
	ans.up = 0;
	ans.down = 1;
	for (int i = 0; i < n; i++) {
		scanf("%lld/%lld", &temp.up, &temp.down);
		ans = add(ans, temp);
	}
	show(ans);


	return 0;
}