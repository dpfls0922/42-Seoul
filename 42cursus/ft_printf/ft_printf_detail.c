/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_detail.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 22:21:22 by yerilee           #+#    #+#             */
/*   Updated: 2023/06/27 14:24:29 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_s(char *str)
{
	int	len;

	len = 0;
	if (!str)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (*str)
	{
		if (ft_printf_c(*str) == -1)
			return (-1);
		len++;
		str++;
	}
	return (len);
}

int	ft_printf_p(unsigned long long p)
{
	int		i;
	int		len;
	char	arr[20];

	i = 0;
	len = 0;
	if (ft_printf_s("0x") == -1)
		return (-1);
	while (p >= 16)
	{
		arr[i] = "0123456789abcdef"[p % 16];
		p /= 16;
		i++;
	}
	arr[i] = "0123456789abcdef"[p];
	len = ft_print_arr(arr, i, len);
	if (len == -1)
		return (-1);
	return (len + 2);
}

int	ft_printf_di(long long n)
{
	int		i;
	int		len;
	char	arr[20];

	i = 0;
	len = 0;
	if (n < 0)
	{
		if (ft_printf_c('-') == -1)
			return (-1);
		n *= -1;
		len++;
	}
	while (n >= 10)
	{
		arr[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	arr[i] = n + '0';
	len = ft_print_arr(arr, i, len);
	if (len == -1)
		return (-1);
	return (len);
}

int	ft_printf_u(unsigned int n)
{
	int		i;
	int		len;
	char	arr[10];

	i = 0;
	len = 0;
	while (n >= 10)
	{
		arr[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	arr[i] = n + '0';
	len = ft_print_arr(arr, i, len);
	if (len == -1)
		return (-1);
	return (len);
}

int	ft_printf_x(unsigned int n, char flag)
{
	int		i;
	int		len;
	char	arr[10];
	char	*hexa;

	i = 0;
	len = 0;
	if (flag == 'x')
		hexa = "0123456789abcdef";
	else
		hexa = "0123456789ABCDEF";
	while (n >= 16)
	{
		arr[i] = hexa[n % 16];
		n /= 16;
		i++;
	}
	arr[i] = hexa[n];
	len = ft_print_arr(arr, i, len);
	if (len == -1)
		return (-1);
	return (len);
}
