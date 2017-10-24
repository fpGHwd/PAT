#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// find the index 
int get_index(char *s, char *t, int pos)
{
	int i = pos, j = 1;
	while (i <= strlen(s) - 1 && j <= strlen(t) - 1) {
		if (s[i] == t[j]) {
			++j; ++i;
		}
		else {
			i = i - j + 1;
			j = 0;
		}
	}
	if (j >= strlen(t))
		return i - strlen(t);
}

// KMP
static char *search1 = "GOODGOOGLE";
static char *pattern1 = "GOOGLE"; // next[] = {0,1,1,1,2,1};
static char *search2 = "abababaababacb";
static char *pattern2 = "ababacb"; // next[] = {0,1,1,2,3,4,1};
static char *pattern3 = "ababaaaba"; //next[] = {0,1,1,2,3,4,2,2,3};
static char *pattern4 = "abaabcac"; // next[] = {0,1,1,2,2,3,1,2}; //example in textbook

void get_next(char *pattern, int *next) {
	int i = 1, j = 0;
	next[i-1] = 0; // i -> index -> next[i];
	while (i < strlen(pattern)) // i from 1 to n-1, total n-1 
		if (j == 0 || pattern[i-1] == pattern[j-1])
			next[i++] = ++j;
		else 
			j = next[j-1]; // i++;j++;next[i-1] = j;
}

void test_string(void) {
	//int i = get_index(S, T, 0); // ok
	int next[4][20] = {0};
	get_next(pattern1, *next);
	get_next(pattern2, *next + 20);
	get_next(pattern3, *next + 40);
	get_next(pattern4, *next + 60);

	getchar();
}