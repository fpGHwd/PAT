#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>

//#define _CRT_SECURE_NO_WARNINGS

#define MAX 100
#define MAXCOST 0x7fffffff

int graph[MAX][MAX];

int Prim(int graph[][MAX], int n)
{

	/* lowcost[i]记录以i为终点的边的最小权值，当lowcost[i]=0时表示终点i加入生成树 */
	int lowcost[MAX];

	/* mst[i]记录对应lowcost[i]的起点，当mst[i]=0时表示起点i加入生成树 */
	int mst[MAX];

	int i, j, min, minid, sum = 0;

	lowcost[0] = 0;
	mst[0] = 0;

	/* 默认选择1号节点加入生成树，从2号节点开始初始化 */
	for (i = 1; i < n; i++)
	{
		/* 最短距离初始化为其他节点到1号节点的距离 */
		lowcost[i] = graph[0][i];

		/* 标记所有节点的起点皆为默认的1号节点 */
		mst[i] = 0;
	}

	/* 标记1号节点加入生成树 */
	mst[0] = 0;

	/* n个节点至少需要n-1条边构成最小生成树 */
	for (i = 1; i < n; i++)
	{
		min = MAXCOST;
		minid = 0;

		/* 找满足条件的最小权值边的节点minid */
		for (j = 1; j < n; j++)
		{
			/* 边权值较小且不在生成树中 */
			if (lowcost[j] < min && lowcost[j] != 0)
			{
				min = lowcost[j];
				minid = j;
			}
		}
		/* 输出生成树边的信息:起点，终点，权值 */
		printf("(%d,%d) : %d\n", mst[minid], minid, min);

		/* 累加权值 */
		sum += min;

		/* 标记节点minid加入生成树 */
		lowcost[minid] = 0;

		/* 更新当前节点minid到其他节点的权值 */
		for (j = 1; j < n; j++)
		{
			/* 发现更小的权值 */
			if (graph[minid][j] < lowcost[j] && lowcost[j] != 0)
			{
				/* 更新权值信息 */
				lowcost[j] = graph[minid][j];

				/* 更新最小权值边的起点 */
				mst[j] = minid;
			}
		}
	}
	/* 返回最小权值和 */
	return sum;
}

void test_prim(void) {
	int i, j, k, m, n;
	int x, y, cost;
	int chx, chy;

	FILE *fp;
	int s;

	if ((s = fopen_s(&fp, "D:\\nayowang\\Documents\\Visual Studio 2017\\Projects\\DataStructure\\test\\data.txt", "rt")) != 0) {
		printf("\n Cannot open file strike any key exit!\n");
		exit(1);
	}

	//printf("\n open file \n");
	fscanf_s(fp, "%d %d", &m, &n);
	/* 读取节点和边的数目 */
	//scanf_s("%d %d", &m, &n);
	//getchar();

	/* 初始化图，所有节点间距离为无穷大 */
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < m; j++)
		{
			graph[i][j] = MAXCOST;
		}
	}

	/* 读取边信息 */
	for (k = 0; k < n; k++)
	{
		fscanf_s(fp, "%d %d %d", &chx, &chy, &cost);
		//scanf_s("%c %c %d", &chx, &chy, &cost);
		//scanf_s("%d %d %d", &chx, &chy, &cost);
		//getchar();
		i = chx;//i = chx - 'A' + 1;
		j = chy;//j = chy - 'A' + 1;
		graph[i][j] = cost;
		graph[j][i] = cost;
	}

	fclose(fp);

	/* 求解最小生成树 */
	cost = Prim(graph, m);

	/* 输出最小权值和 */
	printf("Total:%d\n", cost);
};