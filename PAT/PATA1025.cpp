#include "stdafx.h"
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define LOCATIONS_N 100
#define TESTEES 300

static struct record_pata1025 {
	char id[14];
	int score, location ,local_rank, all_rank;
}stu[LOCATIONS_N * TESTEES];

static bool cmp(struct record_pata1025 a, struct record_pata1025 b) {
	if (a.score != b.score)
		return a.score > b.score;
	else
		return strcmp(a.id,b.id) < 0; // should not use int 
}

//int sec[LOCATIONS_N] = { 0 };
int PATA1025(void) {
	//freopen("input.txt", "r", stdin);
	int n, m, k = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &m);
		for (int j = k; j <k + m; j++) {
			scanf("%s %d", stu[j].id, &stu[j].score);
			stu[j].location = i + 1;
		}
		sort(&stu[k], &stu[k + m], cmp);
		stu[k].local_rank = 1;
		for (int j = k+1; j < k + m; j++) {
			if (stu[j].score == stu[j - 1].score) {
				stu[j].local_rank = stu[j - 1].local_rank;
			}
			else {
				stu[j].local_rank = j - k + 1;
			}
		}
		k += m;
	}

	printf("%d\n", k);
	if (k == 0)
		return 0;

	sort(&stu[0], &stu[k], cmp);
	stu[0].all_rank = 1;
	printf("%s %d %d %d\n", stu[0].id, stu[0].all_rank, stu[0].location, stu[0].local_rank);
	for (int i = 1; i < k; i++) {
		if (stu[i].score == stu[i - 1].score) {
			stu[i].all_rank = stu[i - 1].all_rank;
		}
		else {
			stu[i].all_rank = i + 1;
		}
		printf("%s %d %d %d\n", stu[i].id, stu[i].all_rank, stu[i].location, stu[i].local_rank);
	}
	
	return 0;
}