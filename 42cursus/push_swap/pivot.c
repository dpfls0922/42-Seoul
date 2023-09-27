/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:20:10 by yerilee           #+#    #+#             */
/*   Updated: 2023/09/27 19:42:47 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	select_pivot(t_stack *stack)
{
	t_node	*curr;

	curr = stack->first;
	while (curr)
	{
		if (curr->rank == stack->size / 3)
			stack->pivot1 = curr->val;
		else if (curr->rank == (stack->size) * 2 / 3)
			stack->pivot2 = curr->val;
		curr = curr->next;
	}
}

void	classifying_by_pivot(t_stack *a, t_stack *b)
{
	int	i;
	int	pivot1;
	int	pivot2;

	i = 0;
	pivot1 = a->pivot1;
	pivot2 = a->pivot2;
	if (a->size <= 5)
		return ;
	while (i++ < a->size + b->size)
	{
		if (a->size <= 5)
			return ;
		if (a->first->val < pivot1)
		{
			pb(a, b);
			rb(b);
		}
		else if (a->first->val >= pivot1 && a->first->val <= pivot2)
			pb(a, b);
		else
			ra(a);
	}
}
