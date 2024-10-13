/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasakiyuto <sasakiyuto@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 21:10:54 by sasakiyuto        #+#    #+#             */
/*   Updated: 2024/10/13 21:31:28 by sasakiyuto       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack, char stack_name)
{
	t_node	*current;

	current = stack->top;
	printf("Stack %c: ", stack_name);
	while (current)
	{
		printf("%d ", current->value);
		current = current->next;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		i;
	t_node	**array;

	if (argc < 2) // 引数が0or1
		return (0);
	init_stack(&a, 0);
	init_stack(&b, 0);
	i = argc - 1;
	while (i > 0)
	{
		if (!is_valid_integer(argv[i])) // 整数ではない
		{
			write(2, "Error\n", 6);
			free_stack(&a);
			free_stack(&b);
			return (1);
		}
		push(&a, ft_atoi(argv[i])); // int外
		i--;
	}
	if (has_duplicates(&a)) // 重複
	{
		write(2, "Error\n", 6);
		free_stack(&a);
		free_stack(&b);
		return (1);
	}
	if (is_sorted(&a)) // ソート済み ソートされてたら1が返却
		return (0);
	array = list_to_array(&a);
	sort_array(array, a.size);
	link_array_to_list(array, a.size);
	radix_sort(&a, &b);
	free_stack(&a);
	free_stack(&b);
	free(array);
	return (0);
}
