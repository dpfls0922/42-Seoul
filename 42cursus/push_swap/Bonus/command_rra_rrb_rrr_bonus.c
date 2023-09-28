/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rra_rrb_rrr_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 22:03:17 by yerilee           #+#    #+#             */
/*   Updated: 2023/09/28 16:11:15 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rra(t_stack *a)
{
	int	val;

	if (a->last)
	{
		val = pop_bottom(a);
		push_top(a, val);
	}
}

void	rrb(t_stack *b)
{
	int	val;

	if (b->last)
	{
		val = pop_bottom(b);
		push_top(b, val);
	}
}

void	rrr(t_stack *a, t_stack *b)
{
	if (a->last && b->last)
	{
		rra(a);
		rrb(b);
	}
}
