#include "stdafx.h"
#include <cstdio>
#include <stack>
#include <vector>

using namespace std;

int PATA1051() {
	freopen("input.txt", "r", stdin);
	int m, n, k;
	scanf("%d%d%d", &m, &n, &k);
	for (int i = 0; i < k; i++) { 
		int temp;
		stack<int> st; // every time clean stack
		vector<int> ve(n+1); // // I import the array's complexity of its structure, and split it down to add code's complexity
		bool flag = true;
		for (int j = 0; j < n; j++)
			scanf("%d", &ve[j]);

		int candi = 1;
		for (int j = 0; j < n; j++) {
			st.push(j+1);
			if (st.size() > m)break;
			while (!st.empty() && st.top() == ve[candi-1]) {
				st.pop();
				candi++;
			}
		}

		if (i != 0)
			printf("\n");
		if (candi == n + 1)printf("YES");
		else
			printf("NO");

		/*
		for (int j = 0; j < n; j++) {
			scanf("%d", &temp); // not reading when break;
			if (!st.empty()) {
				if (st.top() == temp) {
					st.pop();
					continue;
				}
			}
			while (candi <= n && st.size() <= m && candi != temp) {
				st.push(candi++);
			}
			if ((candi <= n && st.size() > m) || (candi > n && st.size() <= m)) {
				flag = false;
				while (++j < n) {
					scanf("%d", &temp);
				}
				break;
			}
			else {
				st.push(candi++);
				if (st.size() > m) {
					while (++j < n)
						scanf("%d", &temp);
					flag = false;
					break;
				}
				continue;
			}
		}
		if (i != 0)
			printf("\n");
		if (flag)
			printf("YES");
		else
			printf("NO");
			*/
	}
	return 0;
}