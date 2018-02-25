// PAT A 1034

/*
TEST CASE 1
8 59
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10

OUTPUT1
2
AAA 3
GGG 3
*/

/*
TEST CASE 2
8 70
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10

OUTPUT2
0
*/

/*
Problem space & Solution space
G(V,E)
Algorithm space
pseudocode

*/

#include "stdafx.h"
#include <cstdlib>
#include <cstdio>
#include <map>
#include <cstring>
#include <string>

#define NAMESIZE 10
#define PHONELENGTH 1000+1
#define MAXN 2010

/*
map<int, string> intToString;
map<string, int> stringToInt;
map<string, int> Gangs;
int G[MAXN][MAXN] = { 0 }, weight[MAXN] = { 0 };
bool visited[MAXN] = { false };
int threthold, phonecalls;
int gang_num = 0;
int person_idx = 0;

int readData(string str) {
	if (stringToInt.find(str) != stringToIne.end()) {
		return stringToInt[str];
	}
	else {
		stringToInt[str] = person_idx;
		intToString[person_idx] = str;
		return person_idx++; //
	}
}

void DFS(int u) {
	visited[u] == true;

}

void DFSTravel(int u) {
	for (int i = 0; i < person_idx; i++) {
		if (visited[i] == false) {
			//DFS(int)
		}
	}
}

int PATA1034() {
	string name1, name2;

	cin >> threthold >> phonecalls;
	for (int i = 0; i < threthold; i++) {
		cin >> name1 >> name2 >> calltime;
		int i1 = change(name1);
		int i2 = change(name2);
		G[i1][i2] += calltime;
		G[i2][i1] += calltime;
		weight[i1] += calltime;
		weigth[i2] += calltime;
	}

}
*/
