/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalonso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 05:59:00 by dalonso           #+#    #+#             */
/*   Updated: 2021/10/22 05:59:02 by dalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	t_num	*num;

	zero_values(&stack_a, &stack_b);
	num = malloc(sizeof(t_num) * (argc - 1));
	if (ft_parser(&stack_a, argv, argc, num) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
	go_game(&stack_a, &stack_b);
	exit (1);
}
