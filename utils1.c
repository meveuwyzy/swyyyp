/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalonso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 09:25:57 by dalonso           #+#    #+#             */
/*   Updated: 2021/10/22 09:25:59 by dalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_rank1(t_num *num, int *Ar, int argc)
{
	int	i;
	int	j;
  
	i = 0;
	while (i < argc)
	{
		j = 0;
		while (j < argc)
		{
			if (Ar[i] == num[j].value)
			{
				num[j].rank = i + 1;
			}
			j++;
		}
		i++;
	}
	// if (Ar) 
	// 	free(Ar);
}

void	get_rank(t_num *num, int *Ar, int argc)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < argc)
	{
		j = i;
		while (j < argc)
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
	get_rank1(num, Ar, argc);
}

void	zero_values(t_stack *a, t_stack *b)
{
	t_num	*hui;

	hui = malloc(sizeof(t_num) * 10);
	b->num = hui;
	a->c = 'a';
	b->c = 'b';
	b->amount = 0;
	a->last_ch = 0;
	b->last_ch = 0;
}

int	is_sorted(t_stack *s)
{
	int i;

	i = 0;
	while(i < (s->amount - 1))
	{
		if (s->c == 'a')
			if (s->num[i].rank > s->num[i + 1].rank)
				return (0);
		if (s->c == 'b')
			if (s->num[i].rank < s->num[i + 1].rank)
				return (0);
		i++;
	}
	return (1);
}
