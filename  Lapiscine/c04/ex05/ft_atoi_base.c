/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:39:18 by yerilee           #+#    #+#             */
/*   Updated: 2023/01/23 11:57:59 by yerilee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_space(char base)
{
	while (base == ' ' || base == '\t' || base == '\n'
		|| base == '\v' || base == '\f' || base == '\r')
		return (1);
	return (0);
}

int	is_valid(char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || is_space(base[i]))
			return (0);
		j = i + 1;
		while (base[j])
		{yy
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_in_base_char(char *base_char, char c)
{
	int	i;

	i = 0;
	while (base_char[i])
	{
		if (base_char[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int		n;
	int		sign;
	int		base_len;
	int		i;

	if (!is_valid(base))
		return (0);
	n = 0;
	sign = 1;
	base_len = ft_strlen(base);
	while (is_space(*str))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	i = 0;
	while (is_in_base_char(base, str[i]) != -1)
	{
		n = n * base_len + is_in_base_char(base, str[i]);
		i++;
	}
	return (sign * n);
}
