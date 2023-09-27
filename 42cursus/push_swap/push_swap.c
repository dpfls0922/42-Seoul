/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:43:17 by yerilee           #+#    #+#             */
/*   Updated: 2023/09/27 20:48:51 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	check_argv(argc, argv);
	a = stack_init();
	b = stack_init();
	setting_stack(argc, argv, a);
	sorting(a, b);
	set_min_top(a);
	free_stack(a);
	free_stack(b);
	return (0);
}

int	ft_abs(int value)
{
	if (value < 0)
		return (-(value));
	return (value);
}

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
