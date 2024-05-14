/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrina <randrina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 08:54:25 by randrina          #+#    #+#             */
/*   Updated: 2024/05/01 10:04:13 by randrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_input_sort(char **argv, int argc)
{
	int		i;
	int		words;
	char	**args;

	i = 0;
	if (argc == 2)
	{
		args = ft_split(argv[1]);
		words = ft_count_words(argv[1], ' ');
	}
	else
	{
		words = argc - 1;
		i = 1;
		args = argv;
	}
	if (words == 0)
		return (ft_putstr("Error\n", 2), 1);
	while (args[i + 1] && i < words - 1)
	{
		if (ft_atoi(args[i]) > ft_atoi(args[i + 1]))
			return (0);
		i ++;
	}
	return (1);
}

void	ft_free(char **args, int argc)
{
	if (argc == 2)
		free(args);
}

char	**ft_check_input(char **argv, int argc)
{
	int		index;
	char	**args;

	index = 0;
	if (argc == 2)
		args = ft_split(argv[1]);
	else
	{
		args = argv;
		index = 1;
	}
	while (args[index])
	{
		if (args[index][0] == '\0' || !ft_isnumber(args[index]))
		{
			ft_putstr("Error\n", 2);
			return (ft_free(args, argc), NULL);
		}
		index ++;
	}
	return (args);
}

int	ft_check_stack(t_stack *stack)
{
	int		i;
	t_list	*tmp1;
	t_list	*tmp2;

	if (ft_stacklen(stack) == 0)
		return (0);
	i = 0;
	tmp1 = stack->top;
	while (i < ft_stacklen(stack))
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp1->value == tmp2->value)
				return (0);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1-> next;
		i ++;
	}
	return (1);
}

t_stack	*generate_stack_a(char **argv, int argc)
{
	t_stack	*a;
	int		i;
	char	**args;

	args = ft_check_input(argv, argc);
	if (!args)
		return (NULL);
	a = ft_init();
	if (argc == 2)
		i = 0;
	else
		i = 1;
	while (args[i])
	{
		ft_add_last(a, ft_atoi(args[i]));
		i ++;
	}
	if (!ft_check_stack(a))
	{
		ft_putstr("Error\n", 2);
		return (free(a), NULL);
	}
	return (a);
}
