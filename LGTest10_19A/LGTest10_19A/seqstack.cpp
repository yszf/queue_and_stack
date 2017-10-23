#include "seqstack.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <iostream>
using namespace std;

void init_stack(pSeqSta sta)
{
	assert(sta != NULL);
	sta->length = INITSIZE;
	sta->arr = (ELEM_TYPE *)malloc(sizeof(ELEM_TYPE)*sta->length);
	sta->top = 0;
	memset(sta->arr,0,sizeof(ELEM_TYPE)*sta->length);
	
}

bool is_empty(pSeqSta sta)
{
	assert(sta != NULL);
	return sta->top == 0;
}

bool is_full(pSeqSta sta)
{
	assert(sta != NULL);
	return sta->top == sta->length-1;
}

void push_stack(pSeqSta sta,ELEM_TYPE e)
{
	assert(sta != NULL);
	if (sta->top == sta->length)
	{
		sta->length *= 2;
		sta->arr = (ELEM_TYPE *)realloc(sta->arr,sizeof(ELEM_TYPE)*sta->length);
	}
	sta->arr[sta->top++] = e;
}

ELEM_TYPE pop_stack(pSeqSta sta)
{
	assert(sta != NULL);
	if(sta->top == 0)
	{
		cout<<"Õ»Îª¿Õ"<<endl;
		return -1;
	}
	return sta->arr[--sta->top];
}

ELEM_TYPE top_stack(pSeqSta sta)
{
	assert(sta != NULL);
	if(sta->top == 0)
	{
		cout<<"Õ»Îª¿Õ"<<endl;
		return -1;
	}
	return sta->arr[sta->top-1];
}

void clear_stack(pSeqSta sta)
{
	assert(sta != NULL);
	sta->top = 0;
}

void destroy_stack(pSeqSta sta)
{
	assert(sta != NULL);
	free(sta->arr);
	sta->arr = NULL;
	sta->length = 0;
	sta->top = 0;
}