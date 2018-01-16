#include "stdafx.h"
#include <cstring>
#include <cstdlib>

#define MAX 100

char num[MAX+1]; // N <= 10^100
char tra[][6] = { "zero","one", "two", "three", "four", "five", "six","seven", "eight", "nine" }; // define error: char *tra[] or char tar[][6]

int PATA1005() {

	int ret = 0, len, result[3];
	gets_s(num); // when run in PAT-OJ use gets

	len = strlen(num);
	for (int i = 0; i < len; i++) {
		ret += num[i] - '0';
	}
	int count = 0;
	do {  // when zero consist of
		result[count] = ret % 10;
		count++;
		ret = ret / 10;
	} while (ret);

	for (int i = count -1; i >= 0; i--) { // i++ -> i--
		printf("%s", tra[result[i]]);
		if (i != 0)printf(" ");
	}

	return 0;
}