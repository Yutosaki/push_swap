/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsasak <yutsasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:02:50 by yutsasak          #+#    #+#             */
/*   Updated: 2024/11/09 20:45:50 by yutsasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack *a)
{
	if (a->top == NULL || a->top->next == NULL)
		return ;
	if (a->top->value > a->top->next->value)
		sa(a);
}

void	reverse_sort_2(t_stack *b)
{
	if (b->top == NULL || b->top->next == NULL)
		return ;
	if (b->top->value < b->top->next->value)
		sb(b);
}

void	sort_3(t_stack *a)
{
	if (a->top == NULL || a->top->next == NULL || a->top->next->next == NULL)
		return ;
	if (a->top->value > a->top->next->value)
		sa(a);
	if (a->top->next->value > a->top->next->next->value)
		rra(a);
	if (a->top->value > a->top->next->value)
		sa(a);
}

void	sort_4(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	pb(a, b);
	sort_3(a);
	while (i < 4)
	{
		if (b->top == NULL)
			rra(a);
		else
		{
			if ((a->top->value) - 1 == b->top->value)
				pa(a, b);
			else
				rra(a);
		}
		i++;
	}
}

void	sort_5(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	pb(a, b);
	pb(a, b);
	sort_3(a);
	reverse_sort_2(b);
	while (i < 5)
	{
		if (b->top == NULL)
			rra(a);
		else
		{
			if ((a->top->value) - 1 == b->top->value)
				pa(a, b);
			else
				rra(a);
		}
		i++;
	}
}
