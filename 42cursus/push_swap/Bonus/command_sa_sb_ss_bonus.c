/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_sa_sb_ss_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 22:03:04 by yerilee           #+#    #+#             */
/*   Updated: 2023/09/28 16:11:21 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa(t_stack *a)
{
	int	val1;
	int	val2;

	if (a->first && a->first->next)
	{
		val1 = pop_top(a);
		val2 = pop_top(a);
		push_top(a, val1);
		push_top(a, val2);
	}
}

void	sb(t_stack *b)
{
	int	val1;
	int	val2;

	if (b->first && b->first->next)
	{
		val1 = pop_top(b);
		val2 = pop_top(b);
		push_top(b, val1);
		push_top(b, val2);
	}
}

void	ss(t_stack *a, t_stack *b)
{
	if (a->first && a->first->next && b->first && b->first->next)
	{
		sa(a);
		sb(b);
	}
}
