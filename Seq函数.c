#define _CRT_SECURE_NO_WARNINGS
#include "Seqlist.h"
void SLinit(SL* ps)
{
	ps->arr = NULL;
	ps->capacity = ps->size = 0;
}
void SLcheck(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		SLDatatype* tmp = (SLDatatype*)realloc(ps->arr, newcapacity * sizeof(SLDatatype));
		if (tmp == NULL)
		{
			perror("realloc fail!");
			return 1;
		}
		else
		{
			ps->arr = tmp;
			ps->capacity = newcapacity;
		}
	}
}
void SLdestroy(SL* ps)
{
	if (ps->arr)
	{
		free(ps->arr);
	}
	ps->arr = NULL;
	ps->capacity = ps->size = 0;
}
void SLtailadd(SL* ps,SLDatatype x)
{
	assert(ps);
	SLcheck(ps);
	ps->arr[ps->size] = x;
	ps->size++;
}
void SLheadadd(SL* ps, SLDatatype x)
{
	assert(ps);
	SLcheck(ps);
	for (int i = ps->size; i > 0; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[0] = x;
	ps->size++;
}
void SLheadpop(SL* ps)
{
	assert(ps);
	assert(ps->size);
	for (int i = 0; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}
void SLtailpop(SL* ps)
{
	assert(ps);
	assert(ps->size);
	ps->size--;
}
void SLpop(SL* ps,int p)
{
	assert(ps);
	assert(ps->size);
	for (int i = p; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}
void SLinsert(SL* ps, SLDatatype x, int p)
{
	assert(ps);
	SLcheck(ps);
	ps->size++;
	for (int i = ps->size; i > p; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[p] = x;
}
int SLfind(SL* ps,char* x)
{
	for (int i = 0; i < ps->size; i++)
	{
		if (strcmp(ps->arr[i].name, x) == 0)
		{
			return i;
		}
	}
	return -1;
}
void SLprintsingle(SL* ps, int i)
{
	printf("姓名：%s\n", ps->arr[i].name);
	printf("号码：%s\n", ps->arr[i].number);
	printf("年龄：%d\n", ps->arr[i].age);
	printf("地址：%s\n", ps->arr[i].addr);
}
void SLprintall(SL* ps)
{
	if (ps->size == 0)
	{
		printf("没有联系人！\n");
	}
	for (int i = 0; i < ps->size; i++)
	{
		printf("联系人%d：\n", i+1);
		SLprintsingle(ps, i);
		printf("\n");
	}
}