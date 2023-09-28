/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_ra_rb_rr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:16:51 by yerilee           #+#    #+#             */
/*   Updated: 2023/09/28 16:48:03 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	int	val;

	if (a->first)
	{
		val = pop_top(a);
		push_bottom(a, val, 0);
		write(1, "ra\n", 3);
	}
}

void	rb(t_stack *b)
{
	int	val;

	if (b->first)
	{
		val = pop_top(b);
		push_bottom(b, val, 0);
		write(1, "rb\n", 3);
	}
}

void	rr(t_stack *a, t_stack *b)
{
	int	val;

	if (a->first && b->first)
	{
		val = pop_top(a);
		push_bottom(a, val, 0);
		val = pop_top(b);
		push_bottom(b, val, 0);
		write(1, "rr\n", 3);
	}
}
