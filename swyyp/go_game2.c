/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalonso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 10:10:47 by dalonso           #+#    #+#             */
/*   Updated: 2021/12/11 10:10:49 by dalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	end_ch(t_stack *stack_x, int n)
{
	int	i;

	i = 0;
	if (is_sorted(stack_x) == 1)
		return ;
	while (i < n)
	{
		stack_x->num[i].chunk = (-1);
		rx(stack_x);
		i++;
	}
}

void	rem_a(t_stack *stack_a)
{
	int	n;
	int	i;

	i = 0;
	n = get_n(stack_a, stack_a->num[0].chunk);
	if (n == 2)
		if (stack_a->num[0].rank > stack_a->num[1].rank)
			sx(stack_a);
	end_ch(stack_a, n);
	stack_a->last_ch = stack_a->num[0].chunk;
}

void	b_two(t_stack *stack1, t_stack *stack2) //stack2 = B
{
	int	i;
	int	n;

	n = get_n(stack2, stack2->last_ch);
	i = 0;
	while (i < n)
	{
		px(stack1, stack2);
		i++;
	}
	if (stack2->amount > 0)
		stack2->last_ch = stack2->num[0].chunk;
	rem_a(stack1);
	all_sorted(stack1, stack2);
}

int	a_or_b(t_stack *stack1, int i, int mid)
{
	if (stack1->c == 'a')
		if (stack1->num[i].rank < mid)
			return (1);
	if (stack1->c == 'b')
		if (stack1->num[i].rank > mid)
			return (1);
	return (0);
}

int	mark_nums(t_stack *stack1, t_stack *stack2, int ch)
{
	int	i;
	int	mid;
	int	n;
	int x;

	n = 0;
	i = 0;
	x = 0;
	mid = get_mid(stack1, ch);
	while (i < stack1->amount)
	{
		if (stack1->num[i].chunk == ch)
			if ((x = a_or_b(stack1, i, mid)) == 1)
			{
				stack1->num[i].chunk = stack2->last_ch;
				n++;
			}
		i++;
	}
	return (n);
}
