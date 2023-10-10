/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:12:47 by yerilee           #+#    #+#             */
/*   Updated: 2023/10/10 21:44:32 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_argv(int argc, char **argv)
{
	int		i;
	char	*str;

	i = 1;
	while (i < argc)
	{
		str = argv[i];
		while (*str)
		{
			if (*str == '-' || *str == '+' )
			{
				str++;
				if (*str < '0' || *str > '9')
					print_error();
			}
			else if (*str != ' ' && (*str < '0' || *str > '9'))
				print_error();
			if (*str)
				str++;
		}
		i++;
	}
}

int	check_duplicate(t_stack	*stack, int val)
{
	t_node	*curr;

	curr = stack->first;
	while (curr)
	{
		if (curr->val == val)
			print_error();
		curr = curr->next;
	}
	return (0);
}

int	is_only_space(const char *s, char c)
{
	int	flag;

	flag = 1;
	while (*s)
	{
		if (*s != c)
			flag = 0;
		s++;
	}
	return (flag);
}

int	is_sorted(t_stack *stack)
{
	t_node	*curr;

	curr = stack->first;
	while (curr->next)
	{
		if (curr->val > curr->next->val)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	is_empty(t_stack *stack)
{
	return (stack->first == NULL);
}
