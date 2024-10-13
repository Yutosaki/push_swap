#include "push_swap.h"

void	sa(t_stack *a)
{
	t_node	*tmp;

	if (a->size < 2)
		return ;
	tmp = a->top;
	a->top = a->top->next;
	tmp->next = a->top->next;
	a->top->next = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	t_node	*tmp;

	if (b->size < 2)
		return ;
	tmp = b->top;
	b->top = b->top->next;
	tmp->next = b->top->next;
	b->top->next = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}
