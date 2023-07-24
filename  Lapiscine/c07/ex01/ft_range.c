/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:30:33 by yerilee           #+#    #+#             */
/*   Updated: 2023/01/30 17:36:18 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int			*p;
	long long	size;
	int			i;

	if (min >= max)
		return (0);
	size = max - min;
	p = (int *)malloc(sizeof(int) * size);
	if (!p)
		return (0);
	i = 0;
	while (i < size)
	{
		p[i] = min;
		min++;
		i++;
	}
	return (p);
}
