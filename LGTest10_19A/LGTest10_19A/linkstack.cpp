#include "linkstack.h"
#include <assert.h>
#include <iostream>
using namespace std;

void init_stack(PLinkStack stack)
{
	stack->head = (SNode *)malloc(sizeof(SNode));
	stack->head->next = NULL;
	stack->head->data = 0;
}

bool is_empty(PLinkStack stack)
{	
	assert(stack != NULL);
	return stack->head->next == NULL;
}

void push_stack(PLinkStack stack,ELEM_TYPE e)
{
	assert(stack != NULL);
	PSNode head = stack->head;
	PSNode elem = (SNode *)malloc(sizeof(SNode));
	elem->data = e;
	elem->next = head->next;
	head->next = elem;
}

PSNode pop_stack(PLinkStack stack)
{
	assert(stack != NULL);
	PSNode head = stack->head;
	if (head->next == NULL)
	{
		cout<<"Õ»Îª¿Õ\n"<<endl;
		return NULL;
	}
	PSNode p = head->next;
	PSNode elem = p;
	head->next = p->next;
	return elem;
}

PSNode top_stack(PLinkStack stack)
{
	assert(stack != NULL);
	PSNode head = stack->head;
	if (head->next == NULL)
	{
		cout<<"Õ»Îª¿Õ\n"<<endl;
		return NULL;
	}
	return head->next;
}

void clear_stack(PLinkStack stack)
{
	assert(stack != NULL);
	stack->head->next = NULL;
}

void destroy_stack(PLinkStack stack)
{
	assert(stack != NULL);
	PSNode head = stack->head;
	PSNode p = head->next;

	while (p != NULL)
	{
		pop_stack(stack);
		p = p->next;
	}
}