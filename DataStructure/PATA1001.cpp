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
	int count = 0, j = 1;
	while (d) {
		count++;
		d = d / 10;
		j *= 10;
	}
	if (c < 0) {
		printf("-");
		c = -c;
	}
	else if(c == 0){
		printf("0");
		return 0;
	}
	for (int i = count; i > 0; i--) {
		if (i % 3 == 0 && count > i)printf(",");
		j = j / 10;
		printf("%d", c / j);
		c = c % j;
		
	}
	return 0;
}
