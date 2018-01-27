#include "stdafx.h"
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define RECORD_NUM 1000
#define NAME_LEN 20

enum line {
	ON_LINE = 0,
	OFF_LINE,
};

static char customers[RECORD_NUM / 2][NAME_LEN + 1];
static int rate[24], n;
static struct record { // -> static
	char name[NAME_LEN + 1];
	int month, day, hour, min;
	enum line online;
}D[RECORD_NUM];

static bool cmp(struct record a, struct record b) {
	if (strcmp(a.name, b.name) == 0) {
		if (a.month != b.month) {
			return a.month < b.month;
		}
		else {
			if (a.day != b.day) {
				return a.day < b.day;
			}
			else {
				if (a.hour == b.hour) {
					return a.min < b.min;
				}
				else {
					return a.hour < b.hour;
				}
			}
		}
	}
	else {
		return (strcmp(a.name, b.name) < 0);
	}
}

int PATA1016() {
	//freopen("input.txt", "r", stdin);
	for (int i = 0; i < 24; i++) {
		scanf("%d", &rate[i]);
		getchar();
	}
	scanf("%d", &n);
	struct record temp;
	char l[10];
	for (int i = 0; i < n; i++) {
		scanf("%s %d:%d:%d:%d %s", temp.name, &temp.month, &temp.day, &temp.hour, &temp.min, l);
		if (strcmp(l, "on-line") == 0)
			temp.online = ON_LINE;
		else
			temp.online = OFF_LINE;
		D[i] = temp;
	}

	sort(&D[0], &D[n], cmp); // OK

	/*
	temp = D[0];
	for (int i = 1; i < n; i++) { // todo: print// do not lack info -- use array to save necessary info
		if (strcmp(D[i].name, temp.name) == 0) {
			if (D[i].online == OFF_LINE && D[i - 1].online == ON_LINE) {
				printf("%s %02d\n", D[i].name, D[i].month);
				int delta = D[i].day * 24 + D[i].hour * 60 + D[i].min - (D[i - 1].day * 24 + D[i - 1].hour * 60 + D[i - 1].min);
				printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", D[i - 1].day, D[i - 1].hour, D[i - 1].min, D[i].day, D[i].hour, D[i].min, delta);
				printf("Total amount: $%d\n", delta);
			}
		}
		else {
			temp = D[i];
		}
	}
	*/
	int online[RECORD_NUM] = {0};
	for (int i = 0; i < n; i++) {
		if (i + 1 < n &&  D[i].online == ON_LINE && D[i + 1].online && strcmp(D[i].name, D[i + 1].name) == 0) {
			online[i] = 1;
			i = i + 1; // and i++ -> i=i+2
		}
	}

	char *name_last = NULL;
	int sum = 0;
	for (int i = 0; i < RECORD_NUM; i++) {
		if (online[i] == 1) {
			if (name_last == NULL || strcmp(name_last, D[i].name) != 0) {
				if (name_last != NULL) {
					printf("Total amount: $%.2f\n", sum/100.0);
				}
				printf("%s %02d\n", D[i].name, D[i].month); // may has invalid call
				name_last = D[i].name;
				sum = 0;
			}
			int time = 0,delta = 0;
			struct record start = D[i], end = D[i + 1];
			while (start.day < end.day || start.hour < end.hour || start.min < end.min) { // refer: algorithm note
				start.min++;
				time++;
				delta += rate[start.hour];
				if (start.min == 60) {
					start.min = 0;
					start.hour++;
				}
				if (start.hour == 24) {
					start.hour = 0;
					start.day++;
				}
			}
			// calculate delta
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", D[i].day, D[i].hour, D[i].min, D[i + 1].day, D[i + 1].hour, D[i + 1].min, time, delta/100.0);
			sum += delta;
		}
	}
	printf("Total amount: $%.2f\n", sum / 100.0); // last one // when there is i which satisfies online[i]!= 0; if all i make online[i] = 0, then no this print(loosely)

	return 0;
}