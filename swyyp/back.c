/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalonso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 08:53:26 by dalonso           #+#    #+#             */
/*   Updated: 2021/12/11 08:53:29 by dalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	cat_bthree(t_stack *s, int *n1, int *n2, int *n3)
{
	*n1 = s->num[0].rank;
	*n2 = s->num[1].rank;
	*n3 = s->num[2].rank;
}

void	cat_bthree1(t_stack *stack1, t_stack *stack2)
{
	px(stack1, stack2);
	sx(stack2);
	px(stack1, stack2);
	px(stack1, stack2);
}

void	cat_bthree2(t_stack *stack1, t_stack *stack2)
{
	sx(stack2);
	px(stack1, stack2);
	px(stack1, stack2);
	px(stack1, stack2);
}

void	b_three(t_stack *stack1, t_stack *stack2)
{
	int	n1;
	int	n2;
	int	n3;

	cat_bthree(stack2, &n1, &n2, &n3);
	if (n1 > n2 && n2 > n3)
	{
		px(stack1, stack2);
		px(stack1, stack2);
		px(stack1, stack2);
	}
	if (n1 > n2 && n2 < n3 && n1 > n3)
		cat_bthree1(stack1, stack2);
	if (n1 < n2 && n1 > n3)
		cat_bthree2(stack1, stack2);
	if (n1 > n2 && n1 < n3)
		cat_bthree3(stack1, stack2);
	if (n1 < n2 && n1 < n3 && n2 < n3)
		cat_bthree4(stack1, stack2);
	if (n1 < n2 && n1 < n3 && n2 < n3)
		cat_bthree5(stack1, stack2);
}
