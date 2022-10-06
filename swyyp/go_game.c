/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalonso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 03:57:41 by dalonso           #+#    #+#             */
/*   Updated: 2021/12/11 03:57:44 by dalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	go_five(t_stack *stack1, t_stack *stack2)
{
	int	*Ar;
	int	i;

	i = 0;
	if (is_sorted(stack1) == 1)
		return ;
	Ar = malloc(sizeof(int) * 5);
	while (i < 5)
	{
		Ar[i] = stack1->num[i].value;
		i++;
	}
	get_rang(Ar, 5);
	i = 0;
	while ((stack1->num[0].value) != Ar[0])
		right_scroll(stack1, Ar[0]);
	px(stack2, stack1);
	go_four(stack1, stack2);
	px(stack1, stack2);
}

void	short_case(t_stack *stack1, t_stack *stack2)
{
	if (stack1->amount == 2)
		if (stack1->num[0].rank > stack1->num[1].rank)
			sx(stack1);
	if (stack1->amount == 3)
		go_three(stack1);
	if (stack1->amount == 4)
		go_four(stack1, stack2);
	if (stack1->amount  == 5)
		go_five(stack1, stack2);
	if (stack2->amount < 3 && stack2->amount > 0)
		b_two(stack1, stack2);
	if (stack2->amount == 3 && stack1->amount > 5)
	{
		b_three(stack1, stack2);
		end_ch(stack1, 3);
	}
	if (stack2->amount == 3 && stack1->amount < 6)
		b_three(stack1, stack2);
	all_sorted(stack1, stack2);
}

void	condition(t_stack *s1, t_stack *s2) // 1) s1 = A , 2) s1 = B
{
	int	n;

	if (s1->c == 'a')
	{
		n = get_n(s1, s1->last_ch);
		if (n < 3)
			rem_a(s1);
		all_sorted(s1, s2);
	}
	if (s1->c == 'b')
	{
		n = get_n(s1, s1->last_ch);
		if (n < 3)
			b_two(s2, s1); //s1 = B
		all_sorted(s2, s1);
	}
	return ;
}

int	recura(t_stack *stack1, t_stack *stack2)
{
	int x;

	x = 0;
	condition(stack1, stack2);
	if (stack1->c == 'b' && stack1->amount < 4)
		return (0);
	if (stack2->c == 'b' && stack2->amount < 4)
		return (0);	
	if ((x = get_n(stack2, stack2->last_ch)) > 2)
		transfer(stack2, stack1, (stack2->last_ch + 1));
	return recura(stack2, stack1);
}

void	go_game(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	x;

	short_case(stack_a, stack_b);
	i = 1;
	x = stack_a->amount;
	while (x > 2)
	{
		transfer(stack_a, stack_b, i);
		x--;
		i++;
		//printf("\n TRANS \n");
	}
	short_case(stack_a, stack_b);
	recura(stack_b, stack_a);
	short_case(stack_a, stack_b);
	while (is_sorted(stack_a) == 0)
		rrx(stack_a);
	all_sorted(stack_a, stack_b);
}
