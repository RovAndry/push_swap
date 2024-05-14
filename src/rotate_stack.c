/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrina <randrina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:45:12 by randrina          #+#    #+#             */
/*   Updated: 2024/04/30 15:57:27 by randrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack *stack)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (ft_stacklen(stack) >= 2)
	{
		tmp1 = stack->top;
		tmp2 = tmp1->next;
		stack->top = tmp2;
		tmp1->next = NULL;
		while (tmp2->next)
			tmp2 = tmp2->next;
		tmp2->next = tmp1;
	}
}

void	rotate_a(t_stack *a)
{
	ft_rotate(a);
	ft_putstr("ra\n", 1);
}

void	rotate_b(t_stack *b)
{
	ft_rotate(b);
	ft_putstr("rb\n", 1);
}

void	rotate_all(t_stack *a, t_stack *b)
{
	ft_rotate(a);
	ft_rotate(b);
	ft_putstr("rr\n", 1);
}
