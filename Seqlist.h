#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>
#include <string.h>
typedef struct Connect
{
	char name[100];
	char number[20];
	int age;
	char addr[100];
}Con;
typedef Con SLDatatype;
typedef struct Seqlist
{
	SLDatatype* arr;
	int size;
	int capacity;
}SL;
void SLinit(SL*);
void SLcheck(SL*);
void SLdestroy(SL*);
void SLtailadd(SL*, SLDatatype);
void SLheadadd(SL*, SLDatatype);
void SLpop(SL* ps, int p);
void SLinsert(SL* ps, SLDatatype x, int p);
int SLfind(SL* ps, char* x);
void SLprintsingle(SL* ps, int i);
void SLprintall(SL* ps);