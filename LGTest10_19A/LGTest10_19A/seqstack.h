#ifndef SEQSTACK_H
#define SEQSTACK_H

#define INITSIZE 10

typedef int ELEM_TYPE;

typedef struct  
{
	ELEM_TYPE *arr;
	int top;
	int length;
}SeqSta,*pSeqSta;

void init_stack(pSeqSta sta);

bool is_empty(pSeqSta sta);

bool is_full(pSeqSta sta);

void push_stack(pSeqSta sta,ELEM_TYPE e);

ELEM_TYPE pop_stack(pSeqSta sta);

ELEM_TYPE top_stack(pSeqSta sta);

void clear_stack(pSeqSta sta);

void destroy_stack(pSeqSta sta);

#endif