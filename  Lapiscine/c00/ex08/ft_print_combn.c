/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 08:57:46 by yerilee           #+#    #+#             */
/*   Updated: 2023/01/16 11:56:35 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	string_num(char *str, int i, int v, int n)
{
	str[i] = v;
	if (i == n - 1)
	{
		write(1, str, n);
		if (str[0] < 10 - n + '0')
			write(1, ", ", 2);
	}
	if (i < n && v + 1 <= '9')
	{
		string_num(str, i + 1, v + 1, n);
		string_num(str, i, v + 1, n);
	}
}

void	ft_print_combn(int n)
{
	char	str[10];

	string_num(str, 0, '0', n);
}
