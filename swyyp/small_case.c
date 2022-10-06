/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalonso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 07:28:13 by dalonso           #+#    #+#             */
/*   Updated: 2021/12/11 07:28:15 by dalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	right_scroll(t_stack *a, int x)
{
	if (a->num[1].value == x)
		sx(a);
	else if (a->num[2].value == x)
	{
		rx(a);
		rx(a);
	}
	else
		rrx(a);
}

void	cat_three(t_stack *s, int *n1, int *n2, int *n3)
{
	*n1 = s->num[0].rank;
	*n2 = s->num[1].rank;
	*n3 = s->num[2].rank;	
}

void	go_three(t_stack *stack1)
{
	int	n1;
	int	n2;
	int	n3;

	if (is_sorted(stack1) == 1)
		return ;
	cat_three(stack1, &n1, &n2, &n3);
	if (n1 < n2 && n2 > n3 && n1 < n3)
	{
		rrx(stack1);
		sx(stack1);
	}
	if (n1 < n2 && n2 > n3 && n1 > n3)
		rrx(stack1);
	if (n1 > n2 && n1 > n3 && n2 > n3)
	{
		sx(stack1);
		rrx(stack1);
	}
	if (n1 > n2 && n1 > n3 && n2 < n3)
		rx(stack1);
	if (n1 > n2 && n1 < n3 && n2 < n3)
		sx(stack1);
}

void		go_four(t_stack *stack1, t_stack *stack2)
{
	int	*Ar;
	int	i;

	i = 0;
	if (is_sorted(stack1) == 1)
		return ;
	Ar = malloc(sizeof(int) * 4);
	while (i < 4)
	{
		Ar[i] = stack1->num[i].value;
		i++;
	}
	get_rang(Ar, 4);
	i = 0;
	while (stack1->num[0].value != Ar[0])
		right_scroll(stack1, Ar[0]);
	px(stack2, stack1);
	go_three(stack1);
	px(stack1, stack2);
}
