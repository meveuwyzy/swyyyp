/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalonso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 09:37:38 by dalonso           #+#    #+#             */
/*   Updated: 2021/12/11 09:37:40 by dalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	cat_bthree3(t_stack *stack1, t_stack *stack2)
{
	rx(stack2);
	sx(stack2);
	px(stack1, stack2);
	rrx(stack1);
	px(stack1, stack2);
	px(stack1, stack2);
}

void	cat_bthree4(t_stack *stack1, t_stack *stack2)
{
	rx(stack2);
	sx(stack2);
	px(stack1, stack2);
	rrx(stack2);
	px(stack1, stack2);
	px(stack1, stack2);
}

void	cat_bthree5(t_stack *stack1, t_stack *stack2)
{
	rx(stack2);
	sx(stack2);
	px(stack1, stack2);
	rrx(stack2);
	px(stack1, stack2);
	px(stack1, stack2);
}
