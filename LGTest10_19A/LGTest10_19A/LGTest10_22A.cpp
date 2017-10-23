#include "seqstack.h"
#include "linkstack.h"
#include "linkqueue.h"
#include "loopqueue.h"
#include <assert.h>
#include <iostream>
using namespace std;

void print_stack(SeqSta sta)
{
	for (int i=0;i<sta.top;++i)
	{
		cout<<sta.arr[i]<<" ";
	}
	cout<<endl;
}

int main001()
{
	SeqSta sta;
	init_stack(&sta);
	for (int i=0;i<11;++i)
	{
		push_stack(&sta,i);
	}
	print_stack(sta);
	printf("is_empty:%d\n",is_empty(&sta));
	printf("is_full:%d\n",is_full(&sta));
	ELEM_TYPE elem = pop_stack(&sta);
	printf("elem:%d\n",elem);
	print_stack(sta);
	printf("top_stack:%d\n",top_stack(&sta));
//	clear_stack(&sta);
	destroy_stack(&sta);
	pop_stack(&sta);
	print_stack(sta);
	return 0;
}

void print_stack(PLinkStack pstack)
{
	if (pstack != NULL)
	{
		PSNode head = pstack->head;
		PSNode p = head->next;
		while (p != NULL)
		{
			cout<<p->data<<" ";
			p = p->next;
		}
		cout<<endl;
	}
}

int main002()
{
	LinkStack stack;
	init_stack(&stack);
	for (int i=0;i<5;++i)
	{
		push_stack(&stack,i);
	}
	print_stack(&stack);
	PSNode elem = pop_stack(&stack);
	cout<<elem->data<<endl;
	PSNode elem2 = top_stack(&stack);
	cout<<elem2->data<<endl;
	print_stack(&stack);
//	clear_stack(&stack);
	destroy_stack(&stack);
	print_stack(&stack);
//	pop_stack(&stack);
//	top_stack(&stack);
	return 0;
}

void print_queue(PLinkQueue queue)
{
	if (queue != NULL)
	{
		assert(queue->head != NULL);
		PQNode p = queue->head->next;
		while (p != NULL)
		{
			cout<<p->data<<" ";
			p = p->next;
		}
		cout<<endl;
	}
}

int main003()
{
	LinkQueue queue;
	init_queue(&queue);
	for (int i=0;i<5;++i)
	{
		push_queue(&queue,i);
	}
	print_queue(&queue);
	PQNode node = pop_queue(&queue);
	cout<<node->data<<endl;
	push_queue(&queue,5);
	print_queue(&queue);
//	clear_queue(&queue);
//	destroy_queue(&queue);
//	print_queue(&queue);
	PQNode e1 = pop_queue(&queue);
	cout<<e1->data<<endl;
	PQNode e2 = tail_queue(&queue);
	cout<<e2->data<<endl;
	PQNode e3 = head_queue(&queue);
	cout<<e3->data<<endl;
	return 0;
}

void print_queue(PLQueue que)
{
	assert(que != NULL);
	if (que->arr == NULL)
	{
		exit(1);
	}
	int size = (que->tail - que->head+que->length)%que->length;
	for (int i = que->head;i<size+que->head;)
	{
		cout<<que->arr[i]<<" ";
		i = (i+1)%que->length;
	}
	cout<<endl;
}

int main()
{
	LQueue que;
	init_queue(&que);
	for (int i = 0;i<10;++i)
	{
		push_queue(&que,i);
	}
	print_queue(&que);
	pop_queue(&que);
	pop_queue(&que);

	push_queue(&que,5);
	push_queue(&que,6);
	print_queue(&que);
	destroy_queue(&que);
//	clear_queue(&que);
//	pop_queue(&que);
//	top_queue(&que);
	tail_queue(&que);
	print_queue(&que);
	return 0;
}