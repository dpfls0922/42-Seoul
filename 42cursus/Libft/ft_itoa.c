/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:21:21 by yerilee           #+#    #+#             */
/*   Updated: 2023/04/10 20:32:09 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_size(int n)
{
	int				cnt;
	unsigned int	nbr;

	cnt = 0;
	if (n < 0)
	{
		nbr = n * -1;
		cnt++;
	}
	else if (n == 0)
		return (1);
	else
		nbr = n;
	while (nbr > 0)
	{
		nbr /= 10;
		cnt++;
	}
	return (cnt);
}

unsigned int	ft_odd(int n)
{
	unsigned int	nbr;

	if (n < 0)
		nbr = n * -1;
	else
		nbr = n;
	return (nbr);
}

char	*ft_itoa(int n)
{
	char			*num;
	int				i;
	int				size;
	unsigned int	nbr;

	i = 0;
	size = get_size(n);
	num = (char *)malloc(sizeof(char) * (size + 1));
	if (!num)
		return (NULL);
	if (n < 0)
		num[i] = '-';
	nbr = ft_odd(n);
	if (nbr == 0)
		num[i] = '0';
	while (nbr > 0)
	{
		num[size - 1 - i++] = nbr % 10 + '0';
		nbr /= 10;
	}
	num[size] = 0;
	return (num);
}
