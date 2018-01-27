#include "stdafx.h"
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define USERS_MAX 10000
#define SUBMI_MAX 100000
#define PROBLEM_MAX 5

static int perfect_score[PROBLEM_MAX] = {0};
static struct record_pata1075 {
	bool flag; // reason is important
	int id;
	int score[PROBLEM_MAX], sum_s, perfect_solved;
	int solved;
}RECS[USERS_MAX+1]; // about initiate this structure

void initiate_records(void) {
	for (int i = 0; i <= USERS_MAX; i++) {
		for (int j = 0; j < PROBLEM_MAX; j++) {
			RECS[i].score[j] = -1;
		}
		RECS[i].id = i;
		RECS[i].sum_s = 0;
		RECS[i].perfect_solved = 0;
		RECS[i].flag = false;
	}
}

bool cmp(struct record_pata1075 a, struct record_pata1075 b) {
	/*
	if (a.sum_s != b.sum_s)
		return a.sum_s > b.sum_s;
	else {
		if (a.perfect_solved != b.perfect_solved)
			return a.perfect_solved > b.perfect_solved;
		else
			return a.id < b.id;
	}
	*/
	
	if (a.flag == true && b.flag == true) {
		if (a.sum_s != b.sum_s) {
			return a.sum_s > b.sum_s;
		}
		else {
			if (a.perfect_solved != b.perfect_solved)
				return a.perfect_solved > b.perfect_solved;
			else
				return a.id < b.id;
		}
	}
	else if (a.flag == true && b.flag == false) {
		return true;
	}
	else if (a.flag == false && b.flag == true)
		return false;
	else
		return a.id < b.id;
}

void print_score(int rank, int idx, bool last, int num_score) {
	printf("%d ", rank);

	// cannot calculate sum here, for sort's using sum_s;
	printf("%05d %d ", RECS[idx].id, RECS[idx].sum_s); // %06d -> %05d
	for (int i = 0; i < num_score; i++) {
		if (RECS[idx].score[i] == -1)
			printf("-");
		else
			printf("%d", RECS[idx].score[i]);
		if (i != num_score - 1)printf(" ");
		else
			if (!last)printf("\n");
	}
}

int PATA1075(void) {

	initiate_records();

	freopen("input.txt", "r", stdin);
	int m,n, k; // if unclear about m, may cause invalid call sort
	scanf("%d%d%d", &m, &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &perfect_score[i]);
	struct record_pata1075 temp;
	int id, pro,score;
	int count= 0; // equals to m
	for (int i = 0; i < k; i++) {
		scanf("%d %d %d", &id, &pro, &score);
		if (score != -1) {
			RECS[id].flag = true;
		}
		if (score == -1 && RECS[id].score[pro - 1] == -1)
			RECS[id].score[pro - 1] = 0;

		if (score == perfect_score[pro - 1] && RECS[id].score[pro - 1] < perfect_score[pro - 1]) {
			RECS[id].score[pro - 1] = score;
			RECS[id].perfect_solved++;
		}

		if (score > RECS[id].score[pro - 1] && score < perfect_score[pro - 1]) { // inherit info from up "if"
			RECS[id].score[pro - 1] = score;
		}
		/*
		if (RECS[id].flag == false) { // put sum logic here will increase complexity of TOTAL
			if (score != -1) {
				RECS[id].flag = true;
				RECS[id].id = id;
				RECS[id].score[pro - 1] = score;
				RECS[id].sum_s += score;
				if (score == perfect_score[pro - 1])
					RECS[id].perfect_solved++;
			}
		}
		else {
			int temp_score = RECS[id].score[pro - 1];
			if (temp_score == -1) {
				if (score != -1) {
					RECS[id].score[pro - 1] = score;
					RECS[id].sum_s += score;
					if (score == perfect_score[pro - 1])
						RECS[id].perfect_solved++;
				}
				else
					RECS[id].score[pro - 1] = 0;
			}
			else {
				if (score > temp_score) {
					RECS[id].score[pro - 1] = score;
					RECS[id].sum_s += (score - temp_score);
					if (score == perfect_score[pro - 1])
						RECS[id].perfect_solved++;
				}
			}
		}
		*/
		/*
		if (score > RECS[id].score[pro - 1]) {
			if (RECS[id].flag == false) {
				RECS[id].flag = true;
				RECS[id].id = id;
				RECS[id].sum_s += score;
				count++;
			}
			else {
				if (RECS[id].score[pro - 1] == -1) {
					RECS[id].sum_s += score;
				}
				else {
					RECS[id].sum_s += (score - RECS[id].score[pro - 1]);
				}
			}
			RECS[id].score[pro - 1] = score;

			if (score == perfect_score[pro - 1])
				RECS[id].perfect_solved++;
		} 
		else
			if(RECS[id].flag == true && score == -1 && RECS[id].score[pro-1] ==-1 )
				RECS[id].score[pro-1] = 0; // no solution pass the compiler will not be shown on the list
				*/
	}

	for (int j = 0; j < USERS_MAX; j++) {
		if (RECS[j].flag) {
			int tem_sum = 0;
			for (int i = 0; i < PROBLEM_MAX; i++) {
				if (RECS[j].score[i] != -1)
					tem_sum += RECS[j].score[i];
			}
			RECS[j].sum_s = tem_sum;
		}
	}


	sort(&RECS[0], &RECS[USERS_MAX], cmp); // fatal: sort -> runtime error caused by record multiple defined in other files before, and vanished after rename struct record of this file

	int rank = 1;
	print_score(1, 0, false, n);
	for (int i = 1; i < USERS_MAX; i++) {
		if (RECS[i].sum_s != RECS[i - 1].sum_s)
			rank = i + 1;
		if (RECS[i + 1].flag == false) {
			print_score(rank, i, true, n);
			break; // this break count on the sort function form and content
		}
		else
			print_score(rank, i, false, n);
	}

	return 0;
}
