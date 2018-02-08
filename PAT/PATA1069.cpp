#include "stdafx.h"
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int big(int num) {
	vector<int> a;
	a.push_back(num / 1000);
	a.push_back(num / 100 % 10);
	a.push_back(num / 10 % 10);
	a.push_back(num % 10);
	sort(a.begin(), a.end());
	return a[3] * 1000 + a[2] * 100 + a[1] * 10 + a[0];
}

int small(int num) {
	vector<int> a;
	a.push_back(num / 1000);
	a.push_back(num / 100 % 10);
	a.push_back(num / 10 % 10);
	a.push_back(num % 10);
	sort(a.begin(), a.end());
	return a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
}

int PATA1069() {
	freopen("input.txt", "r", stdin);
	/*
	int num;
	scanf("%d", &num);
	int a = big(num);
	int b = small(num);
	int c = a - b;
	if (c == num)
		printf("%04d - %04d = %04d\n", a, b, c);
	else
	while (c != 6174) {
		printf("%04d - %04d = %04d\n", a, b, c);
		a = big(c);
		b = small(c);
		c = a - b;
	}
	*/
	int num = 0;
	scanf("%d", &num);
	int b = big(num);
	int s = small(num);
	int newnum = b - s;
	if (num == newnum)
		printf("%04d - %04d = %04d\n", b, s, newnum);
	while (num != newnum) {
		printf("%04d - %04d = %04d\n", b, s, newnum);
		num = newnum;
		b = big(num);
		s = small(num);
		newnum = b - s;
	}
	return 0;
}

/*
bool isSame(char *a, char *b) {
	for (int i = 0; i < 4; i++) {
		if (a[i] != b[i])
			return false;
	}
	return true;
}

bool cmp1(char a, char b) {
	return a < b;
}

bool cmp2(char a, char b) {
	return a > b;
}

void show_s(char *a) {
	for (int i = 0; i < 4; i++) {
		printf("%c", a[i]);
	}
}

int s_to_i(char *a) {
	int i = 0,ret = 0;
	while (i<4) {
		ret = ret *10 +  (a[i] - '0');
		i++;
	}
	return ret;
}

void i_to_s(int k, char *a) {
	int i = 4;
	while (i) {
		a[i-1] = k % 10 + '0';
		k = k / 10;
		i--;
	}
}

int PATA1069(void) {
	freopen("input.txt", "r", stdin);
	char s[5], temp[5]; // error: stack around the variable was corrupted, then 4->5
	
	scanf("%s", s);

	bool flag = true; // first flag

	do{
		for (int i = 0; i < 4; i++) {
			temp[i] = s[i];
		}
		sort(s, s + 4, cmp2);
		sort(temp, temp + 4, cmp1);
		if (!flag) {
			printf("\n");
		}
		flag = false;
		show_s(s);
		printf(" - ");
		show_s(temp);
		printf(" = ");
		i_to_s(s_to_i(s) - s_to_i(temp), s);
		show_s(s);
	} while (!isSame(s, "6174") && !isSame(s, "0000"));

	return 0;
} // not AC
*/
