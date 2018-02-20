#include "stdafx.h"
#include <cstdio>
#include <cstring>

int PATA1060() {
	freopen("input.txt", "r", stdin);
	int n;
	char a[10000], b[10000], A[10000], B[10000];
	scanf("%d%s%s", &n, a, b);
	int a_len = strlen(a), b_len = strlen(b), a_dot = a_len, b_dot = b_len;
	for (int i = 0; i < a_len; i++) {
		if (a[i] == '.') {
			a_dot = i; // 0.0005 a_dot = 1;
			break;
		}
	}
	for (int i = 0; i < b_len; i++) {
		if (b[i] == '.') {
			b_dot = i;
			break;
		}
	}
	int a_valid = 0, b_valid = 0;
	while (a[a_valid] == '0' || a[a_valid] == '.')a_valid++; // 0.0005 a_valid = 5
	while (b[b_valid] == '0' || b[b_valid] == '.')b_valid++; 

	int a_e, b_e; // exponents of a & b
	if (a_dot >= a_valid)
		a_e = a_dot - a_valid;
	else
		a_e = a_dot - a_valid + 1;
	if (b_dot >= b_valid)
		b_e = b_dot - b_valid;
	else
		b_e = b_dot - b_valid + 1;
	if (a_valid == strlen(a))
		a_e = 0;
	if (b_valid == strlen(b))
		b_e = 0;

	int index_a = 0, index_b = 0;
	while (index_a < n) {
		if (a[a_valid] != '.' && a_valid < strlen(a))
			A[index_a++] = a[a_valid];
		else if (a_valid >= strlen(a))
			A[index_a++] = '0';
		a_valid++;
	}
	A[index_a] = 0;
	while (index_b < n) {
		if (b[b_valid] != '.' && b_valid < strlen(b))
			B[index_b++] = b[b_valid];
		else if (b_valid >= strlen(b))
			B[index_b++] = '0';
		b_valid++;
	}
	B[index_b] = 0;
	if (strcmp(A, B) == 0 && a_e == b_e)
		printf("YES 0.%s*10^%d", A, a_e);
	else
		printf("NO 0.%s*10^%d 0.%s*10^%d", A, a_e, B, b_e);

	return 0;
}
