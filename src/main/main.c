/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsasak <yutsasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 21:10:54 by sasakiyuto        #+#    #+#             */
/*   Updated: 2024/11/09 21:07:07 by yutsasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_error(t_stack *a, t_stack *b, char **argv, int argc)
{
	int	i;

	i = argc - 1;
	while (i > 0)
	{
		if (!is_valid_integer(argv[i]))
		{
			execute_error(a, b);
			return (1);
		}
		push(a, ft_atoi(argv[i]));
		i--;
	}
	if (has_duplicates(a))
	{
		execute_error(a, b);
		return (1);
	}
	if (is_sorted(a))
	{
		free_stack(a);
		free_stack(b);
		return (1);
	}
	return (0);
}

void	execute_error(t_stack *a, t_stack *b)
{
	write(2, "Error\n", 6);
	free_stack(a);
	free_stack(b);
}

int	small_case(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		printf("a->top->value = %d\n", a->top->value);
		printf("a->top->next->value = %d\n", a->top->next->value);
		sort_2(a);
	}
	else if (a->size == 3)
		sort_3(a);
	else if (a->size == 4)
		sort_4(a, b);
	else if (a->size == 5)
		sort_5(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_node	**array;

	if (argc < 2)
		return (0);
	init_stack(&a, 0);
	init_stack(&b, 0);
	if (check_error(&a, &b, argv, argc))
		return (1);
	array = list_to_array(&a);
	sort_array(array, a.size);
	link_array_to_list(array, a.size);
	if (argc <= 6)
	{
		free(array);
		return (small_case(&a, &b));
	}
	radix_sort(&a, &b);
	free_stack(&a);
	free_stack(&b);
	free(array);
	return (0);
}
