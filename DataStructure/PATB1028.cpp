#include "stdafx.h" // #include<cstdio> #include<cstring>

#define CURRENTDATE 20140906
#define NAMEMAX 10
#define N 100000

struct man{
	char name[NAMEMAX];
	int year, month, day;
}D[N]; // reduce occupied memory
int oldest = 0, youngest = 0;

int older(man *a, man *b) {
	if (a->year < b->year) {
		return 1;
	}
	else if(a->year == b->year) {
		if (a->month < b->month) { //
			return 1;
		}
		else if (a->month == b->month) {
			if (a->day < b->day) { // b->year -> b->day
				return 1;
			}
			else if(a->day == b->day){
				return 0; // no a->day == b->day
			}
			else {
				return -1;
			}
		}
		else {
			return -1;
		}
	}
	else {
		return -1;
	}
}

man left = {
	"LEFT",1814,9,6
};
man right = {
	"RIGHT", 2014, 9,6
};

int PATB1028(void) { // int main(void){return 0;}
	int n, y,m,d, count =  0;
	scanf("%d", &n);
	char s[NAMEMAX];
	for (int i = 0; i < n; i++) {
		scanf("%s %d/%d/%d", s, &y, &m, &d);
		strcpy(D[i].name, s);
		D[i].year = y;
		D[i].month = m;
		D[i].day = d;
		if ( (older(&D[i], &right)!= -1)  && (older(&D[i], &left) != 1)) {
			count++;
			if (count == 1) {
				oldest = i;
				youngest = i;
			}
			else if (count != 0) {
				if (older(&D[i], &D[oldest]) != -1) {
					oldest = i;
				}
				if (older(&D[i], &D[youngest]) != 1) {
					youngest = i;
				}
			}
		}
	}

	if (count == 0) {
		printf("0");
		return 0;
	}
	else {
		printf("%d %s %s", count, D[oldest].name, D[youngest].name);
	}
	

	return 0;
}