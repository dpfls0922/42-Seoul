/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_pa_pb_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 22:03:31 by yerilee           #+#    #+#             */
/*   Updated: 2023/09/28 16:10:56 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	pa(t_stack *a, t_stack *b)
{
	int	val;

	if (b->first)
	{
		val = pop_top(b);
		push_top(a, val);
	}
}

void	pb(t_stack *a, t_stack *b)
{
	int	val;

	if (a->first)
	{
		val = pop_top(a);
		push_top(b, val);
	}
}
