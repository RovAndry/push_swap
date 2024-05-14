/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrina <randrina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 03:56:28 by randrina          #+#    #+#             */
/*   Updated: 2024/05/09 03:56:44 by randrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int to_top(t_stack *stack, int index)
{
    int count;
    t_list *tmp;

    tmp = stack->top;
    count = 0;
    while (tmp)
    {
        if (tmp->index == index)
            break ;
        tmp = tmp->next;
        count ++;
    }
    if (count <= ft_stacklen(stack) / 2)
        return (count);
    return (count - ft_stacklen(stack));
}

int mov_nbr(int mov_a, int mov_b)
{
    int mov;

    if (mov_a >= 0 && mov_b >= 0)
    {
        if(mov_a > mov_b)
            mov = mov_a;
        else
            mov = mov_b;
    }
    else if (mov_a >= 0 && mov_b < 0)
        mov = mov_a + abs_value(mov_b);
    else if (mov_a < 0 && mov_b >= 0)
        mov = abs_value(mov_a) + mov_b;
    else
    {
        if (abs_value(mov_a) > abs_value(mov_b))
            mov = abs_value(mov_a);
        else
            mov = abs_value(mov_b);
    }
    return (mov);
}

int index_to_mov(t_stack *a, t_stack *b)
{
    t_list  *tmp;
    int     max;
    int     index;
    int     mov;

    max = ft_maxindex(a) - 2;
    mov = 1000;
    tmp = a->top;
    while (tmp)
    {
        if (mov > index_moov(a, b, tmp->index) && tmp->index < max)
        {
            mov = index_moov(a, b, index);
            index = tmp->index;
        }
        tmp = tmp->next;
    }
    return (index);
}

void    ft_insert_index(t_stack *stack)
{
    int     index;
    t_list  *tmp;
    int     max;

    index = ft_stacklen(stack);
    max = ft_max_value(stack);
    while (index > 0)
    {
        tmp = stack->top;
        while(tmp)
        {
        if (tmp->value == max)
            tmp->index = index;
        tmp = tmp->next;
        }
        max = ft_last_max(stack, max);
        index --;
    }
}

int index_moov(t_stack *a, t_stack *b, int index)
{
    int cible;
    int mov;

    cible = find_cible(b, index);
    mov = mov_nbr(to_top(a, index), to_top(b, cible));
    return (abs_value(mov));
}