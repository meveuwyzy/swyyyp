/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalonso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 22:02:59 by dalonso           #+#    #+#             */
/*   Updated: 2021/12/10 22:03:11 by dalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_n_1(int n)
{
	n = (n / 2) + 1;
	return (n);
}

int	get_n(t_stack *st, int ch)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (i < st->amount)
	{
		if (st->num[i].chunk == ch)
			n++;
		i++;
	}
	return (n);
}

void	get_rang(int *Ar, int n)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < n)
	{
		j = i;
		while (j < n)
		{
			if (Ar[i] > Ar[j])
			{
				temp = Ar[i];
				Ar[i] = Ar[j];
				Ar[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	get_mid(t_stack *st, int ch)
{
	int	i;
	int	*Ar;
	int	n;
	int	j;

	n = get_n(st, ch);
	Ar = malloc(sizeof(int) * n);
	i = 0;
	j = 0;
	while (i < st->amount)
	{
		if (st->num[i].chunk == ch)
		{
			Ar[j] = st->num[i].rank;
			j++;
		}
		i++;
	}
	get_rang(Ar, n);
	i = get_n_1(n);
	n = Ar[i - 1];
	return (n);
}
