#include "stdafx.h" // #include <cstdio>
// #include <string.h>

#define N 100

int weight[17] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
char z2m[11] = { '1','0','X','9','8','7','6','5','4','3','2' };
bool valid(char *idno) {
	int sum = 0;
	for (int i = 0; i < 17; i++) {
		if (idno[i] <= '9' && idno[i] >= '0') // fatal not check
			sum += weight[i] * (idno[i] - '0');
		else
			return false;
	}
	if (idno[17] == z2m[sum % 11])
		return true;
	else
		return false;
}

int PATB1031() { // int main(){;}
	int n, count = 0;
	char PROBLEM[N][19];
	char tmp[19];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", tmp);
		if (!valid(tmp)) {
			strcpy(PROBLEM[count], tmp); // #include <cstring> // or unknown file -- not very clear
			count++;
		}
	}

	if (count == 0) {
		printf("All passed\n");
	}
	else {
		for (int i = 0; i < count; i++) {
			printf("%s\n", PROBLEM[i]);
		}
	}

	getchar();
	return 0;
}