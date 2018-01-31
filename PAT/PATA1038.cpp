#include "stdafx.h"
#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

#define SEGMENTS 10000
#define DIGITS_MAX 8

static string input[SEGMENTS];

static bool cmp(string a, string b) {
	return a + b < b + a; // every string is not the same
}
// vector?
int PATA1038() {
	freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}

	sort(input, input + n , cmp);
	string ans;
	int i = 0;
	while (i < n) {
		ans += input[i++];
	}

	//string::iterator it = ans.begin();
	while (ans.size() > 0 && ans[0] == '0')
		ans.erase(ans.begin());

	/*
	for (int i = 0; i < ans.size(); i++) {
		printf*()
	}*/
	if (ans.size() == 0)cout << 0; // AC 3 point
	cout << ans;

	return 0;
}
