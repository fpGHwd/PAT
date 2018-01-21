#include "stdafx.h"
#include <cstring>
#include <algorithm>

using namespace std;

#define N_MAX 100000

static int N, K,M;

static struct record_pata1055 {
	char name[9];
	int age, net_worth;
}wealthies[N_MAX];

bool cmp(struct record_pata1055 a, struct record_pata1055 b)
{
	if (a.net_worth != b.net_worth) {
		return a.net_worth > b.net_worth;
	}
	else {
		if (a.age != b.age) {
			return a.age < b.age;
		}
		else {
			return (strcmp(a.name, b.name) < 0);
		}
	}
	/*
	if (a.age != b.age) {
		return a.age < b.age;
	}
	else {
		if (a.net_worth != b.net_worth) {
			return a.net_worth > b.net_worth;
		}
		else {
			return strcmp(a.name, b.name) < 0;
		}
	}
	*/
}

int PATA1055() {
	//freopen("input.txt", "r", stdin);
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%s %d %d", wealthies[i].name, &wealthies[i].age, &wealthies[i].net_worth);
	}

	sort(&wealthies[0], &wealthies[N], cmp);

	int agemin, agemax, start, end, count;
	for (int i = 0; i < K; i++) {
		count = 0;
		scanf("%d%d%d", &M, &agemin, &agemax);
		bool flag = false;
		printf("Case #%d:", i + 1);
		for (int j = 0; j < N; j++) {
			if (wealthies[j].age <= agemax && wealthies[j].age >= agemin) {
				flag = true;
				printf("\n");
				printf("%s %d %d", wealthies[j].name, wealthies[j].age, wealthies[j].net_worth);
				count++;
			}
			if (count == M)
				break;
		}
		if (!flag) {
			printf("\nNone");
		}
		if (i != K - 1)
			printf("\n");
	}

	return 0;
}
