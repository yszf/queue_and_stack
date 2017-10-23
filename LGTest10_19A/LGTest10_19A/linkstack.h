#ifndef LINKSTACK_H
#define LINKSTACK_H

typedef int ELEM_TYPE;

typedef struct SNode
{
	ELEM_TYPE data;
	struct SNode *next;
}SNode,*PSNode;

typedef struct  
{
	PSNode head;
}LinkStack,*PLinkStack;

void init_stack(PLinkStack stack);

bool is_empty(PLinkStack stack);

void push_stack(PLinkStack stack,ELEM_TYPE e);

PSNode pop_stack(PLinkStack stack);

PSNode top_stack(PLinkStack stack);

void clear_stack(PLinkStack stack);

void destroy_stack(PLinkStack stack);

#endif