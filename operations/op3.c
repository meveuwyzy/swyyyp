/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalonso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 05:10:03 by dalonso           #+#    #+#             */
/*   Updated: 2021/10/24 05:10:27 by dalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrx_base(t_stack *x)
{
	t_num	tmp;
	int		i;

	tmp = x->num[x->amount - 1];
	i = x->amount - 1;
	while (i > 0)
	{
		x->num[i] = x->num[i - 1];
		i--;
	}
	x->num[0] = tmp;
}

void	rrx(t_stack *x)
{
	rrx_base(x);
	ft_putstr_fd("rr", 0);
	ft_putstr_fd(&x->c, 0);
	ft_putstr_fd("\n", 0);
}

void	rrr(t_stack *x1, t_stack *x2)
{
	rrx_base(x1);
	rrx_base(x2);
	ft_putstr_fd("rrr\n", 0);
}
