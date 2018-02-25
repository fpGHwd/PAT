#include "stdafx.h"
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

//#define inf (1LL<<63)-1

#define MAX_DIGITS 10
static char a1[MAX_DIGITS + 1], a2[MAX_DIGITS + 1];

long long decade(char *s, long long radix) { // int radix -> long long radix
	long long temp = 0, temp1;
	int len = strlen(s), i = 0;
	while (i < len) {
		if (s[i] >= '0' && s[i] <= '9') {
			temp1 = s[i] - '0';
		}
		else {
			temp1 = s[i] - 'a' + 10;
		}
		temp = temp * radix + temp1;
		if (temp < 0 /*|| temp > inf*/)return -1; // if temp < 0, overflow, and should be the end = mid -1
		i++;
	}
	return temp;
}

int leastRadix(char *s) {
	int i = 2, len = strlen(s);
	for (int i = 0; i < len; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			if (s[i] - '0' + 1 > i)i = s[i] - '0' +1;
		}
		else {
			if (s[i] - 'a' + 1 > i)i = s[i] - 'a' + 1;
		}
	}
	return i;
}

int PATA1010() {
	freopen("input.txt", "r", stdin);
	int tag, radix;
	char *c1, *c2;
	scanf("%s %s %d %d", a1, a2, &tag, &radix);
	c1 = a1;
	c2 = a2;
	if (tag == 2) {
		swap(c1, c2);
	}

	long long dec = decade(c1, radix);
	long long front = leastRadix(c2), end = max(front, dec+1), mid; // dec+1 is when c2 is 1 and has the maximum radix
	long long tempt;
	bool flag = false;
	while (front <= end) {
		mid = (front + end) / 2;
		tempt = decade(c2, mid);
		if (tempt > dec || tempt == -1) { /// add || tempt == -1 -> tempt < 0 // tempt == -1 || temp < 0
			end = mid-1;
		}
		else if (tempt == dec) {
			flag = true;
			break;
		}
		else {
			front = mid+1; // when front + 1 == end, when goes here, then front = end, and mid then = end // if here is not satisfy, then flag = false
		}
	}

	if (flag)printf("%lld", mid); /// then 
	else
		printf("Impossible");


	return 0;
}
// 20180206 25-2=23
