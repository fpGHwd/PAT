#include "stdafx.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
//#include <set>

using namespace std;

#define K_MAX 99
#define N_MAX 100
#define MAX 5000 // max = 4616 

static int store[MAX] = { 0 };
static int nums[K_MAX] = { 0 }, not_overlaped[K_MAX], count = 0;
//static set<int> s; // order is not needed

static bool cmp(int a, int b) {
	return a > b;
}

int PATB1005() {
	/*
	int max = 0;
	for (int i = 2; i <= 100; i++) {
		int temp = i;
		while (temp>1) {
			if (temp % 2)
				temp = temp * 3 + 1;
			temp = temp / 2;
			if (temp > max)
				max = temp;
		}
	}
	*/
	freopen("input.txt", "r", stdin);
	int k, temp;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &temp);
		nums[i] = temp;
		while (temp) {
			if (store[temp] < 2) {
				store[temp]++;
			}
			else {
				break;
			}
			if (temp % 2) {
				temp = temp * 3 + 1;
			}
			temp = temp / 2;
		}
	}
	
	int count = 0;
	for (int i = 0; i < k; i++) {
		if (store[nums[i]] == 1) {
			not_overlaped[count++] = nums[i];
		}
	}

	sort(not_overlaped, not_overlaped + count, cmp);
	
	for (int i = 0; i < count; i++) {
		printf("%d", not_overlaped[i]);
		if (i != count - 1)printf(" ");
	}


	return 0;
}