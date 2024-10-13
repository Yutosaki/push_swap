/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasakiyuto <sasakiyuto@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 21:10:49 by sasakiyuto        #+#    #+#             */
/*   Updated: 2024/10/13 21:10:50 by sasakiyuto       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	write(1, "ra\n", 3);
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
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}
