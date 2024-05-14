/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrina <randrina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:17:33 by randrina          #+#    #+#             */
/*   Updated: 2024/05/08 21:21:25 by randrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort_sup(t_stack *a)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = a->top;
	tmp2 = tmp1->next->next;
	if (tmp1->value < tmp2->value)
		swap_a(a);
	else
		rotate_a(a);
}

int	ft_min_value(t_stack *stack)
{
	t_list	*tmp;
	int		min;

	tmp = stack->top;
	min = tmp->value;
	while (tmp)
	{
		if (min > tmp->value)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

void	moov_a(t_stack *a, int mov)
{
	t_list	*tmp;
	t_list	*tmp1;

	tmp = a->top;
	tmp1 = tmp->next;
	if (mov == 1 && (tmp->index > tmp1->index))
			swap_a(a);
	else if (mov > 0)
	{
		while (mov > 0)
		{
			rotate_a(a);
			mov --;
		}
	}
	else
	{
		while (mov < 0)
		{
			reverse_a(a);
			mov ++;
		}
	}
}

void	moov_b(t_stack *b, int mov)
{
	t_list	*tmp;
	t_list	*tmp1;

	tmp = b->top;
	tmp1 = tmp->next;
	if (mov == 1 && (tmp->index > tmp1->index))
			swap_b(b);
	else if (mov > 0)
	{
		while (mov > 0)
		{
			rotate_b(b);
			mov --;
		}
	}
	else
	{
		while (mov < 0)
		{
			reverse_b(b);
			mov ++;
		}
	}
}