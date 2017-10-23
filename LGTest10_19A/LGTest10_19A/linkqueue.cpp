#include "linkqueue.h"
#include <assert.h>
#include <stdlib.h>

void init_queue(PLinkQueue que)
{
	assert(que != NULL);
	que->head = (QNode *)malloc(sizeof(QNode));
	if (que->head == NULL)
	{
		exit(1);
	}
	que->tail = que->head;
	que->head->next = NULL;

}

bool is_empty(PLinkQueue que)
{
	assert(que != NULL);
	assert(que->head != NULL && que->tail != NULL);

	return que->head == que->tail;
}

void push_queue(PLinkQueue que,ELEM_TYPE e)
{
	assert(que != NULL && que->tail != NULL);
	PQNode elem = (QNode *)malloc(sizeof(QNode));
	if (elem == NULL)
	{
		exit(1);
	}
	elem->data = e;
	elem->next = NULL;
	que->tail->next = elem;
	que->tail = elem;
}

PQNode pop_queue(PLinkQueue que)
{
	assert(que != NULL && que->head != NULL);

	PQNode elem = que->head->next;
	if(elem != NULL)
	{
		que->head->next = elem->next;
		if (que->tail == elem)
		{
			que->tail = que->head;
		}
		return elem;
	}
	return elem;
}

PQNode head_queue(PLinkQueue que)
{
	assert(que != NULL);
	return que->head->next;
}

PQNode tail_queue(PLinkQueue que)
{
	assert(que != NULL);
	return que->tail;
}

void clear_queue(PLinkQueue que)
{
	assert(que != NULL);
	que->head->next = NULL;
	que->tail = que->head;
}

void destroy_queue(PLinkQueue que)
{
	assert(que != NULL && que->head != NULL);
	PQNode p = que->head->next;
	while (p != NULL)
	{
		que->head->next = p->next;
		free(p);
		if (que->tail == p)
		{
			que->tail = que->head;
		}
		p = que->head->next;
	}
	free(que->head);
	que->head = NULL;
}
