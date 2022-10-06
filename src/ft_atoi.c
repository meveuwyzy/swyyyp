/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 17:44:04 by student           #+#    #+#             */
/*   Updated: 2020/06/04 17:48:57 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (c);
	else
		return (0);
}

long long	ft_atoi(char *str)
{
	int				neg;
	long long int	x;

	neg = 1;
	x = 0;

	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	while (ft_isdigit((int)*str))
	{
		x = x * 10 + *str - '0';
		str++;
	}
	x = x * neg;
	return (x);
}
