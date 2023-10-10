/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_rb_ra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 20:33:27 by yerilee           #+#    #+#             */
/*   Updated: 2023/10/10 21:45:24 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run_rb(t_stack *b, int rb_cnt)
{
	if (rb_cnt < 0)
	{
		rb_cnt = rb_cnt * -1;
		while (rb_cnt--)
			rrb(b);
	}
	else
		while (rb_cnt--)
			rb(b);
}

void	run_ra(t_stack *a, int ra_cnt)
{
	if (ra_cnt < 0)
	{
		ra_cnt = ra_cnt * -1;
		while (ra_cnt--)
			rra(a);
	}
	else
		while (ra_cnt--)
			ra(a);
}
