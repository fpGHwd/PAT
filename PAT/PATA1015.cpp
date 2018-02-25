#include "stdafx.h"
#include <cstdio>
#include <cmath>

using namespace std;

static bool isPrime(int k) {
	if (k <= 1)return false;
	if (k == 2)return true; // if not ensure to save time
	int sqr = (int)sqrt(1.0 * k);
	for (int i = 2; i <= sqr; i++) {
		if (k%i == 0)return false;
	}
	return true;
}

int PATA1015() {
	freopen("input.txt", "r", stdin);
	int n, radix;
	while (scanf("%d", &n) != EOF && n > 0) {
		scanf("%d", &radix); // should read radix and then judge the n/prime, critical
		if (!isPrime(n)) { /// this is also a point(3, 0~3)
			printf("No\n");
			continue;
		}
		int save[20] = { 0 };
		int k = 0;
		while(n) {
			save[k++] = n % radix;
			n = n / radix;
		}
		int reverse = 0;
		for (int i = 0; i < k; i++) {
			reverse = reverse * radix + save[i];
		}
		
		if (isPrime(reverse))
			printf("Yes\n");
		else
			printf("No\n");		
	}
	return 0;
}
