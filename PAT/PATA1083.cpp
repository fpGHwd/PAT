#include "stdafx.h"
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define NAME_MAX 10
#define N_MAX 1000 // to be understood

static struct record_pata1083 { // static -> student
	char name[NAME_MAX+1], id[NAME_MAX+1];
	int score;
}student[N_MAX];

static int N;

static bool cmp(struct record_pata1083 a, struct record_pata1083 b) {
	return a.score > b.score;
}

int PATA1083() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s %s %d", student[i].name, student[i].id, &student[i].score);
	}

	sort(&student[0], &student[N], cmp);

	int min, max, count = 0;
	scanf("%d%d", &min, &max);

	for (int i = 0; i < N; i++) {
		if (student[i].score >= min && student[i].score <= max) {
			printf("%s %s", student[i].name, student[i].id/*student[i].score*/);
			count++;
			if (student[i+1].score >= min)printf("\n");
			count++;
		}	
	}
	if (count == 0) {
		printf("NONE");
	}

	return 0;
}