/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:13:13 by yerilee           #+#    #+#             */
/*   Updated: 2023/01/30 21:50:06 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);
int	base_is_valid(char *base);
int	is_in_base_char(char *base_char, char c);

int	ft_atoi_base(char *str, char *base_from)
{
	int		n;
	int		sign;
	int		base_len;
	int		i;

	n = 0;
	sign = 1;
	base_len = ft_strlen(base_from);
	while (*str == ' ' || ('\t' <= *str && *str <= '\r'))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	i = 0;
	while (is_in_base_char(base_from, str[i]) != -1)
	{
		n = n * base_len + is_in_base_char(base_from, str[i]);
		i++;
	}
	return (sign * n);
}

int	get_size(int nbr, char *to_base)
{
	int			cnt;
	long long	n;

	cnt = 0;
	n = (long long)nbr;
	if (n < 0)
		n *= -1;
	else if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= ft_strlen(to_base);
		cnt++;
	}
	return (cnt);
}

char	*ft_putnbr_base(int nbr, char *dest, char *base_to)
{
	int			i;
	long long	n;

	i = get_size(nbr, base_to);
	n = (long long)nbr;
	if (n < 0)
	{
		dest[0] = '-';
		n *= -1;
		i++;
	}
	else if (n == 0)
		dest[0] = base_to[0];
	dest[i] = 0;
	while (n > 0)
	{
		i--;
		dest[i] = base_to[n % ft_strlen(base_to)];
		n /= ft_strlen(base_to);
	}
	return (dest);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		dec;
	int		size;
	char	*p;

	if (!base_is_valid(base_from) || !base_is_valid(base_to))
		return (0);
	dec = ft_atoi_base(nbr, base_from);
	size = get_size(dec, base_to) + 1;
	if (dec < 0)
		size++;
	p = (char *)malloc(sizeof(char) * size);
	if (!p)
		return (0);
	return (ft_putnbr_base(dec, p, base_to));
}
