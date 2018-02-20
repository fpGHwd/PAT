#include "stdafx.h"
#include <cstdio>
#include <map>
#include <string>
#include <set>
#include <iostream>

using namespace std;

static map<string, set<int>> mpTitle, mpAuthor, mpKey, mpPub, mpYear;

static void query(map<string, set<int>> &mp, string q_key) { // timeout here
	if (mp.find(q_key) == mp.end())printf("\nNot Found");
	else
		for (set<int>::iterator it_s = mp[q_key].begin(); it_s != mp[q_key].end(); it_s++)
			printf("\n%07d", *it_s);
}

int PATA1022() {
	freopen("input.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	string title, author, keyword, pub, year; 
	int id;
	for (int i = 0; i < n; i++) {
		scanf("%d", &id);
		char c = getchar();
		getline(cin, title);
		mpTitle[title].insert(id);
		getline(cin, author);
		mpAuthor[author].insert(id);
		while (cin >> keyword) {
			mpKey[keyword].insert(id);
			c = getchar();
			if (c == '\n')break;
		}
		getline(cin, pub);
		mpPub[pub].insert(id);
		getline(cin, year);
		mpYear[year].insert(id);
	}

	int inquiry;
	string temp;
	scanf("%d", &inquiry);
	getchar();
	for (int i = 0; i < inquiry; i++) {
		getline(cin, temp);
		if (i != 0)
			cout << endl;
		cout << temp;
		string temp1 = temp.substr(3, temp.length() - 3);
		switch (temp[0])
		{
		case '1':query(mpTitle, temp1); break;
		case '2':query(mpAuthor, temp1); break;
		case '3':query(mpKey, temp1); break;
		case '4':query(mpPub, temp1); break;
		case '5':query(mpYear, temp1); break;
		default:
			break;
		}
	}
	return 0;
}
// timeout:4/[0-4] point
