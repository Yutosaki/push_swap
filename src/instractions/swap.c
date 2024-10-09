#include "push_swap.h"

void sa(t_stack *a)
{
    t_node  *tmp;

    if (a->size < 2)
        return ;
    tmp = a->top;
    a->top = a->top->next;
    tmp->next = a->top->next;
    a->top->next = tmp;
}

void sb(t_stack *b)
{
    t_node  *tmp;

    if (b->size < 2)
        return ;
    tmp = b->top;
    b->top = b->top->next;
    tmp->next = b->top->next;
    b->top->next = tmp;
}

void ss(t_stack *a, t_stack *b)
{
    sa(a);
    sb(b);
}
