/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:58:43 by yerilee           #+#    #+#             */
/*   Updated: 2023/09/27 16:59:26 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_index(t_stack *stack)
{
	int		i;
	int		min_index;
	int		min_val;
	t_node	*curr;

	i = 0;
	min_index = 0;
	min_val = stack->first->val;
	curr = stack->first;
	while (curr)
	{
		if (min_val > curr->val)
		{
			min_val = curr->val;
			min_index = i;
		}
		i++;
		curr = curr->next;
	}
	return (min_index);
}

void	move_min_element(t_stack *a, t_stack *b)
{
	set_min_top(a);
	pb(a, b);
}

void	set_min_top(t_stack *a)
{
	int	index;

	index = find_min_index(a);
	if (index > a->size / 2)
		while (a->size - index++)
			rra(a);
	else
		while (index--)
			ra(a);
}
