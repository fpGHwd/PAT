#include "stdafx.h"
#include <cstdio>
#include <algorithm>

#define MAX_N 100000

static int diamonds[MAX_N];
static int sum_value[MAX_N] = {0};
static int least_indexs[MAX_N][2] = { 0 }, least_sum = 0;

int PATA1044(void) {
	freopen("input.txt", "r", stdin);
	int N, M;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &diamonds[i]);
		if (i == 0)
			sum_value[i] = diamonds[i];
		else
			sum_value[i] = sum_value[i - 1] + diamonds[i];
	}

	int front, end, sum = 0, mid, count =0, least = -1;
	for (int i = 0; i < N; i++) {
		front = i;
		end = N-1;
		while (front <= end) {
			mid = (front + end) / 2;
			sum = sum_value[mid] - ((i == 0) ? 0 : (sum_value[i - 1]));
			if (sum < M) {
				front = mid + 1;
			}
			else if (sum == M) {
				if (count != 0) {
					printf("\n");
				}
				printf("%d-%d", i+1, mid+1); // i -> i+1; mid -> mid +1
				count++;
				break;
			}
			else {
				int temp = sum - M;
				if (least_sum == 0) {
					least = temp;
					least_indexs[least_sum][0] = i;
					least_indexs[least_sum][1] = mid;
					least_sum++;
				}
				else {
					if (temp <= least) {
						if (least != temp) {
							least_sum = 0;
							least = temp;
						}
						least_indexs[least_sum][0] = i;
						least_indexs[least_sum][1] = mid;
						least_sum++;
					}
				}
				end = mid - 1;
			}
		}
	}

	if(count == 0)
		for (int i = 0; i < least_sum; i++) {
			if (i != 0)
				printf("\n");
			printf("%d-%d", least_indexs[i][0] + 1, least_indexs[i][1] + 1);
		}

	return 0;
}