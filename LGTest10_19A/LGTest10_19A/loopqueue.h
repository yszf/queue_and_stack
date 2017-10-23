#pragma once

#define INITSIZE 10

typedef int ELEM_TYPE;

typedef struct
{
	ELEM_TYPE *arr;
	int head;
	int tail;
	int length;
}LQueue,*PLQueue;

void init_queue(PLQueue que);

bool is_empty(PLQueue que);

bool is_full(PLQueue que);

void push_queue(PLQueue que,ELEM_TYPE e);

ELEM_TYPE pop_queue(PLQueue que);

ELEM_TYPE top_queue(PLQueue que);

ELEM_TYPE tail_queue(PLQueue que);

void clear_queue(PLQueue que);

void destroy_queue(PLQueue que);

