/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasakiyuto <sasakiyuto@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 21:10:39 by sasakiyuto        #+#    #+#             */
/*   Updated: 2024/11/10 18:03:26 by sasakiyuto       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;

void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);
void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);

void				init_stack(t_stack *stack, int size);
void				push(t_stack *stack, int value);
int					pop(t_stack *stack);
void				free_stack(t_stack *stack);
int					is_valid_integer(char *str);
int					ft_atoi(char *str);
int					is_sorted(t_stack *stack);
int					has_duplicates(t_stack *stack);
void				link_array_to_list(t_node **array, int size);
t_node				**list_to_array(t_stack *stack);
void				sort_array(t_node **array, int size);
int					get_max_bit(t_stack *stack);
void				radix_sort(t_stack *a, t_stack *b);
void				execute_error(t_stack *a, t_stack *b);
int					check_error(t_stack *a, t_stack *b, char **argv, int argc);
void				sort_2(t_stack *a);
void				sort_3(t_stack *a);
void				sort_4(t_stack *a, t_stack *b);
void				sort_5(t_stack *a, t_stack *b);
int					is_perfectly_sorted(t_stack *stack, int size);

#endif // PUSH_SWAP_H