/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:42:14 by yerilee           #+#    #+#             */
/*   Updated: 2023/02/01 22:03:54 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	ascend;
	int	desecnd;

	i = 0;
	ascend = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) <= 0)
			ascend++;
		i++;
	}
	i = 0;
	desecnd = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) >= 0)
			desecnd++;
		i++;
	}
	if (ascend == (length - 1) || desecnd == (length - 1) || length == 0)
		return (1);
	return (0);
}
