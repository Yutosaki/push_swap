#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
// #include "../libft.h"
# include <stdio.h>
#include <unistd.h>

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

#endif // PUSH_SWAP_H