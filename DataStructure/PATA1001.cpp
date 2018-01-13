#include "stdafx.h" // #include<cstdio>

int PATA1001(void) { // main
	int a, b, c ,d;
	scanf("%d%d", &a, &b);
	c = a + b;
	if(c<0)
		d = -c;
	else {
		d = c;
	}
	int count = 0;
	while (d) {
		count++;
		d = d / 10;
	}
	/*
	int e = d;
	count = 0;
	while (e/3) {
		count++;
		e = e / 3;
	}*/
	int count1 = count;
	if (c < 0) {
		printf("-");
		c = -c;
	}
	else if(c == 0){
		printf("0");
		return 0;
	}
	int j = 1;
	while (count-- -1) {
		j = j * 10;
	}
	for (int i = count1; i > 0; i--) {
		if (i % 3 == 0 && count1 > i)printf(",");
		printf("%d", c / j);
		c = c % j;
		j = j / 10;
	}
	return 0;
}
