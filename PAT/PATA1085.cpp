#include "stdafx.h"
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_NUM 100000
static int sequence[MAX_NUM];
static bool cmp(int a, int b) {
	return a < b;
}

int PATA1085() {
	freopen("input.txt", "r", stdin);
	int n, p;
	scanf("%d%d", &n, &p);
	for (int i = 0; i < n; i++) {
		scanf("%d", &sequence[i]);
	}
	sort(sequence, sequence + n, cmp);

	//int k;
	int end, k = 1, mid, front; // k = 0 -> k = 1 // contains only one element in the sequence
	for (int i = 0; i < n; i++) {
		front = i;
		end = n;
		while (front+1 < end) { // front < end -> front +1 < end
			mid = (front + end) / 2; // front and end change discipline is also important
			if ((long long)sequence[i] * p >= sequence[mid]) { // front is fit and mid is not fit: OK // -> long long // 
				front = mid;
			}
			else {
				end = mid;
			}
		}
		if (front - i +1 > k)k = front - i + 1;
		
		//int j = upper_bound(sequence + i + 1, sequence + n, (long long)sequence[i] * p) - sequence;
		//k = max(k, j - i);
	}

	printf("%d", k);
	
	return 0;
} // last point AC : (long long)(sequence[i] * p >= sequence[mid]) // and pastwards I was right