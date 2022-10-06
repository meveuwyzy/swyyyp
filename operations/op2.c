/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalonso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 04:06:39 by dalonso           #+#    #+#             */
/*   Updated: 2021/10/24 04:06:42 by dalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rx_base(t_stack *z)
{
	t_num	tmp;
	int		i;

	tmp = z->num[0];
	i = 0;
	while (i < (z->amount - 1))
	{
		z->num[i] = z->num[i + 1];
		i++;
	}
	z->num[i] = tmp;
}

void	rx(t_stack *x)
{
	rx_base(x);
	ft_putstr_fd("r", 0);
	ft_putstr_fd(&x->c, 0);
	ft_putstr_fd("\n", 0);
}

void	rr(t_stack *x1, t_stack *x2)
{
	rx_base(x1);
	rx_base(x2);
	ft_putstr_fd("rr\n", 0);
}

void	px(t_stack *x1, t_stack *x2)   //amount = [кол-во num] + 1
{
	struct s_num	*tmp;

	tmp = malloc(sizeof(t_num) * 1);
	rrx_base(x1);  // down
	x1->num[x1->amount] = x1->num[0];
	x1->num[x1->amount + 1].stack = NULL;
	x1->num[0] = x2->num[0];
	//x2->num[0].stack = NULL;  //!!!!
	rx_base(x2);   // up
	*(x2->num + (x2->amount - 1)) = *tmp;  //that's right
	free(tmp);
	x1->num[0].stack = x1;
	x2->amount--;
	x1->amount++;
	x2->num[x2->amount].stack = NULL;
	ft_putstr_fd("p", 0);
	ft_putstr_fd(&x1->c, 0);
	ft_putstr_fd("\n", 0);
}
