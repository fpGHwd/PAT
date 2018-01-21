#include "stdafx.h"
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define STU_MAX 40000
#define SCHOOL_MAX 100
#define CHOICES 5

static struct record_pata1080{
	int idx, GE, GI, choices[CHOICES], rank, admit_school; // rank may have meaning
	float final;
}stu[STU_MAX];
static int N, M, K, schools[SCHOOL_MAX], choices[SCHOOL_MAX][STU_MAX], school_admitted[SCHOOL_MAX] = {0};

static bool cmp(struct record_pata1080 a, struct record_pata1080 b)
{
	if (a.final != b.final) {
		return a.final > b.final;
	}
	else {
		if (a.GE != b.GE) {
			return a.GE > b.GE;
		}
		else {
			return a.idx < b.idx;
		}
	}
}

static bool cmp2(int a, int b) {
	return a<b;
}

int PATA1080() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < M; i++) {
		scanf("%d", &schools[i]);
		getchar();
	}
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &stu[i].GE, &stu[i].GI);
		getchar();
		for (int j = 0; j < K; j++) {
			scanf("%d", &stu[i].choices[j]);
			getchar();
		}
		stu[i].idx = i;
		stu[i].final = (stu[i].GE + stu[i].GI) * 1.0 / 2;
	}

	sort(&stu[0], &stu[N], cmp);

	stu[0].rank = 1;
	for (int i = 1; i < N; i++) {
		if (stu[i].final == stu[i - 1].final && stu[i].GE == stu[i - 1].GE) {
			stu[i].rank = stu[i - 1].rank;
		}
		else {
			stu[i].rank = i + 1;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			int s = stu[i].choices[j];
			if (schools[s] > 0) {
				choices[s][school_admitted[s]] = stu[i].idx;
				school_admitted[s]++;
				schools[s]--;
				stu[i].admit_school = s;
				break; // break here
			}
			else {
				if ((stu[i].rank == stu[i - 1].rank) && (s = stu[i - 1].admit_school)) { // ( ) is fatal // here logic: (choices[s][school_admitted[s]]) // todo: fatal logic
					choices[s][school_admitted[s]] = stu[i].idx;
					school_admitted[s]++;
					schools[s]--;
					stu[i].admit_school = s;
					break; // break here
				}
			}
		}
	}

	for (int i = 0; i < M; i++) {
		sort(&choices[i][0], &choices[i][school_admitted[i]], cmp2); // output: 4 1 -> 1 4
	}

	for (int i = 0; i < M; i++) {
		if (school_admitted[i] == 0) {
			printf("\n");
			continue;
		}
		for (int j = 0; j < school_admitted[i]; j++) {
			printf("%d", choices[i][j]);
			if (j != school_admitted[i] - 1) {
				printf(" ");
			}
			else {
				//if (i != M - 1)
					printf("\n");
			}
		}
	}

	return 0;
}