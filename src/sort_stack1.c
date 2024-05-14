/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghost <ghost@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:39:42 by randrina          #+#    #+#             */
/*   Updated: 2024/05/14 13:27:41 by ghost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mov_with_neg(t_stack *a, t_stack *b, int aindex, int bindex)
{
	int	count;

	count = 0;
	while (aindex < 0 && bindex < 0)
	{
		reverse_all(a, b);
		aindex ++;
		bindex ++;
		count ++;
	}
	while (aindex < 0)
	{
		aindex ++;
		rotate_a(a);
	}
	while (bindex < 0)
	{
		bindex ++;
		rotate_b(b);
	}
}

void	mov_with_pos(t_stack *a, t_stack *b, int aindex, int bindex)
{
	int	count;

	count = 0;
	while (aindex > 0 && bindex > 0)
	{
		rotate_all(a, b);
		aindex --;
		bindex --;
		count ++;
	}
	while (aindex > 0)
	{
		aindex --;
		rotate_a(a);
	}
	while (bindex > 0)
	{
		bindex --;
		rotate_b(b);
	}
}

void	ft_push_b(t_stack *a, t_stack *b)
{
	int		aindex;
	int		bindex;
	int		mov_a;
	int		mov_b;

	aindex = index_to_mov(a, b);
	bindex = find_cible(b, aindex);
	printf("\n");
	ft_show_stack(a, b);
	printf("\n");
	mov_a = to_top(a, aindex);
	mov_b = to_top(b, bindex);
	printf("\t\t aindex : %d, \tcible : %d \n", mov_a, mov_b);
	mov_with_pos(a, b, mov_a, mov_b);
	mov_with_neg(a, b, mov_a, mov_b);
}

void	ft_sort_stack1(t_stack *a, t_stack *b)
{
	//int	movb;

	ft_insert_index(a);
	first_push(a, b);
	while (ft_stacklen(a) > 3)
	{
		ft_push_b(a, b);
		push_b(a, b);
	}
	/*
	ft_three_sort(a);
	ft_show_stack(a, b);
	while (b->top)
	{
		movb = to_top(b, ft_maxindex(b));
		moov_b(b, movb);
		push_a(a, b);
	}*/
}
