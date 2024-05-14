/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrina <randrina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:27:18 by randrina          #+#    #+#             */
/*   Updated: 2024/04/30 15:56:37 by randrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack *stack1, t_stack *stack2)
{
	t_list	*tmp1;
	t_list	*new;
	t_list	*tmp2;

	if (stack2->top)
	{
		new = (t_list *)malloc(sizeof(t_list));
		if (new == NULL)
			return ;
		tmp1 = stack1->top;
		tmp2 = stack2->top;
		new->value = tmp2->value;
		new->index = tmp2->index;
		stack2->top = tmp2->next;
		new->next = tmp1;
		stack1->top = new;
		free(tmp2);
	}
}

void	push_a(t_stack *a, t_stack *b)
{
	ft_push(a, b);
	ft_putstr("pa\n", 1);
}

void	push_b(t_stack *a, t_stack *b)
{
	ft_push(b, a);
	ft_putstr("pb\n", 1);
}
