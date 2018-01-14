#include "stdafx.h"
#include<cmath>

struct monetory {
	int galleon, sickle, knut;
}price, pay;

#define G_K (17*29)
#define S_K (29)

int PATB1037(void) {
	int charge;
	scanf("%d.%d.%d %d.%d.%d", &price.galleon, &price.sickle, &price.knut, &pay.galleon, &pay.sickle, &pay.knut);

	charge = pay.galleon * G_K + pay.sickle * S_K + pay.knut - (price.galleon* G_K + price.sickle* S_K + price.knut);
	printf("%d.%d.%d", charge / G_K, abs(charge%G_K / S_K), abs(charge% S_K)); // abs -> <stdlib.h> from visual studio

	/*
	if (pay.knut < price.knut)
		borrow = 1;
	else
		borrow = 0;
	charge.knut = pay.knut + (borrow?29:0) - price.knut; // () is fatal
	if (pay.sickle + (borrow?-1:0) < price.sickle) 
		borrow = 1;
	else
		borrow = 0;
	charge.sickle = pay.sickle + (borrow?17:0) - price.sickle;
	charge.galleon = pay.galleon - borrow - price.galleon;
	printf("%d.%d.%d", charge.galleon, charge.sickle, charge.knut);
	*/
	return 0;
}