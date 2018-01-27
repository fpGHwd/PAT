#include "stdafx.h"


#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define STU_MAX 40010
#define SCHOOL_MAX 110
#define CHOICES 6

static struct record_pata1080{
	int idx, GE, GI, choices[CHOICES], rank; // rank may have meaning
	float final;
}stu[STU_MAX];
static int N, M, K, schools[SCHOOL_MAX], choices[SCHOOL_MAX][STU_MAX], school_admitted[SCHOOL_MAX] = {0};

static bool cmp(struct record_pata1080 a, struct record_pata1080 b)
{
	if (a.GE+a.GI != b.GE+b.GI)
		return a.GE+a.GI > b.GE+b.GI;
	else
			return a.GE > b.GE;
}

static bool cmp2(int a, int b) {
	return a<b;
}

int PATA1080() {
	freopen("input2.txt", "r", stdin);
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < M; i++) {
		scanf("%d", &schools[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &stu[i].GE, &stu[i].GI);
		for (int j = 0; j < K; j++) {
			scanf("%d", &stu[i].choices[j]);
		}
		stu[i].idx = i;
	}

	sort(&stu[0], &stu[N], cmp);

	stu[0].rank = 1;
	for (int i = 1; i < N; i++) {
		if (stu[i].GE + stu[i].GI == stu[i - 1].GE + stu[i-1].GI && stu[i].GE == stu[i - 1].GE)
			stu[i].rank = stu[i - 1].rank;
		else
			stu[i].rank = i + 1;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			int s = stu[i].choices[j];
			if (schools[s] > 0) {
				choices[s][school_admitted[s]++] = stu[i].idx;
				schools[s]--;
				break;
			}
			else {
				/*
				if ((school_admitted[s] != 0) && (stu[choices[s][school_admitted[s] - 1]].rank == stu[i].rank)) {
					choices[s][school_admitted[s]++] = stu[i].idx;
					//schools[s]--;
					break;
				}
				*/
				if (school_admitted[s] != 0) {
					if ((stu[choices[s][school_admitted[s] - 1]].rank == stu[i].rank)) {
						choices[s][school_admitted[s]++] = stu[i].idx;
						schools[s]--;
						break;
					}
				}
			}
		}
	}
	/*
	for (int i = 0; i < M; i++) {
		sort(&choices[i][0], &choices[i][school_admitted[i]], cmp2); // output: 4 1 -> 1 4
		if (school_admitted[i] == 0)
			printf("\n");
		else {
			for (int j = 0; j < school_admitted[i]; j++) {
				printf("%d", choices[i][j]);
				if (j != school_admitted[i] - 1)
					printf(" ");
			}
			if (i != M - 1)
				printf("\n");
		}
	}*/


	for (int i = 0; i < M; i++) {
		sort(&choices[i][0], &choices[i][school_admitted[i]], cmp2);

		for (int j = 0; j < school_admitted[i]; j++) {
			if (j != 0)
				printf(" ");
			printf("%d", choices[i][j]);
		}
		printf("\n");
	}
	return 0;
} // todo: not AC



/*

#include <cstdio>  
#include <algorithm>  
#include <vector>  
using namespace std;

static struct Applicants {
	int id;
	int ge, gi;
	int sum;
	int choices[6];
} apt;

static bool cmp1(Applicants a1, Applicants a2) {
	if (a1.sum != a2.sum) {
		return a1.sum > a2.sum;
	}
	else {
		return a1.ge > a2.ge;
	}
}
static bool cmp2(Applicants a1, Applicants a2) {
	return a1.id < a2.id;
}
static int n, m, k;
static int quota[110];
static vector<Applicants> v, schools[110];

int PATA1080() {
	//freopen("input2.txt", "r", stdin);
	scanf("%d%d%d", &n, &m, &k);

	for (int i = 0; i < m; i++) {
		scanf("%d", &quota[i]);  
	}

	for (int i = 0; i < n; i++) {

		scanf("%d%d", &apt.ge, &apt.gi);
		apt.id = i;
		apt.sum = apt.ge + apt.gi;
		for (int j = 0; j < k; j++) {
			scanf("%d", &apt.choices[j]);
		}
		v.push_back(apt);
	}
	sort(v.begin(), v.end(), cmp1);

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < k; j++) {
			int choice = v[i].choices[j];
			if (schools[choice].size() < quota[choice]) {
				schools[choice].push_back(v[i]);
				break;
			}
			else {
				if (v[i].sum == schools[choice].back().sum && v[i].ge == schools[choice].back().ge) {
					schools[choice].push_back(v[i]);
					break;
				}
			}
		}
	}
	for (int i = 0; i < m; i++) {
		sort(schools[i].begin(), schools[i].end(), cmp2);
		for (int j = 0; j < schools[i].size(); j++) {
			if (j != 0)
				printf(" ");
			printf("%d", schools[i][j].id);
		}
		printf("\n");
	}
	return 0;
} // Answer Correct
*/

/*
#include<cstdio>  
#include<algorithm>  
#include<vector>   
#include<map>  
using namespace std;
int num[105];
struct node {
	int ge = 0;
	int gi = 0;
	int id;
	vector<int> add;
};
node t[40005];
int rate[40005];
map<int, vector<int> > ans;
bool cmp(const node& a, const node& b) {
	if (a.ge + a.gi != b.ge + b.gi) return a.ge + a.gi > b.ge + b.gi;
	return a.ge > b.ge;
}
bool cmp1(int a, int b) {
	return t[a].id < t[b].id;
}
int PATA1080()
{
	freopen("input2.txt", "r", stdin);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; ++i) scanf("%d", num + i);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &t[i].ge, &t[i].gi);
		int temp;
		for (int j = 0; j < k; ++j) {
			scanf("%d", &temp);
			t[i].add.push_back(temp);
		}
		t[i].id = i;
	}
	sort(t, t + n, cmp);
	rate[0] = 1;
	for (int i = 1; i < n; ++i)
		if (t[i].ge + t[i].gi == t[i - 1].ge + t[i - 1].gi&&t[i].ge == t[i - 1].ge) rate[i] = rate[i - 1];
		else rate[i] = i + 1;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < k; ++j) {
				int s = t[i].add[j];
				if (num[s] != 0) {
					ans[s].push_back(i);
					num[s]--;
					break;
				}
				else if (num[s] == 0) {
					int len = ans[s].size();
					if (len != 0) {
						int la = ans[s][len - 1];
						if (rate[la] == rate[i]) {
							ans[s].push_back(i);
							break;
						}
					}
				}
			}
		}
		for (int i = 0; i < m; ++i) sort(ans[i].begin(), ans[i].end(), cmp1);
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < ans[i].size(); ++j) {
				if (j != 0) printf(" %d", t[ans[i][j]].id);
				else printf("%d", t[ans[i][j]].id);
			}
			printf("\n");
		}
		return 0;
}
*/
