/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 09:56:45 by yerilee           #+#    #+#             */
/*   Updated: 2023/02/02 14:41:08 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_dec_to_hex(unsigned long long addr)
{
	if (addr > 15)
	{
		ft_dec_to_hex(addr / 16);
		ft_dec_to_hex(addr % 16);
	}
	else
		write(1, &"0123456789abcdef"[addr % 16], 1);
}

void	ft_print_addr(unsigned long long addr)
{
	int					n;
	unsigned long long	temp;

	n = 0;
	temp = addr;
	while (temp)
	{
		temp /= 16;
		n++;
	}
	temp = 0;
	while (n + temp < 16)
	{
		write(1, "0", 1);
		temp++;
	}
	ft_dec_to_hex(addr);
	write(1, ":", 1);
}

void	ft_print_hex(unsigned char *addr, unsigned int length)
{
	unsigned int	i;

	i = 0;
	while (i < length)
	{
		if (i % 2 == 0)
			write(1, " ", 1);
		write(1, &"0123456789abcdef"[addr[i] / 16], 1);
		write(1, &"0123456789abcdef"[addr[i] % 16], 1);
		i++;
	}
	while (i < 16)
	{
		if (i % 2 == 0)
			write(1, " ", 1);
		write(1, "  ", 2);
		i++;
	}
}

void	ft_print_ascii(unsigned char *addr, unsigned int length)
{
	unsigned int	i;

	i = 0;
	while (i < length)
	{
		if (32 <= addr[i] && addr[i] < 127)
			write(1, addr + i, 1);
		else
			write(1, ".", 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	length;
	int				i;

	i = 0;
	while (size)
	{
		if (size / 16)
			length = 16;
		else
			length = size;
		ft_print_addr((unsigned long long)(addr + i));
		ft_print_hex(addr + i, length);
		write(1, " ", 1);
		ft_print_ascii(addr + i, length);
		write(1, "\n", 1);
		size -= length;
		i += 16;
	}
	return (addr);
}
