/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:26:32 by yerilee           #+#    #+#             */
/*   Updated: 2023/01/30 17:36:42 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int			*p;
	long long	size;
	int			i;

	if (min >= max)
		return (0);
	size = max - min;
	p = (int *)malloc(sizeof(int) * size);
	if (p == 0)
		return (-1);
	i = 0;
	while (i < size)
	{
		p[i] = min;
		min++;
		i++;
	}
	*range = p;
	return (size);
}
