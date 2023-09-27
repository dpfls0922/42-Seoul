/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 20:32:06 by yerilee           #+#    #+#             */
/*   Updated: 2023/09/27 20:47:14 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	greedy(t_stack *a, t_stack *b)
{
	int		min_ra;
	int		min_rb;

	if (is_sorted(a) && b->size == 0)
		return ;
	while (b->size)
	{
		find_minimum_times(a, b, &min_ra, &min_rb);
		run_rb(b, min_rb);
		run_ra(a, min_ra);
		pa(a, b);
	}
}

void	find_minimum_times(t_stack *a, t_stack *b, int *m_a, int *m_b)
{
	int		index_b;
	int		ra;
	int		rb;
	int		min_times;
	t_node	*curr;

	index_b = 0;
	min_times = 2147483647;
	curr = b->first;
	while (curr)
	{
		rb = rb_times(b, index_b);
		ra = ra_times(a, curr->val);
		if (min_times > ft_abs(rb) + ft_abs(ra))
		{
			min_times = ft_abs(rb) + ft_abs(ra);
			*m_a = ra;
			*m_b = rb;
		}
		index_b++;
		curr = curr->next;
	}
}

int	rb_times(t_stack *b, int index)
{
	if (index > b->size / 2)
		return (index - b->size);
	return (index);
}

int	ra_times(t_stack *a, int data_b)
{
	int	index;

	index = -1;
	find_index_to_push(a, data_b, &index);
	if (index > a->size / 2)
		return (index - a->size);
	return (index);
}

void	find_index_to_push(t_stack *a, int data_b, int *index)
{
	int		i;
	int		gap;
	t_node	*curr;

	i = 0;
	gap = 2147483647;
	curr = a->first;
	while (curr)
	{
		if (curr->val > data_b && gap > curr->val - data_b)
		{
			gap = curr->val - data_b;
			*index = i;
		}
		i++;
		curr = curr->next;
	}
	if (*index == -1)
		*index = find_min_index(a);
}
