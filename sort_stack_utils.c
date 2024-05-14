/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrina <randrina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:07:37 by randrina          #+#    #+#             */
/*   Updated: 2024/05/04 01:50:11 by randrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_maxindex(t_stack *stack)
{
    t_list *tmp;
    int     max;
    int     maxindex;

    tmp = stack->top;
    max = tmp->value;
    maxindex = tmp->index;
    tmp = tmp->next;
    while (tmp)
    {
        if (tmp->value > max)
        {
            max = tmp->value;
            maxindex = tmp->index;
        }
        tmp = tmp->next;
    }
    return (maxindex);
}

int find_cible(t_stack *stack, int index)
{
    t_list *tmp;
    int     min;
    int     cindex;

    tmp = stack->top;
    min = 0;
    while (tmp)
    {
        if (tmp->index < index && min < tmp->index)
        {
            min = tmp->index;
            cindex = tmp->index;
        }
        tmp = tmp->next;
    }
    if (min > 0)
        return(cindex);
    return (ft_maxindex(stack));
}

int ft_first_moov(t_stack *stack)
{
    t_list  *tmp;
    int     moov;
    int     maxindex;
    int     index;

    maxindex = ft_maxindex(stack);
    tmp = stack->top;
    index = ft_mindex(stack);
    moov = to_top(stack, index);
    while (tmp)
    {
        if (tmp->index < maxindex - 2 && abs_value((stack, tmp->index)) < abs_value(moov))
        {
            moov = to_top(stack, tmp->index);
            index = tmp->index;
        }
        tmp = tmp->next;
    }
    return (moov);
}

void    first_push(t_stack *a, t_stack *b)
{
    int mov;

    if (ft_stacklen(a) <= 5)
        mov = to_top(a, ft_mindex(a));
    else
        mov = ft_first_moov(a);
    if (mov != 0)
        moov_a(a, mov);
    if (!ft_check_final(a))
        push_b(a, b);
}

int ft_mindex(t_stack *stack)
{
    t_list *tmp;
    int     min;

    tmp = stack->top;
    min = tmp->index;
    while (tmp)
    {
        if (tmp->index < min)
            min = tmp->index;
        tmp = tmp->next;
    }
    return (min);
}