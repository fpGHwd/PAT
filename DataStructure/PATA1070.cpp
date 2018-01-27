#include "stdafx.h"
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_SPECIES 1000
#define NEED_THRESHOLD 500

static int species;
static float need; // stock is stock
static struct cake{
	float weight, price;
}cakes[MAX_SPECIES];

static bool cmp(cake a, cake b) {
	return (a.price / a.weight) > (b.price/ b.weight);
}

int PATA1070() {
	freopen("input.txt", "r", stdin);
	scanf("%d%f", &species, &need);
	for (int i = 0; i < species; i++) {
		scanf("%f", &cakes[i].weight); //float
	}

	for (int i = 0; i < species; i++) {
		scanf("%f", &cakes[i].price); // float
	}

	sort(cakes, cakes + species, cmp);

	float pay = 0;
	int i = 0;
	while (need > 0 && i<species) {
		if (cakes[i].weight < need) {
			pay += cakes[i].price;
			need -= cakes[i].weight;
		}
		else {
			pay += cakes[i].price*1.0 / cakes[i].weight * need;
			need = 0;
		}
		i++;
	}

	printf("%.2f", pay);

	return 0;
}
