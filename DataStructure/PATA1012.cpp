#include "stdafx.h"
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_STU 2000
#define MAX_STU_ID 999999

struct student_pata1012{
	int id;
	int C, M, E;
	int A;
}D[2000];

int stu_r[MAX_STU_ID+1][4] = {0}, m, n; // -1 or 0 // fast to find, not search everyone // 999999 -> 999999 + 1
char character[4] = { 'A','C','M', 'E' };

bool cmp_c(struct student_pata1012 a, struct student_pata1012 b) {
	return a.C > b.C;
}

bool cmp_m(struct student_pata1012 a, struct student_pata1012 b) {
	return a.M > b.M;
}

bool cmp_e(struct student_pata1012 a, struct student_pata1012 b) {
	return a.E > b.E;
}

bool cmp_a(struct student_pata1012 a, struct student_pata1012 b) {
	return a.A > b.A;
}

int PATA1012(void) {
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d%d",&D[i].id, &D[i].C, &D[i].M, &D[i].E);
		D[i].A = (D[i].C + D[i].M + D[i].E)/ 3;
	}	

	sort(&D[0], &D[n], cmp_a);
	stu_r[D[0].id][0] = 1;
	for (int i = 1; i < n; i++) {
		if (D[i].A == D[i - 1].A)
			stu_r[D[i].id][0] = stu_r[D[i - 1].id][0];
		else
			stu_r[D[i].id][0] = i + 1;
	}

	sort(&D[0], &D[n], cmp_c);
	stu_r[D[0].id][1] = 1;
	for (int i = 1; i < n; i++) {
		if (D[i].C == D[i - 1].C)
			stu_r[D[i].id][1] = stu_r[D[i-1].id][1];
		else
			stu_r[D[i].id][1] = i + 1;
	}

	sort(&D[0], &D[n], cmp_m);
	stu_r[D[0].id][2] = 1;
	for (int i = 1; i < n; i++) {
		if (D[i].M == D[i - 1].M)
			stu_r[D[i].id][2] = stu_r[D[i - 1].id][2];
		else
			stu_r[D[i].id][2] = i + 1;
	}

	sort(&D[0], &D[n], cmp_e);
	stu_r[D[0].id][3] = 1;
	for (int i = 1; i < n; i++) {
		if (D[i].E == D[i - 1].E)
			stu_r[D[i].id][3] = stu_r[D[i - 1].id][3];
		else
			stu_r[D[i].id][3] = i + 1;
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