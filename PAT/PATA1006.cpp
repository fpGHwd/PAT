#include "stdafx.h" // #include<cstdio>
// #include<string.h>

struct sign{
	char id[20];
	int hour, minute, second; // sign time // regardless of signin or signout
}first, last;

bool cmp(struct sign a, struct sign b) {
	if (a.hour != b.hour)
		return a.hour > b.hour;
	if (a.minute != b.minute)
		return a.minute > b.minute;
	return a.second > b.second;
}

int PATA1006(void) {
	int n;
	scanf("%d", &n);
	struct sign tmp;
	bool flag = false;
	for (int i = 0; i < n; i++) {
		scanf("%s %d:%d:%d", tmp.id, &tmp.hour, &tmp.minute, &tmp.second);
		if (flag) {
			if (!cmp(tmp, first)) {
				first = tmp;
			}
		}
		else {
			first = tmp;
			last = tmp;
			flag = true;
		}
		scanf("%d:%d:%d", &tmp.hour, &tmp.minute, &tmp.second);
		if (cmp(tmp, last)) {
			last = tmp;
		}
	}

	printf("%s %s\n", first.id, last.id);

	return 0;
}