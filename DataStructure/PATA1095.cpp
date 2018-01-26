#include "stdafx.h"
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

#define RECORD_MAX 10000
#define PLATE_NUMBER_LENGTH 7

static struct record_pata1095 {
	char plate[PLATE_NUMBER_LENGTH + 1];
	int time, status;
}R[RECORD_MAX+10], valid_record[RECORD_MAX+10];
static int maxTime = -1, N, K; // 0 -> -1
map<string, int> parkTime;

static bool cmp(struct record_pata1095 a, struct record_pata1095 b) {
	int r = strcmp(a.plate, b.plate);
	if (r != 0)
		return r < 0;
	else
		return a.time < b.time;
}

static bool cmp_time(struct record_pata1095 a, struct record_pata1095 b) {
	return a.time < b.time;
}

int PATA1095() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &N, &K);
	char status[5];
	int hour, min, second;
	for (int i = 0; i < N; i++) {
		scanf("%s %d:%d:%d %s", R[i].plate, &hour, &min, &second, status);
		R[i].time = hour * 3600 + min * 60 + second; // to int
		if (strcmp(status, "in") == 0)
			R[i].status = 1; // to int
		else
			R[i].status = -1;
	}

	sort(R, R+N, cmp);

	int count = 0;
	for (int i = 0; i < N - 1; i++) { 
		if ((strcmp(R[i].plate, R[i+1].plate) == 0) && (R[i].status == 1) && (R[i + 1].status == -1)) { // i->i+1 
			valid_record[count++] = R[i];
			valid_record[count++] = R[i + 1];
			int t = R[i+1].time - R[i].time;
			if (parkTime.count(R[i].plate) == 0) {
				parkTime[R[i].plate] = 0;
			}
			parkTime[R[i].plate] += t;
			maxTime = max(maxTime, parkTime[R[i].plate]); // include <cstdlib>
		}
	}

	sort(valid_record, valid_record+count, cmp_time);
	
	int now = 0, numCar = 0;
	for (int i = 0; i < K; i++) {
		scanf("%d:%d:%d", &hour, &min, &second);
		int t = hour * 3600 + min * 60 + second;
		while ((now < count) && (valid_record[now].time <= t))
			numCar += valid_record[now++].status;
		printf("%d\n", numCar);
	}

	map<string, int>::iterator it; // map is a entity
	for (it = parkTime.begin(); it != parkTime.end(); it++) {
		if (it->second == maxTime) { // second
			printf("%s ", it->first.c_str());
		}
	}

	printf("%02d:%02d:%02d\n", maxTime / 3600, maxTime % 3600 / 60, maxTime % 60);

	return 0;
} // 4 timeout, then change compare function 156ms < 220ms
