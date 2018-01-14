#include "stdafx.h"

char RGB_MACRO[13] = { '0', '1','2', '3', '4', '5', '6', '7', '8', '9', 'A','B','C' };

void n2rgb(int n, char RGB[2]) {
	RGB[0] = RGB_MACRO[n / 13];
	RGB[1] = RGB_MACRO[n % 13];
}

int PATA1027() {
	int a, b, c;
	char rgb[6];
	scanf("%d%d%d", &a, &b, &c);
	n2rgb(a, &rgb[0]);
	n2rgb(b, &rgb[2]);
	n2rgb(c, &rgb[4]);
	printf("#");
	for (int i = 0; i < 6; i++) {
		printf("%c", rgb[i]);
	}
	return 0;
}