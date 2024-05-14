/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrina <randrina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:45:39 by randrina          #+#    #+#             */
/*   Updated: 2024/05/03 19:13:35 by randrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*new;
	size_t	i;

	new = (char *) malloc(nmemb * size);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		new[i] = '\0';
		i ++;
	}
	return ((void *)new);
}

t_stack	*ft_init(void)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->top = NULL;
	return (new);
}

void	*ft_add_first(t_stack *stack, int value)
{
	t_list	*new;

	new = malloc (sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->value = value;
	new->next = stack->top;
	stack->top = new;
	return (stack);
}

void	*ft_add_last(t_stack *stack, int value)
{
	t_list	*new;
	t_list	*tmp;

	new = malloc (sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->value = value;
	new->next = NULL;
	if (stack->top == NULL)
	{
		stack->top = new;
		return (stack);
	}
	tmp = stack->top;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (stack);
}
