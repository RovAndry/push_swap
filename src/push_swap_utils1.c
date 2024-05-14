/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrina <randrina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:30:00 by randrina          #+#    #+#             */
/*   Updated: 2024/05/03 19:20:03 by randrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_number_check(char *str)
{
	long int	nbr;

	nbr = (long int)ft_atoi(str);
	if (nbr > 2147483647 || nbr < -2147483648)
		return (0);
	return (1);
}

int	ft_isnumber(char *str)
{
	int	len;
	int	count;

	len = 0;
	count = 0;
	if (!ft_number_check(str))
		return (0);
	if (str[0] == '-' || str[0] == '+')
	{
		if (!str[1] || !(str[1] >= '0' && str[1] <= '9'))
			return (0);
		len ++;
		count ++;
	}
	while (str[len])
	{
		if (str[len] >= '0' && str[len] <= '9')
			count ++;
		len ++;
	}
	if (count != len)
		return (0);
	return (1);
}

void	ft_putstr(char *str, int fd)
{
	int	len;

	len = 0;
	while (str[len])
	{
		write(fd, (str + len), 1);
		len ++;
	}
}

void	ft_putnbr(long int nbr)
{
	char	c;

	if (nbr < 0)
	{
		nbr = -nbr;
		write (1, "-", 1);
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	c = nbr % 10 + '0';
	write(1, &c, 1);
}

long int	ft_atoi(char *str)
{
	int			len;
	long int	nbr;
	int			sign;

	len = 0;
	nbr = 0;
	sign = 1;
	if (str[0] == '-')
	{
		sign = -sign;
		len ++;
	}
	if (str[0] == '+')
		len ++;
	while (str[len])
	{
		nbr = (nbr * 10) + (str[len] - '0');
		len ++;
	}
	return (nbr * sign);
}
