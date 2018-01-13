#include "stdafx.h"
#include <iostream>

using namespace std;

int FindNum(int n, int k)
{
	if (n <= 0)
		return 0;
	FindNum(n / 10, k + 1);
	for (int i = 1; i <= n % 10; i++)
	{
		if (k == 0)
		{
			cout << i;
		}
		if (k == 1)
		{
			cout << "S";
		}
		if (k == 2)
		{
			cout << "B";
		}
	}
}

void pat1006(void) {
	
	int N[3] = {0}, n, top = -1,temp;
	scanf("%d", &n);
	temp = n;
	while (n) {
		N[++top] = n % 10;
		n /= 10;
	}
	int k;
	while (top != -1) {
		k = N[top];
		switch (top) {
		case 2:
			while (k--)printf("B");
			break;
		case 1:
			while (k--)printf("S");
			break;
		case 0:
			printf("1");
			break;
		}
		top--;
	}
	printf("%d", temp);
	
	/*
	int i = 0;
	cin >> i;
	FindNum(i, 0);
	system("pause");
	*/
}

void Test(void) {
	/*
	int W[2][3] = { {1,2,3},{4,5,6} };
	printf("%d\n", *(W[0] + 2));
	printf("%d\n", *(W + 1)[2]);
	printf("%d\n", (*(W + 1))[2]);
	printf("%d\n", W[0][0]);
	printf("%d\n", *(W[1]+2));
	printf("%d\n", W[1]+2);
	getchar();
	*/
	pat1006();
}