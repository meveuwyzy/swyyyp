/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalonso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 03:55:43 by dalonso           #+#    #+#             */
/*   Updated: 2021/12/11 03:55:45 by dalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	all_sorted(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a) && stack_b->amount == 0)
		exit (0);
}

int		move_num_up(t_stack *stack1, t_stack *stack2, int i)
{
	px(stack2, stack1);
	i++;
	return (i);
}

int		move_num_down(t_stack *stack1, t_stack *stack2, int i)
{
	rrx(stack1);
	px(stack2, stack1);
	i++;
	return (i);
}

void	transfer(t_stack *stack1, t_stack *stack2, int ch) // из 1->2 ; в начале stack1=a
{
	int	i;
	int	n;
	int	x;

	i = 0;
	stack2->last_ch = ch; //should last_ch + 1
	n = mark_nums(stack1, stack2, stack1->last_ch);
	x = (stack1->amount - 1);
	while (i < n && x > 1)
	{
		if (stack1->num[0].chunk == ch)
			i = move_num_up(stack1, stack2, i);
		else if (stack1->num[x].chunk == ch)
			i = move_num_down(stack1, stack2, i);
		else
			rx(stack1);
		//printf("\n TRANSFEEEEEERSSSSSSSSS===----- %d\n", n);
	}
}
