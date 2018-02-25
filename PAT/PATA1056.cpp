#include "stdafx.h"
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_PROGRAMMERS 1000

static struct mice{
	int rank;
	int weight;
	int output_order;
	int result_order;
}result[MAX_PROGRAMMERS];

//static vector<int> init_order;

int PATA1056() {
	freopen("input.txt", "r", stdin);
	int np, ng;
	scanf("%d%d", &np, &ng);
	for (int i = 0; i < np; i++) {
		scanf("%d", &result[i].weight);
		result[i].output_order = i+1;
	}

	queue<int> order;
	int temp;
	for (int i = 0; i < np; i++) {
		scanf("%d", &temp);
		order.push(temp);
	}

	int now = 0, max_index, weight, count = order.size(), group = 0;
	int turn_left = order.size();
	int has_ranked = 0; // groups count
	int group;
	while (!order.empty()) {
		group = 0;
		while (turn_left) {
			group++;
			int index_temp = order.front();
			temp = result[index_temp].weight;
			order.pop();
			turn_left--;
			if (turn_left) {
				if (result[order.front()].weight > temp) {
					result[index_temp].rank = 
				}
				turn_left--;
				has_ranked++;
			}
			
			if (turn_left) {
				turn_left--;
				has_ranked++;
			}
			
		}
		turn_left = order.size();
	}

	return 0;
}