#include "push_swap.h"
#include <stdio.h>

void	ra(t_stack *a)
{
	t_node	*first;
	t_node	*last;

	if (a->size < 2)
		return ;
	first = a->top;
	a->top = a->top->next;
	last = a->top;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	rb(t_stack *b)
{
	t_node	*first;
	t_node	*last;

	if (b->size < 2)
		return ;
	first = b->top;
	b->top = b->top->next;
	last = b->top;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}