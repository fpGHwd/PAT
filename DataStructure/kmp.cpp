#include "stdafx.h"

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
static char *search1 = "GOODGOOGLE"; // index = 5
static char *pattern1 = "GOOGLE"; // next[] = {0,1,1,1,2,1};
static char *search2 = "abababaababacbababaaabaabaabcac"; // index = 8,15,24;
static char *pattern2 = "ababacb"; // next[] = {0,1,1,2,3,4,1};
static char *pattern3 = "ababaaaba"; //next[] = {0,1,1,2,3,4,2,2,3};
static char *pattern4 = "abaabcac"; // next[] = {0,1,1,2,2,3,1,2};

void get_next(char *pattern, int *next) {
	int i = 1, j = 0;
	next[i - 1] = 0; // i -> index -> next[i];
	while (i < strlen(pattern)) // i from 1 to n-1, n-1 in total 
		if (j == 0 || pattern[i - 1] == pattern[j - 1])
			next[i++] = ++j; // i++;j++;next[i-1] = j;
		else
			j = next[j - 1];
}

static int next_tmp[20] = { 0 };
int get_index(char *search, char *pattern) {
	int i = 1, j = 1;// i is search index, j is pattern index
	get_next(pattern, next_tmp);

	while (i <= strlen(search) && j <= strlen(pattern)) {
		if (j == 0 || search[i - 1] == pattern[j - 1]) {
			i++; j++;
		}
		else
			j = next_tmp[j - 1];
	}

	if (j > strlen(pattern))
		return (i - strlen(pattern));
	else
		return 0;
}

void test_string(void) {
	//int i = get_index(S, T, 0); // ok

	/*
	int next[4][20] = {0};
	get_next(pattern1, *next);
	get_next(pattern2, *next + 20);
	get_next(pattern3, *next + 40);
	get_next(pattern4, *next + 60);
	*/
	/*
	// get index
	int i[4] = { 0 } , k = 0;
	i[k++] = get_index(search1, pattern1);
	i[k++] = get_index(search2, pattern2);
	i[k++] = get_index(search2, pattern3);
	i[k++] = get_index(search2, pattern4);
	*/

	getchar();
}