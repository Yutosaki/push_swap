/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasakiyuto <sasakiyuto@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 21:11:05 by sasakiyuto        #+#    #+#             */
/*   Updated: 2024/10/14 18:02:10 by sasakiyuto       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str)
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return ((int)(sign * num));
}

t_node	**list_to_array(t_stack *stack)
{
	t_node	**array;
	t_node	*current;
	int		i;

	if (stack->size == 0)
		return (NULL);
	array = (t_node **)malloc(sizeof(t_node *) * stack->size);
	if (!array)
		return (NULL);
	current = stack->top;
	i = 0;
	while (current && i < stack->size)
	{
		array[i] = current;
		current = current->next;
		i++;
	}
	return (array);
}

void	sort_array(t_node **array, int size)
{
	int		i;
	int		j;
	t_node	*temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (array[j]->value > array[j + 1]->value)
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	link_array_to_list(t_node **array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		array[i]->value = i;
		i++;
	}
}
