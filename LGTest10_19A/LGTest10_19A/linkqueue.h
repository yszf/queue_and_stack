#pragma once

typedef int ELEM_TYPE;
typedef struct QNode 
{
	ELEM_TYPE data;
	struct QNode *next;
}QNode,*PQNode;

typedef struct  
{
	PQNode head;
	PQNode tail;
}LinkQueue,*PLinkQueue;

void init_queue(PLinkQueue queue);

bool is_empty(PLinkQueue queue);

void push_queue(PLinkQueue queue,ELEM_TYPE e);

PQNode pop_queue(PLinkQueue queue);

PQNode head_queue(PLinkQueue queue);

PQNode tail_queue(PLinkQueue queue);

void clear_queue(PLinkQueue queue);

void destroy_queue(PLinkQueue queue);
