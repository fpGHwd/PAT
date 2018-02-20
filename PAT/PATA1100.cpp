#include "stdafx.h"
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <string>
#include <iostream>
#include <cctype>

using namespace std;

static string low_ref[13] = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
static string high_ref[13] = { "tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };

map<string, int>string2integer;

int PATA1100() {
	freopen("input1.txt", "r", stdin);
	int n;
	//scanf("%d%*c", &n); // not seem before
	cin >> n;
	getchar();

	for (int i = 0; i < 13; i++) {
		string2integer[low_ref[i]] = i; // ref is ambiguous
		string2integer[high_ref[i]] = i * 13; // finally AC
	}
	
	string temp;
	int num;
	for (int i = 0; i < n; i++) {
		getline(cin, temp);
		if (isdigit(temp[0])) {
			num = 0;
			for (int j = 0; j < temp.length(); j++)
				num = num * 10 + temp[j] - '0';

			if (num / 13) { // finally AC
				if (num % 13) {
					cout << high_ref[num / 13] << " ";
					cout << low_ref[num % 13];
				}
				else {
					cout << high_ref[num / 13];
				}
			}
			else {
				cout << low_ref[num % 13];
			}
		}
		else {
			num = 0;
			if (temp.length() != 3) { // finally AC
				num = string2integer[temp.substr(0, 3)];
				num = num + string2integer[temp.substr(4, 3)];
			}
			else
				num = string2integer[temp];
			cout << num;
		}
		if (i < n - 1)
			cout << endl;
	}

	return 0;
}
