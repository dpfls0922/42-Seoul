/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_pa_pb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:16:46 by yerilee           #+#    #+#             */
/*   Updated: 2023/09/27 15:58:27 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	int	val;

	if (b->first)
	{
		val = pop_top(b);
		push_top(a, val);
		write(1, "pa\n", 3);
	}
}

void	pb(t_stack *a, t_stack *b)
{
	int	val;

	if (a->first)
	{
		val = pop_top(a);
		push_top(b, val);
		write(1, "pb\n", 3);
	}
}
