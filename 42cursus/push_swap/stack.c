/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:15:52 by yerilee           #+#    #+#             */
/*   Updated: 2023/09/27 20:51:29 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_init(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->size = 0;
	stack->first = NULL;
	stack->last = NULL;
	return (stack);
}

int	setting_stack(int argc, char **argv, t_stack *stack)
{
	int	i;

	i = 0;
	while (++i < argc)
		push_node_in_stack(stack, argv[i]);
	setting_node_rank(stack);
	return (0);
}

void	push_node_in_stack(t_stack *stack, char *argv)
{
	char	**num_list;
	int		i;

	i = 0;
	if (is_only_space(argv, ' '))
		exit(1);
	num_list = ft_split(argv, ' ');
	if (!num_list)
		exit(1);
	while (num_list[i])
	{
		if (check_duplicate(stack, ft_atoi(num_list[i])))
			print_error();
		push_bottom(stack, ft_atoi(num_list[i]), 1);
		i++;
	}
	free_list(num_list);
}

void	setting_node_rank(t_stack *stack)
{
	t_node	*curr;

	curr = stack->first;
	while (curr)
	{
		ranking(stack, curr);
		curr = curr->next;
	}
	curr = stack->first;
	while (curr)
	{
		curr->val = curr->rank;
		curr = curr->next;
	}
}

void	ranking(t_stack *stack, t_node *target)
{
	t_node	*curr;

	curr = stack->first;
	while (curr != target)
	{
		if (curr->val > target->val)
			curr->rank++;
		else if (curr->val < target->val)
			target->rank++;
		curr = curr->next;
	}
}
