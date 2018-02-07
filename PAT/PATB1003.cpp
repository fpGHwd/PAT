#include "stdafx.h"
#include <cstdio>
#include <cstring>


int PATB1003() {
	freopen("input.txt", "r", stdin);
	int n;
	char s[101];
	scanf("%d", &n);
	getchar(); // \n with n, otherwise the i = 0, s = ""(very important)
	int p_loc=-1, t_loc= -1, len;
	for (int i = 0; i < n; i++) {
		gets_s(s);
		len = strlen(s);
		for (int j = 0; j < len; j++) {
			if (s[j] == 'P') {
				p_loc = j;
			}
			else if (s[j] == 'T') {
				t_loc = j;
			}
		}

		bool flag0 = false;
		if (!(p_loc == -1 || t_loc == -1)) {
			bool flag = true;
			for (int k = 0; k < len; k++) {
				if (k != p_loc && k != t_loc) {
					if (s[k] != 'A') {
						flag = false;
						break;
					}
				}
			}
			if (flag) {
				int b = t_loc - p_loc -1, a = p_loc, c = len - t_loc - 1; // HERE IS IMPORTANT
				while (b > 1) {
					b = b - 1;
					c = c - a;
				}
				if (b == 1 && c == a) {
					flag0 = true;
				}
			}
		}

		if (i != 0)printf("\n");
		if (flag0) {
			printf("YES");
		}
		else {
			printf("NO");
		}

	}
	return 0;
}