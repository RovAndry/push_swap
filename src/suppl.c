#include "push_swap.h"

int find_cible_a(t_stack *stack, int index)
{
    t_list *tmp;
    int     max;
    int     cindex;

    tmp = stack->top;
    max = ft_maxindex(stack);
    while (tmp)
    {
        if (tmp->index > index && max > tmp->index)
        {
            max = tmp->index;
            cindex = tmp->index;
        }
        tmp = tmp->next;
    }
    if (max < ft_maxindex(stack))
        return(cindex);
    return (ft_maxindex(stack));
}

void    ft_first_push2(t_stack *a, t_stack *b)
{
    int mov;
    t_list *tmp;
    int     len;

    len = ft_maxindex(a) / 2;
    tmp = a->top;
    mov = to_top(a, tmp->index);
    while (tmp)
    {
        if (tmp->index <= len && abs_value(mov) > abs_value(to_top(a, tmp->index)))
            mov = to_top(a, tmp->index);
        tmp = tmp->next;
    }
    moov_a(a, mov);
    push_b(a, b);
}

void ft_sort_stack2(t_stack *a, t_stack *b)
{
    int len;

    len = ft_stacklen(a);
	ft_insert_index(a);
	first_push(a, b);
	while (ft_stacklen(a) > len /2)
	{
		ft_push_b(a, b);
		push_b(a, b);
	}
    while (ft_stacklen(a) > 3)
    {
        ft_push_b(a, b);
        push_b(a, b);
    }
    ft_show_stack(a, b);
    ft_push_a(a, b);
	/*ft_three_sort(a);
	while (b->top)
	{
		movb = to_top(b, ft_maxindex(b));
		moov_b(b, movb);
		push_a(a, b);
	}*/
}

void	ft_push_b(t_stack *a, t_stack *b)
{
	int		aindex;
	int		bindex;
	int		mov_a;
	int		mov_b;

	aindex = index_to_mov(b, a);
	bindex = find_cible_a(b, aindex);
	mov_a = to_top(a, aindex);
	mov_b = to_top(b, bindex);
	mov_with_pos(a, b, mov_a, mov_b);
	mov_with_neg(a, b, mov_a, mov_b);
}

int index_moov(t_stack *a, t_stack *b, int index)
{
    int cible;
    int mov;

    cible = find_cible(b, index);
    mov = mov_nbr(to_top(a, index), to_top(b, cible));
    return (abs_value(mov));
}