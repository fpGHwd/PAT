#include "stdafx.h"
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define TANK_CAPACITY_MAX 100
#define HANGZ_DEST 30000
#define PER_UNIT_GAS_AVG 20
#define GAS_STATIONS_MAX 500

static struct stations {
	float unit_gas_price, distance;
	bool choose;
}sta[GAS_STATIONS_MAX+1];

static bool cmp(struct stations a, struct stations b) {
	return a.distance < b.distance;
}

void opt(struct stations *a, struct stations *b) {
	if (b - 1 != a) {

	}
}

int PATA1033() {
	freopen("input.txt", "r", stdin);
	float cap, dis, avg;
	int n;
	scanf("%f%f%f%d", &cap, &dis, &avg, &n);
	float temp;
	for (int i = 0; i < n; i++) {
		scanf("%f%f", &sta[i].unit_gas_price, &sta[i].distance);
		sta[i].choose = false;
	}
	sta[n].distance = dis;
	sort(sta, sta + n+1, cmp);
	int k = 0;
	for (int i = 0; i < n + 1; i++) {
		if (sta[i].distance == dis) {
			k = i;
			break;
		}
	}
	opt(sta, sta+k);

	return 0;
}