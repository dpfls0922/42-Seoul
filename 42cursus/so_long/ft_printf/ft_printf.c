/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:40:52 by yerilee           #+#    #+#             */
/*   Updated: 2023/06/27 14:19:27 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_c(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_print_arr(char *c, int i, int len)
{
	while (i >= 0)
	{
		if (ft_printf_c(c[i]) == -1)
			return (-1);
		i--;
		len++;
	}
	return (len);
}

int	check_sign(va_list *ap, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len = ft_printf_c((char)va_arg(*ap, int));
	else if (format == 's')
		len = ft_printf_s(va_arg(*ap, char *));
	else if (format == 'p')
		len = ft_printf_p(va_arg(*ap, unsigned long long));
	else if (format == 'd' || format == 'i')
		len = ft_printf_di(va_arg(*ap, int));
	else if (format == 'u')
		len = ft_printf_u(va_arg(*ap, unsigned int));
	else if (format == 'x')
		len = ft_printf_x(va_arg(*ap, unsigned int), 'x');
	else if (format == 'X')
		len = ft_printf_x(va_arg(*ap, unsigned int), 'X');
	else if (format == '%')
		len = ft_printf_c('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	int		sum;
	va_list	ap;

	sum = 0;
	va_start(ap, format);
	while (*format)
	{
		len = 1;
		if (*format == '%')
		{
			format++;
			len = check_sign(&ap, *format++);
			if (len == -1)
				return (-1);
		}
		else
		{
			if (ft_printf_c(*format++) == -1)
				return (-1);
		}
		sum += len;
	}
	va_end(ap);
	return (sum);
}
