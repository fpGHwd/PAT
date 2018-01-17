#include "stdafx.h"
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_STU 2000
#define MAX_STU_ID 999999

struct student_pata1012{
	int id;
	int score[4];
}D[2000];

int stu_r[MAX_STU_ID+1][4] = {0}, m, n; // -1 or 0 // fast to find, not search everyone // 999999 -> 999999 + 1
char character[4] = { 'A','C','M', 'E' };
int u;

bool cmp(struct student_pata1012 a, struct student_pata1012 b) {
	return a.score[u] > b.score[u];
}

int PATA1012(void) {
	//freopen("input.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d%d",&D[i].id, &D[i].score[1], &D[i].score[2], &D[i].score[3]);
		D[i].score[0] = (D[i].score[1] + D[i].score[2] + D[i].score[3])/ 3;
	}	

	for (u = 0; u < 4; u++) {
		sort(&D[0], &D[n], cmp);
		stu_r[D[0].id][u] = 1;
		for (int i = 1; i < n; i++) {
			if (D[i].score[u] == D[i - 1].score[u])
				stu_r[D[i].id][u] = stu_r[D[i - 1].id][u];
			else
				stu_r[D[i].id][u] = i + 1;
		}
	}

	int id;
	for (int i = 0; i < m; i++) {
		scanf("%d", &id);
		if (stu_r[id][0] == 0) {
			printf("N/A");
		}
		else {
			int k = 0;
			for (int j = 1; j <= 3; j++) {
				if (stu_r[id][j] < stu_r[id][k]) {
					k = j;
				}
			}
			printf("%d %c", stu_r[id][k], character[k]);
		}
		if (i != m - 1) {
			printf("\n");
		}
	}

	return 0;
}