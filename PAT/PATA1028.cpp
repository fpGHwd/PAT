#include "stdafx.h"
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define N_MAX 100000

static int N, C;

static struct student {
	int id, score;
	char name[9];
}stu[N_MAX];

static bool cmp(struct student a, struct student b) {
	if (C == 1)
		return a.id < b.id;
	else if (C == 2)
		if (strcmp(a.name, b.name) == 0)
			return a.id < b.id; /// illustrate big sort and embedded small sort.
		else
			return strcmp(a.name, b.name) < 0;
	else
		if (a.score == b.score)
			return a.id < b.id;
		else
			return a.score < b.score;
}

int PATA1028(void) {
	//freopen("input.txt", "r", stdin);
	scanf("%d%d", &N, &C);
	struct student temp;
	for (int i = 0; i < N; i++) {
		scanf("%d %s %d", &temp.id, temp.name, &temp.score);
		stu[i] = temp;
	}

	sort(&stu[0], &stu[N], cmp);

	for (int i = 0; i < N; i++) {
		printf("%06d %s %d", stu[i].id, stu[i].name, stu[i].score);
		if (i != N - 1)
			printf("\n");
	}

	return 0;
}
