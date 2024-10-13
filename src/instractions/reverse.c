/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasakiyuto <sasakiyuto@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 21:10:47 by sasakiyuto        #+#    #+#             */
/*   Updated: 2024/10/13 21:10:48 by sasakiyuto       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	write(1, "rra\n", 4);
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
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}
