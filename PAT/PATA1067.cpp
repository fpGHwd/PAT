#include "stdafx.h"
#include <cstdio>
#include <algorithm>

using namespace std;
#define MAX 100000
static int permutation[MAX], N = 0, hashTable[MAX]; // hashTable -> indexs: easy to understand

int PATA1067() {
	freopen("input.txt", "r", stdin);
	int temp;
	scanf("%d", &N);
	for(int i = 0; i< N; i++){
		scanf("%d", &temp);
		permutation[i] = temp;
		hashTable[temp] = i;
	}

	int /*index_0 = 0,*/ index_swap, count = 0, k = 1;
	//while (permutation[index_0] != 0)index_0++;
	while (true) {
		if (hashTable[0] == 0) {
			index_swap = k;
			while ((index_swap == hashTable[0] ||  hashTable[index_swap] == index_swap) && index_swap < N)index_swap++;
			if (index_swap >= N)break;
			else
				k = index_swap;
		}
		else {
			index_swap = hashTable[hashTable[0]]; // use hash and AC at 2 point(*3)
		}
		swap(permutation[index_swap], permutation[hashTable[0]]);
		swap(hashTable[permutation[hashTable[0]]], hashTable[0]); // here is tricky
		count++;
	}

	/*
	while (index_0) {
		index_swap = 0;
		while (permutation[index_swap] != index_0 && index_swap < N)index_swap++;
		if (index_swap == 0) {
			int temp = 1;
			while (permutation[temp] == temp && temp < N)temp++;
			if (temp < N && temp != index_0) {
				index_swap = temp;
			}
			else if (temp == index_0) {
				int temp2 = index_0+1;
				while (permutation[temp2] == temp2 && temp2 < N)temp2++;
				if (temp2 < N) {
					index_swap = temp2;
				}
				else {
					;
				}
			}else {
				break;
			}
		}
		swap(permutation[index_swap], permutation[index_0]);
		swap(index_0, index_swap);
		count++;
	}
	*/

	printf("%d",count);
	return 0;
}