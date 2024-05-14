/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrina <randrina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:51:54 by randrina          #+#    #+#             */
/*   Updated: 2024/05/01 10:46:54 by randrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *stack)
{
	t_list	*tmp1;
	t_list	*tmp2;
	int		value;
	int		index;

	if (ft_stacklen(stack) >= 2)
	{
		tmp1 = stack->top;
		tmp2 = tmp1->next;
		value = tmp1->value;
		index = tmp1->index;
		tmp1->value = tmp2->value;
		tmp1->index = tmp2->index;
		tmp2->value = value;
		tmp2->index = index;
	}
}

void	swap_a(t_stack *a)
{
	ft_swap(a);
	ft_putstr("sa\n", 1);
}

void	swap_b(t_stack *b)
{
	ft_swap(b);
	ft_putstr("sb\n", 1);
}

void	swap_all(t_stack *a, t_stack *b)
{
	ft_swap(a);
	ft_swap(b);
	ft_putstr("ss\n", 1);
}
