/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrina <randrina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 09:38:54 by randrina          #+#    #+#             */
/*   Updated: 2024/05/03 17:12:38 by randrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min_index(t_stack *stack)
{
	t_list	*tmp;
	int		index;
	int		min;
	int		mindex;

	tmp = stack->top;
	min = tmp->value;
	index = 0;
	mindex = 0;
	tmp = tmp->next;
	while (tmp)
	{
		index ++;
		if (tmp->value < min)
		{
			mindex = index;
			min = tmp->value;
		}
		tmp = tmp->next;
	}
	return (mindex);
}

void	ft_sort_last_min(t_stack *a)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = a->top;
	tmp2 = tmp1->next;
	if (tmp1->value < tmp2->value)
		reverse_a(a);
	else
	{
		swap_a(a);
		reverse_a(a);
	}
}

void	ft_three_sort(t_stack *a)
{
	if (ft_stacklen(a) == 2)
		swap_a(a);
	else
	{
		if (ft_check_final(a))
			return ;
		if (ft_min_index(a) == 0)
		{
			swap_a(a);
			rotate_a(a);
		}
		else if (ft_min_index(a) == 1)
			three_sort_sup(a);
		else
			ft_sort_last_min(a);
	}
}

void	ft_sort_stack(t_stack *a, t_stack *b)
{
	if (ft_check_final(a))
	{
		free(b);
		return ;
	}
	else if (ft_stacklen(a) <= 3)
		ft_three_sort(a);
	else
		ft_sort_stack1(a, b);
}
