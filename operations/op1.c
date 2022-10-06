/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalonso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 02:35:17 by dalonso           #+#    #+#             */
/*   Updated: 2021/10/24 02:35:19 by dalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sx_base(t_stack *x)
{
	t_num	tmp;

	tmp = x->num[1];
	x->num[1] = x->num[0];
	x->num[0] = tmp;
}

void	sx(t_stack *x)
{
	sx_base(x);
	ft_putstr_fd("s", 0);
	ft_putstr_fd(&x->c, 0);
	ft_putstr_fd("\n", 0);
}

void	ss(t_stack *x1, t_stack *x2)
{
	sx_base(x1);
	sx_base(x2);
	ft_putstr_fd("ss\n", 0);
}
