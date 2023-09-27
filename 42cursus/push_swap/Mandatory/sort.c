/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 20:31:20 by yerilee           #+#    #+#             */
/*   Updated: 2023/09/27 20:36:21 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorting(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return (0);
	select_pivot(a);
	classifying_by_pivot(a, b);
	while (a->size > 5)
		pb(a, b);
	sorting_a_stack(a, b);
	greedy(a, b);
	return (0);
}

void	sorting_a_stack(t_stack *a, t_stack *b)
{
	if (is_empty(a))
		return ;
	if (is_sorted(a))
		return ;
	else if (a->size == 2)
		sa(a);
	else if (a->size == 3)
		sort_3(a);
	else if (a->size == 4)
		sort_4(a, b);
	else if (a->size == 5)
		sort_5(a, b);
}

void	sort_3(t_stack *stack)
{
	int	one;
	int	two;
	int	thr;

	one = stack->first->val;
	two = stack->first->next->val;
	thr = stack->first->next->next->val;
	while (!(one < two && two < thr))
	{
		if (one > two && one > thr)
			ra(stack);
		else if (two > thr)
			rra(stack);
		else if (one > two)
			sa(stack);
		one = stack->first->val;
		two = stack->first->next->val;
		thr = stack->first->next->next->val;
	}
}

void	sort_4(t_stack *a, t_stack *b)
{
	set_min_top(a);
	if (!is_sorted(a))
	{
		pb(a, b);
		sort_3(a);
		pa(a, b);
	}
}

void	sort_5(t_stack *a, t_stack *b)
{
	move_min_element(a, b);
	move_min_element(a, b);
	sort_3(a);
	pa(a, b);
	pa(a, b);
	if (a->first->val > a->first->next->val)
		sa(a);
}
