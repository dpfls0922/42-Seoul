/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:26:42 by yerilee           #+#    #+#             */
/*   Updated: 2023/01/18 17:53:05 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_lower(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	is_upper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	is_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int		i;

	if (is_lower(str[0]))
		str[0] = str[0] - 'a' + 'A';
	i = 1;
	while (str[i])
	{
		if (is_lower(str[i - 1]) || is_upper(str[i - 1])
			|| is_numeric(str[i - 1]))
		{
			if (is_upper(str[i]))
				str[i] = str[i] - 'A' + 'a';
		}
		else
		{
			if (is_lower(str[i]))
				str[i] = str[i] - 'a' + 'A';
		}
		i++;
	}
	return (str);
}
