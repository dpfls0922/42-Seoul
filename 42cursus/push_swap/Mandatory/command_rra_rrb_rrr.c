/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rra_rrb_rrr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:16:53 by yerilee           #+#    #+#             */
/*   Updated: 2023/09/28 16:48:19 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a)
{
	int	val;

	if (a->last)
	{
		val = pop_bottom(a);
		push_top(a, val);
		write(1, "rra\n", 4);
	}
}

void	rrb(t_stack *b)
{
	int	val;

	if (b->last)
	{
		val = pop_bottom(b);
		push_top(b, val);
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_stack *a, t_stack *b)
{
	int	val;

	if (a->last && b->last)
	{
		val = pop_bottom(a);
		push_top(a, val);
		val = pop_bottom(b);
		push_top(b, val);
		write(1, "rrr\n", 4);
	}
}
