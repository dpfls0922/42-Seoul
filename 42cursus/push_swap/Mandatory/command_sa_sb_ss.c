/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_sa_sb_ss.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:15:06 by yerilee           #+#    #+#             */
/*   Updated: 2023/09/28 16:48:49 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		write(1, "sa\n", 3);
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
		write(1, "sb\n", 3);
	}
}

void	ss(t_stack *a, t_stack *b)
{
	int	val1;
	int	val2;

	if (a->first && a->first->next && b->first && b->first->next)
	{
		val1 = pop_top(a);
		val2 = pop_top(a);
		push_top(a, val1);
		push_top(a, val2);
		val1 = pop_top(b);
		val2 = pop_top(b);
		push_top(b, val1);
		push_top(b, val2);
		write(1, "ss\n", 3);
	}
}
