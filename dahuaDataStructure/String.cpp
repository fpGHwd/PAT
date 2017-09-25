#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static char *S = "GOODGOOGLE";
static char *T = "GOOGLE";

int Index(char *s, char *t, int pos) // pos: default = 0, find flag
{// s = search, t = 
	int i = pos,j = 1;
	while (i <= strlen(s)-1 && j <= strlen(t)-1) { // s[0] = length, T[0] = length
		if (S[i] == T[j]) {
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
static char *next_string = "ABABAAABA"; // next[j] = {0,1,1,2,3,4,2,2,3}; // ababaaaba 
										// abababaababacb
void get_next(char *T, int *next) {
	//next[j] = ; // j = 0,1,2,3,4,strlen(T) - 1;
	int i, j;

	/*
	for (j = 1; j <= strlen(T); j++) {
		next[j - 1] = 0;
		for (i = 1; i < j - 1; i++) {
			if (T[i - 1] == T[j - 2 + i])
				next[j - 1] = i+1;
			else {
				break;
			}
		}
	}*/
	i = 0;
	j = 0;
	next[1] = 0;
	while (i < strlen(T)) {
		if (j == 0 || T[i] == T[j]) {
			++i;
			++j;
			next[i] = j;
		}
		else {
			j = next[j];
		}
	}

	next[1] = 0;
	next[2] = 1;
	next[3] = 1;


}

//next[j] = { 0,1,1,2,3,4,2,2,3 }; // ABABAAABA
void GetNext(char *T, int *next) { // todo: 20170925 18:45
	int j=0,i = 1;
	
	

}

void TestString(void) {
	int i = Index(S, T, 0); // ok
	int arrar[10];
	get_next(next_string, arrar);
	printf("\n");
}