/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasakiyuto <sasakiyuto@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 21:10:31 by sasakiyuto        #+#    #+#             */
/*   Updated: 2024/10/13 21:10:32 by sasakiyuto       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bit(t_stack *stack)
{
	int		max;
	int		max_bits;
	t_node	*current;

	max = 0;
	current = stack->top;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	max_bits = 0;
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	i = 0;
	size = a->size;
	max_bits = get_max_bit(a);
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((a->top->value >> i) & 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (b->size > 0)
			pa(a, b);
		i++;
	}
}
