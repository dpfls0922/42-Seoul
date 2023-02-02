/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:43:18 by yerilee           #+#    #+#             */
/*   Updated: 2023/02/01 20:10:57 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft.h"

int	ft_strcmp(char *s1, char *s2)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *) s1;
	p2 = (unsigned char *) s2;
	while (*p1 && *p2)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
	}
	return (*p1 - *p2);
}

int	valid_op(char *op)
{
	int	len;

	len = 0;
	while (op[len])
		len++;
	if (len != 1)
		return (0);
	if (!(op[0] == '+' || op[0] == '-'
			|| op[0] == '/' || op[0] == '%' || op[0] == '*'))
		return (0);
	return (1);
}

int	do_op(char *n1, char *c, char *n2)
{
	int	(*f[5])(int, int);

	f[0] = ft_add;
	f[1] = ft_sub;
	f[2] = ft_mul;
	f[3] = ft_div;
	f[4] = ft_mod;
	if (c[0] == '+')
		return (f[0](ft_atoi(n1), ft_atoi(n2)));
	else if (c[0] == '-')
		return (f[1](ft_atoi(n1), ft_atoi(n2)));
	else if (c[0] == '*')
		return (f[2](ft_atoi(n1), ft_atoi(n2)));
	else if (c[0] == '/')
		return (f[3](ft_atoi(n1), ft_atoi(n2)));
	else if (c[0] == '%')
		return (f[4](ft_atoi(n1), ft_atoi(n2)));
	return (0);
}

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		if (!valid_op(av[2]))
		{
			write (1, "0\n", 2);
			return (0);
		}
		if (av[2][0] == '/' &&
				(ft_strcmp(av[3], "0") == 0 || ft_atoi(av[3]) == 0))
			write (1, "Stop : division by zero", 23);
		else if (av[2][0] == '%' &&
				(ft_strcmp(av[3], "0") == 0 || ft_atoi(av[3]) == 0))
			write (1, "Stop : modulo by zero", 21);
		else
			ft_putnbr(do_op(av[1], av[2], av[3]));
		write(1, "\n", 1);
	}
	return (0);
}
