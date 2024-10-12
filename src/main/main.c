#include "push_swap.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

int	is_valid_integer(char *str)
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
		if (*str < '0' || *str > '9')
			return (0);
		num = num * 10 + (*str - '0');
		if (sign * num > INT_MAX || sign * num < INT_MIN)
			return (0);
		str++;
	}
	return (1);
}

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
	return (int)(sign * num);
}

int	has_duplicates(t_stack *stack)
{
	t_node	*current;
	t_node	*runner;

	current = stack->top;
	while (current)
	{
		runner = current->next;
		while (runner)
		{
			if (current->value == runner->value)
				return (1);
			runner = runner->next;
		}
		current = current->next;
	}
	return (0);
}

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

int	is_sorted(t_stack *stack)
{
    t_node	*current;

    current = stack->top;
    while (current && current->next)
    {
        if (current->value > current->next->value)
            return (0);
        current = current->next;
    }
    return (1);
}

int	main(int argc, char **argv)
{
	t_stack a;
	t_stack b;
	int i;

	if (argc < 2)// 引数が0or1
		return (0);
	init_stack(&a, argc - 1);
	init_stack(&b, 0);
	i = argc - 1;
	while (i > 0)
	{
		if (!is_valid_integer(argv[i]))// 整数ではない
		{
			write(2, "Error\n", 6);
			free_stack(&a);
			free_stack(&b);
			return (1);
		}
		push(&a, ft_atoi(argv[i]));// int外
		i--;
	}
	if (has_duplicates(&a))// 重複
	{
		write(2, "Error\n", 6);
		free_stack(&a);
		free_stack(&b);
		return (1);
	}
    if (!is_sorted(&a))// ソート済み
    print_stack(&a, 'a');
    print_stack(&b, 'b');
    printf("--------------------\n");
	if (a.size <= 3)
		pb(&a, &b);
	else if (a.size <= 5)
		sa(&a);
	else if (a.size <= 6)
		ra(&a);
    else 
        rra(&a);

	print_stack(&a, 'a');
	print_stack(&b, 'b');

	free_stack(&a);
	free_stack(&b);
	return (0);
}