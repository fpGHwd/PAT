#include "stdafx.h"
#include <cstdio>
#include <algorithm>

using namespace std;

#define NTHRESH 100000
#define LTHRESH 60
#define HTHRESH 100

int N, L, H;
struct candidate {
	int id, vi, in; // set level
	int lev;
}D[NTHRESH];

bool cmp_class(struct candidate a, struct candidate b) {
	if (a.lev == b.lev) {
		int sum1 = a.vi + a.in, sum2 = b.vi + b.in;
		if (sum1 != sum2)
			return (sum1 > sum2);
		else // sum1 == sum2
			if (a.vi != b.vi)
				return a.vi > b.vi;
			else
				return a.id < b.id;
	}else
		return (a.lev < b.lev);
}

void set_level(struct candidate *a) {
	if (a->vi >= H && a->in >= H) {
		a->lev = 1;
	}
	else if (a->vi >= H && a->in < H) {
		a->lev = 2;
	}
	else if (a->vi >= a->in && a->vi < H) {
		a->lev = 3;
	}
	else {
		a->lev = 4;
	}
}

int PATA1062(void) {
	int count = 0;
	//freopen("input.txt", "r", stdin);
	scanf("%d%d%d", &N, &L, &H);
	struct candidate temp;
	for (int i = 0; i < N; i++) {
		scanf("%d%d%d", &temp.id, &temp.vi, &temp.in);
		if (temp.vi >= L && temp.in >= L) {
			set_level(&temp);
			D[count++] = temp;
		}
	}

	sort(&D[0], &D[count], cmp_class); // count - 1 -> count // fatal error

	printf("%d\n", count);
	if (count == 0)
		return 0;
	for (int i = 0; i < count; i++) {
		printf("%08d %d %d\n", D[i].id, D[i].vi, D[i].in);
	}

	return 0;
}
