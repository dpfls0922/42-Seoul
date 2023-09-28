/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_ra_rb_rr_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 22:03:21 by yerilee           #+#    #+#             */
/*   Updated: 2023/09/28 16:11:05 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra(t_stack *a)
{
	int	val;

	if (a->first)
	{
		val = pop_top(a);
		push_bottom(a, val, 0);
	}
}

void	rb(t_stack *b)
{
	int	val;

	if (b->first)
	{
		val = pop_top(b);
		push_bottom(b, val, 0);
	}
}

void	rr(t_stack *a, t_stack *b)
{
	if (a->first && b->first)
	{
		ra(a);
		rb(b);
	}
}
