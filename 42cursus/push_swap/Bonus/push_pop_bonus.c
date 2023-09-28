/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 22:02:53 by yerilee           #+#    #+#             */
/*   Updated: 2023/09/27 22:10:50 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	push_top(t_stack *stack, int val)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return ;
	node->val = val;
	node->prev = NULL;
	if (is_empty(stack))
	{
		node->next = NULL;
		stack->first = node;
		stack->last = node;
	}
	else
	{
		node->next = stack->first;
		stack->first->prev = node;
		stack->first = node;
	}
	stack->size++;
}

void	push_bottom(t_stack *stack, int val, int flag)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return ;
	if (flag == 1)
		node->rank = 0;
	node->val = val;
	node->next = NULL;
	if (is_empty(stack))
	{
		node->prev = NULL;
		stack->first = node;
		stack->last = node;
	}
	else
	{
		node->prev = stack->last;
		stack->last->next = node;
		stack->last = node;
	}
	stack->size++;
}

int	pop_top(t_stack *stack)
{
	int		val;
	t_node	*temp;

	if (is_empty(stack))
		print_error(1);
	val = stack->first->val;
	temp = stack->first->next;
	free(stack->first);
	if (temp == NULL)
	{
		stack->first = NULL;
		stack->last = NULL;
	}
	else
	{
		stack->first = temp;
		temp->prev = NULL;
	}
	stack->size--;
	return (val);
}

int	pop_bottom(t_stack *stack)
{
	int		val;
	t_node	*temp;

	if (is_empty(stack))
		print_error(1);
	val = stack->last->val;
	temp = stack->last->prev;
	free(stack->last);
	if (temp == NULL)
	{
		stack->first = NULL;
		stack->last = NULL;
	}
	else
	{
		stack->last = temp;
		temp->next = NULL;
	}
	stack->size--;
	return (val);
}
