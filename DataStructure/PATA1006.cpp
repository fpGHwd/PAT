#include "stdafx.h" // #include<cstdio>
// #include<string.h>

struct time_pat {
	int hour, minute, second;
};

struct sign{
	char id[20];
	struct time_pat signin, signout;
}first, last;

int cmptime(struct time_pat a, struct time_pat b) { // 
	if (a.hour > b.hour || (a.hour == b.hour && a.minute > b.minute) || (a.hour == b.hour && a.minute == b.minute && a.second > b.second)) {
		return 1;
	}
	else if(a.hour == b.hour && a.minute == b.minute && a.second == b.second){
		return 0;
	}
	else {
		return -1;
	}
}

int PATA1006(void) {
	int n;
	scanf("%d", &n);
	char id[20];
	struct time_pat signin, signout;
	for (int i = 0; i < n; i++) {
		scanf("%s %d:%d:%d", id, &signin.hour, &signin.minute, &signin.second);
		if (i == 0) {
			strcpy(first.id, id);
			first.signin.hour = signin.hour;
			first.signin.minute = signin.minute;
			first.signin.second = signin.second;
			strcpy(last.id, id);
			last.signin.hour = signin.hour;
			last.signin.minute = signin.minute;
			last.signin.second = signin.second;
		}
		else {
			if (cmptime(signin, first.signin) == -1) {
				strcpy(first.id, id);
				first.signin.hour = signin.hour;
				first.signin.minute = signin.minute;
				first.signin.second = signin.second;
			}
		}
		scanf("%d:%d:%d", &signout.hour, &signout.minute, &signin.second);
		if (cmptime(signin, last.signin) == 1) {
			strcpy(last.id, id);
			last.signin.hour = signin.hour;
			last.signin.minute = signin.minute;
			last.signin.second = signin.second;
		}
	}

	printf("%s %s\n", first.id, last.id);

	return 0;
}