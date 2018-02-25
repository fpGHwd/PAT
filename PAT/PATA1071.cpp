#include "stdafx.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <cctype>

using namespace std;

static map<string, int> ans;
static string save;

int PATA1071() {
	freopen("input.txt", "r", stdin);
	// one line
	getline(cin,save); // #include <iostream>
	int i = 0, len = save.length();
	string temp;
	while (i < len) {
		int j = i,front;
		while (j < len && !(isalpha(save[j])|| isdigit(save[j])))j++; // !isalpha(save[j])  ->  *(!isalpha(save[j])); // maybe not effect AC
		front = j;
		while (j < len && (isalpha(save[j]) || isdigit(save[j])))j++;
		if (j != front) {
			temp = save.substr(front, (j == len) ? (len - front) : (j - front));
			int len_temp = temp.length();
			for (int i = 0; i < len_temp; i++) {
				if (temp[i] >= 'A' && temp[i] <= 'Z') {
					temp[i] = temp[i] - 'A' + 'a';
				}
			}
			if (ans.find(temp) != ans.end()) {
				ans[temp]++;
			}
			else {
				ans[temp] = 1;
			}
		}
		i = j;
	}

	string s_max = ans.begin()->first;
	int c_max = ans.begin()->second;
	for (map<string, int>::iterator it = ans.begin(); it != ans.end(); it++) {
		if (it->second > c_max) {
			s_max = it->first;
			c_max = it->second;
		}
	}

	cout << s_max << " " << c_max << endl;

	return 0;
}