/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_filler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalonso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 09:19:17 by dalonso           #+#    #+#             */
/*   Updated: 2021/10/22 09:19:21 by dalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_int(long long int x)
{
	if (x > MAX_INT || x < MIN_INT)
		return (0);
	return (1);
}

int	ft_parser(t_stack *stack_a, char **argv, int argc, t_num *num)
{
	int	i;
	int	*Ar;

	Ar = malloc(sizeof(int) * (argc - 1));
	stack_a->amount = (argc - 1);
	stack_a->num = num;
	i = 1;
	while (argv[i])
	{
		if (true_num(argv[i]) == 0)
			return (0);
		if (check_int(ft_atoi(argv[i])) == 0)
			return (0);
		num[i - 1].value = (int)ft_atoi(argv[i]);
		num[i - 1].stack = stack_a;
		num[i - 1].chunk = 0;
		Ar[i - 1] = num[i - 1].value;
		i++;
	}
	if (no_reply(num, (argc - 1)) == 0)
		return (0);
	get_rank(num, Ar, (argc - 1));
	return (1);
}

int	true_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '0')
		if (str[i + 1])
			return (0);
	if (str[i] == '-')
	{
		if (str[i + 1] == '-' || str[i + 1] == '0')
			return (0);
		i++;
	}
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (0);
		i++;
	}
	return (1);
}

int	no_reply(t_num *num, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		while (j < argc)
		{
			if (j == i)
				j++;
			if (num[i].value == num[j].value && j < argc)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
