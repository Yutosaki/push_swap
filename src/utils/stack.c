/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasakiyuto <sasakiyuto@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 21:10:57 by sasakiyuto        #+#    #+#             */
/*   Updated: 2024/10/13 21:10:58 by sasakiyuto       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack, int size)
{
	stack->top = NULL;
	stack->size = size;
}

void	push(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
}

int	pop(t_stack *stack)
{
	t_node	*temp;
	int		value;

	if (stack->size == 0)
		return (0);
	temp = stack->top;
	value = temp->value;
	stack->top = temp->next;
	free(temp);
	stack->size--;
	return (value);
}

void	free_stack(t_stack *stack)
{
	while (stack->size > 0)
		pop(stack);
}
