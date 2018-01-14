#include "stdafx.h"

#define ABSENT "Absent"
#define NA "NA"

struct record{
	char name[11]; // no more than 10 characters
	char ID[11];
	int score;
}boy_lowest, girl_highest;

int dif;

int PATA1036(void) {
	int n;
	struct record tmp;
	char g;
	bool boy = false, girl = false;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s %c %s %d", tmp.name, &g, tmp.ID, &tmp.score);
		if (g == 'M') {
			if (boy == false) {
				boy_lowest = tmp;
				boy = true;
			}
			else {
				if (tmp.score < boy_lowest.score) {
					boy_lowest = tmp;
				}
			}
		}
		else {
			if (girl == false) {
				girl_highest = tmp;
				girl = true;
			}
			else {
				if (tmp.score > girl_highest.score) {
					girl_highest = tmp;
				}
			}
		}
	}

	if (girl) {
		printf("%s %s\n", girl_highest.name, girl_highest.ID);
	}
	else {
		printf("Absent\n");
	}
	if (boy) {
		printf("%s %s\n", boy_lowest.name, boy_lowest.ID);
	}
	else {
		printf("Absent\n");
	}
	if (girl && boy) {
		printf("%d", girl_highest.score - boy_lowest.score);
	}
	else {
		printf("NA\n");
	}
	

	return 0;
}