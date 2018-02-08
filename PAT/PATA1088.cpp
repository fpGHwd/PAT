#include "stdafx.h"
#include <cstdio>
#include <cstdlib>

using namespace std;

static struct fractal {
	long long up, down;
}; // static can not pass compilation of PAT system

static long long gcd(long long a, long long b) {
	return (b == 0) ? a : gcd(b, a%b);
}

static void reduction(struct fractal &a) {
	long long g;
	if (a.down < 0) {
		a.down = -a.down;
		a.up = -a.up;
	}
	g = gcd(abs(a.up), a.down);
	a.up = a.up / g;
	a.down = a.down / g;
}

static struct fractal minus(struct fractal a, struct fractal b) {
	struct fractal c;
	c.up = a.up * b.down - b.up * a.down;
	c.down = a.down * b.down;
	reduction(c);
	return c;
}

static struct fractal add(struct fractal a, struct fractal b) {
	struct fractal c;
	c.up = a.up * b.down + b.up * a.down;
	c.down = a.down * b.down;
	reduction(c);
	return c;
}

static struct fractal multiple(struct fractal a, struct fractal b) {
	struct fractal c;
	c.up = a.up *  b.up;
	c.down = a.down * b.down;
	reduction(c);
	return c;
}

static struct fractal divide(struct fractal a, struct fractal b) { // ensure b.up != 0
	struct fractal c;
	c.up = a.up * b.down;
	c.down = a.down * b.up;
	reduction(c);
	return c;
}

static void show(struct fractal a) {
	if (a.up == 0) {
		printf("0");
	}
	else {
		int flag;
		if (a.up < 0) {
			flag = -1;
			printf("(-");
			a.up = -a.up;
		}
		else {
			flag = 1;
		}
		if (a.up > a.down) {
			printf("%lld", a.up / a.down);
			if (a.up % a.down) {
				printf(" %lld/%lld", a.up%a.down, a.down);
			}
		}
		else {
			if (a.down == 1)
				printf("%lld", a.up);
			else
				printf("%lld/%lld", a.up, a.down);
		}
		if (flag == -1)printf(")"); // flag is a STACK whose capacity is only 1 // so stack is the structure which is for unaccomplished tasks
	}
}

int PATA1088() {
	freopen("input.txt", "r", stdin);
	struct fractal a, b;
	scanf("%lld/%lld", &a.up, &a.down);
	scanf("%lld/%lld",&b.up, &b.down);
	reduction(a);
	reduction(b);
	show(a); printf(" + "); show(b); printf(" = "); show(add(a, b)); printf("\n");
	show(a); printf(" - "); show(b); printf(" = "); show(minus(a, b)); printf("\n");
	show(a); printf(" * "); show(b); printf(" = "); show(multiple(a, b)); printf("\n");
	show(a); printf(" / "); show(b); printf(" = "); if (b.up == 0)printf("Inf"); else show(divide(a, b));

	return 0;
}

//random test:  point 4: when a = 2/3 and b = -5/3, plus: 2/3 + -5/3 = (-1/1); // but pass in A1081(todo) // so problem is in show(a) when a = -1/1 
