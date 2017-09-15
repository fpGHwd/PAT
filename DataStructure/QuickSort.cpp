#include "QuickSort.h"
#include "stdafx.h"

void quick_sort(int a[], int l, int r)
{
	if (l < r)
	{
		int i, j, x;

		i = l;
		j = r;
		x = a[i];
		while (i < j)
		{
			while (i < j && a[j] > x)
				j--; // 从右向左找第一个小于x的数
			if (i < j)
				a[i++] = a[j];

			while (i < j && a[i] < x)
				i++; // 从左向右找第一个大于x的数
			if (i < j)
				a[j--] = a[i];
		}
		a[i] = x;
		quick_sort(a, l, i - 1); /* 递归调用 */
		quick_sort(a, i + 1, r); /* 递归调用 */
	}
}

void test_quick_sort(void) {
	int a[20] = {23,34,56,3,12,67,8,42,64,34,7,34,23,5,23,44,33,25,61,43};
	int i;
	printf("the origin array: is: |");
	for (i = 0; i < 20; i++) {
		printf("%d | ", a[i]);
	}
	printf("\n");
	quick_sort(a, 0, 19);
	printf("the quick_sorted array: is: |");
	for (i = 0; i < 20; i++) {
		printf("%d | ", a[i]);
	}
	printf("\n");
}