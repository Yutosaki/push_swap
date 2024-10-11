#include "push_swap.h"

void	rra(t_stack *a)
{
	t_node	*tmp;
	t_node	*last;

	if (a->size < 2)
		return ;
	tmp = a->top;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = a->top;
	a->top = last;
}

void	rrb(t_stack *b)
{
	t_node	*tmp;
	t_node	*last;

	if (b->size < 2)
		return ;
	tmp = b->top;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = b->top;
	b->top = last;
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}
