/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 21:11:42 by yerilee           #+#    #+#             */
/*   Updated: 2023/09/28 17:23:18 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	check_argv(argc, argv);
	a = stack_init();
	b = stack_init();
	setting_stack(argc, argv, a);
	get_operation_line(a, b);
	if (!is_sorted(a))
		print_error(2);
	if (b->size != 0)
		print_error(2);
	print_success();
	free_stack(a);
	free_stack(b);
	return (0);
}

void	get_operation_line(t_stack *a, t_stack *b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (!do_operation(a, b, line))
		{
			free(line);
			print_error(1);
		}
		free(line);
	}
}

int	do_operation(t_stack *a, t_stack *b, char *op)
{
	if (ft_strcmp(op, "sa\n") == 0)
		sa(a);
	else if (ft_strcmp(op, "sb\n") == 0)
		sb(b);
	else if (ft_strcmp(op, "ss\n") == 0)
		ss(a, b);
	else if (ft_strcmp(op, "pa\n") == 0)
		pa(a, b);
	else if (ft_strcmp(op, "pb\n") == 0)
		pb(a, b);
	else if (ft_strcmp(op, "ra\n") == 0)
		ra(a);
	else if (ft_strcmp(op, "rb\n") == 0)
		rb(b);
	else if (ft_strcmp(op, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(op, "rra\n") == 0)
		rra(a);
	else if (ft_strcmp(op, "rrb\n") == 0)
		rrb(b);
	else if (ft_strcmp(op, "rrr\n") == 0)
		rrr(a, b);
	else
		return (0);
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
