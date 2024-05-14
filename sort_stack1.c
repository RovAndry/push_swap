/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrina <randrina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:39:42 by randrina          #+#    #+#             */
/*   Updated: 2024/05/04 02:52:18 by randrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	mov_with_neg(t_stack *a, t_stack *b, int aindex, int bindex)
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
}

int	mov_with_pos(t_stack *a, t_stack *b, int aindex, int bindex)
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
}

void	ft_push_b(t_stack *a, t_stack *b)
{
	int		aindex;
	int		bindex;
	int		mov_a;
	int		mov_b;

	aindex = index_to_mov(a, b);
	bindex = find_cible(b, aindex);
	mov_a = to_top(a, aindex);
	mov_b = to_top(b, bindex);
	if (mov_a > 0 && mov_b > 0)
	{
		mov_a = mov_a - mov_with_pos(a, b, aindex, bindex);
		mov_b = mov_b - mov_with_pos(a, b, aindex, bindex);
	}
	else if (mov_a < 0 && mov_b < 0)
	{
		mov_a = mov_with_neg(a, b, aindex, bindex);
		mov_b = mov_with_neg(a, b, aindex, bindex);
	}
	if (mov_a != 0)
		moov_a(a, mov_a);
	if (mov_b != 0)
		moov_b(b, mov_b);
}

void	ft_sort_stack1(t_stack *a, t_stack *b)
{
	int	index;
	int	movb;
	int	totop;

	ft_insert_index(a);
	first_push(a, b);
	while (ft_stacklen(a) > 3)
	{
		ft_push_b(a, b);
		push_b(a, b);
	}
	ft_three_sort(a);
	while (b->top)
	{
		movb = to_top(b, ft_maxindex(b));
		moov_b(b, movb);
		push_a(a, b);
	}
}
