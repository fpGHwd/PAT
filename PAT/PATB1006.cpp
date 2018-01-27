#include "stdafx.h"

int PATB1006() {
	int n, ret[3],count = 0;
	char C[3] = {'*', 'S', 'B' };
	scanf("%d", &n);
	for (int i = 0; i < 3 && n > 0; i++) {
		ret[i] = n % 10;
		n = n / 10;
		count++;
	}

	for (int i = count-1; i >=0 ; i--) {
		int j = 1;
		while (ret[i]--) {
			if (i != 0)printf("%c", C[i]);
			else printf("%d", j++);
		}
		/*
		switch (i)
		{
		case 2:
			while (ret[i]--)printf("B");
			break;
		case 1:
			while (ret[i]--)printf("S");
			break;
		case 0:
			while (ret[i]--)printf("%d", j++);
			break;
		default:
			break;
		}
		*/
	}
	return 0;
}