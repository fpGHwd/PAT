#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>

//#define _CRT_SECURE_NO_WARNINGS

#define MAX 100
#define MAXCOST 0x7fffffff

int graph[MAX][MAX];

int Prim(int graph[][MAX], int n)
{

	/* lowcost[i]��¼��iΪ�յ�ıߵ���СȨֵ����lowcost[i]=0ʱ��ʾ�յ�i���������� */
	int lowcost[MAX];

	/* mst[i]��¼��Ӧlowcost[i]����㣬��mst[i]=0ʱ��ʾ���i���������� */
	int mst[MAX];

	int i, j, min, minid, sum = 0;

	lowcost[0] = 0;
	mst[0] = 0;

	/* Ĭ��ѡ��1�Žڵ��������������2�Žڵ㿪ʼ��ʼ�� */
	for (i = 1; i < n; i++)
	{
		/* ��̾����ʼ��Ϊ�����ڵ㵽1�Žڵ�ľ��� */
		lowcost[i] = graph[0][i];

		/* ������нڵ������ΪĬ�ϵ�1�Žڵ� */
		mst[i] = 0;
	}

	/* ���1�Žڵ���������� */
	mst[0] = 0;

	/* n���ڵ�������Ҫn-1���߹�����С������ */
	for (i = 1; i < n; i++)
	{
		min = MAXCOST;
		minid = 0;

		/* ��������������СȨֵ�ߵĽڵ�minid */
		for (j = 1; j < n; j++)
		{
			/* ��Ȩֵ��С�Ҳ����������� */
			if (lowcost[j] < min && lowcost[j] != 0)
			{
				min = lowcost[j];
				minid = j;
			}
		}
		/* ����������ߵ���Ϣ:��㣬�յ㣬Ȩֵ */
		printf("(%d,%d) : %d\n", mst[minid], minid, min);

		/* �ۼ�Ȩֵ */
		sum += min;

		/* ��ǽڵ�minid���������� */
		lowcost[minid] = 0;

		/* ���µ�ǰ�ڵ�minid�������ڵ��Ȩֵ */
		for (j = 1; j < n; j++)
		{
			/* ���ָ�С��Ȩֵ */
			if (graph[minid][j] < lowcost[j] && lowcost[j] != 0)
			{
				/* ����Ȩֵ��Ϣ */
				lowcost[j] = graph[minid][j];

				/* ������СȨֵ�ߵ���� */
				mst[j] = minid;
			}
		}
	}
	/* ������СȨֵ�� */
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
	/* ��ȡ�ڵ�ͱߵ���Ŀ */
	//scanf_s("%d %d", &m, &n);
	//getchar();

	/* ��ʼ��ͼ�����нڵ�����Ϊ����� */
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < m; j++)
		{
			graph[i][j] = MAXCOST;
		}
	}

	/* ��ȡ����Ϣ */
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

	/* �����С������ */
	cost = Prim(graph, m);

	/* �����СȨֵ�� */
	printf("Total:%d\n", cost);
};