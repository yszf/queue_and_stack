#include "loopqueue.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

void init_queue(PLQueue que)
{
	assert(que != NULL);
	que->length = INITSIZE;
	que->arr = (ELEM_TYPE *)malloc(sizeof(ELEM_TYPE)*que->length);
	if (que->arr == NULL)
	{
		exit(1);
	}
	memset(que->arr,0,sizeof(ELEM_TYPE)*que->length);
	que->head = que->tail = 0;
}

bool is_empty(PLQueue que)
{
	assert(que != NULL);
	if (que->arr == NULL)
	{
		return 1;
	}
	return que->head == que->tail;
}

bool is_full(PLQueue que)
{
	assert(que != NULL);
	return (que->tail+1)%que->length == que->head;
}

void push_queue(PLQueue que,ELEM_TYPE e)
{
	assert(que != NULL);
	if(is_full(que))
	{
		que->length *= 2;
		que->arr = (ELEM_TYPE*)realloc(que->arr,sizeof(ELEM_TYPE)*que->length);
	}
	que->arr[que->tail] = e;
	que->tail = (que->tail+1)%que->length;
}

ELEM_TYPE pop_queue(PLQueue que)
{
	assert(que != NULL);
	if (is_empty(que))
	{
		cout<<"队列为空"<<endl;
		return -1;
	}
	ELEM_TYPE elem = que->arr[que->head];
	que->head = (que->head+1)%que->length;
	return elem;
}

ELEM_TYPE top_queue(PLQueue que)
{
	assert(que != NULL);
	if (is_empty(que))
	{
		cout<<"队列为空"<<endl;
		return -1;
	}
	return que->arr[que->head];
}

ELEM_TYPE tail_queue(PLQueue que)
{
	assert(que != NULL);
	if (is_empty(que))
	{
		cout<<"队列为空"<<endl;
		return -1;
	}
	return que->arr[que->tail];
}

void clear_queue(PLQueue que)
{
	assert(que != NULL);
	que->head = que->tail = 0;
}

void destroy_queue(PLQueue que)
{
	assert(que != NULL);
	free(que->arr);
	que->arr = NULL;
	que->length = 0;
	que->head = que->tail = 0;
}