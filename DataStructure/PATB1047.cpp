#include "stdafx.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX_TEAMS 1000

static int team_score[MAX_TEAMS+1] = { 0 };

int PATB1047() {
	freopen("input.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	int member, team, score;
	for (int i = 0; i < n; i++) {
		scanf("%d-%d %d", &team, &member, &score);
		team_score[team] += score;
	}

	int max = 1;
	for (int i = 2; i < MAX_TEAMS + 1; i++) {
		if (team_score[i] > team_score[max]) {
			max = i;
		}
	}
	printf("%d %d", max, team_score[max]);

	return 0;
}