/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_success_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 22:09:41 by yerilee           #+#    #+#             */
/*   Updated: 2023/09/28 17:39:43 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	print_success(void)
{
	write(1, "OK\n", 3);
}

void	print_error(int num)
{
	if (num == 1)
		write(2, "Error\n", 6);
	if (num == 2)
		write(2, "KO\n", 3);
	exit(1);
}
