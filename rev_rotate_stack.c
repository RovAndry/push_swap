/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrina <randrina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:36:12 by randrina          #+#    #+#             */
/*   Updated: 2024/04/30 15:57:46 by randrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse(t_stack *stack)
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*tmp3;

	if (ft_stacklen(stack) <= 2)
		ft_rotate(stack);
	else
	{
		tmp1 = stack->top;
		tmp2 = tmp1->next;
		while (tmp2->next->next)
			tmp2 = tmp2->next;
		tmp3 = tmp2->next;
		tmp2->next = NULL;
		tmp3->next = tmp1;
		stack->top = tmp3;
	}
}

void	reverse_a(t_stack *a)
{
	ft_reverse(a);
	ft_putstr("rra\n", 1);
}

void	reverse_b(t_stack *b)
{
	ft_reverse(b);
	ft_putstr("rrb\n", 1);
}

void	reverse_all(t_stack *a, t_stack *b)
{
	ft_reverse(a);
	ft_reverse(b);
	ft_putstr("rrr\n", 1);
}
