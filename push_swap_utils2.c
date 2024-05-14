/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrina <randrina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 09:33:49 by randrina          #+#    #+#             */
/*   Updated: 2024/05/08 21:14:19 by randrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stacklen(t_stack *stack)
{
	int		len;
	t_list	*tmp;

	len = 0;
	tmp = stack->top;
	while (tmp)
	{
		tmp = tmp->next;
		len ++;
	}
	return (len);
}

void	ft_show_stack(t_stack *a, t_stack *b)
{
	t_list	*tmp;

	tmp = a->top;
	ft_putstr("a\n", 1);
	while (tmp)
	{
		ft_putnbr(tmp->value);
		ft_putstr("[", 1);
		ft_putnbr(tmp->index);
		ft_putstr("]\n", 1);
		tmp = tmp->next;
	}
	tmp = b->top;
	ft_putstr("b\n", 1);
	while (tmp)
	{
		ft_putnbr(tmp->value);
		ft_putstr("[", 1);
		ft_putnbr(tmp->index);
		ft_putstr("]\n", 1);
		tmp = tmp->next;
	}
}

int	abs_value(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

int	ft_last_max(t_stack *stack, int last)
{
	t_list *tmp;
	int		max;

	tmp = stack->top;
	max = ft_min_value(stack);
	while (tmp)
	{
		if (tmp->value > max && tmp->value < last)
			max =  tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

int ft_max_value(t_stack *stack)
{
	t_list *tmp;
	int		max;

	tmp = stack->top;
	max = tmp->value;
	while (tmp)
	{
		if (max < tmp->value)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}