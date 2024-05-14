/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghost <ghost@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:12:07 by randrina          #+#    #+#             */
/*   Updated: 2024/05/14 13:06:29 by ghost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2 || argv[1][0] == '\0')
		return (1);
	else if (!ft_check_input(argv, argc) || ft_check_input_sort(argv, argc))
		return (1);
	else
	{
		a = generate_stack_a(argv, argc);
		if (!a || ft_check_final(a))
			return (1);
		else
		{
			b = ft_init();
			ft_sort_stack(a, b);
//			ft_show_stack(a, b);
//			printf("\ncheck[%d]\n", ft_check_final(a));
		}
	}
	return (0);
}
