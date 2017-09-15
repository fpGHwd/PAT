#pragma once

#include "stdafx.h"

#define MaxSize 100

typedef struct {
	char data[MaxSize];
	int length;
}SqString;

// interfaces
// BF algorithm, Brutle-force
int index(SqString s, SqString t);
int KMPIndex(SqString s, SqString t);
