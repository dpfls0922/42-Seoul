/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_pipex_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:11:15 by yerilee           #+#    #+#             */
/*   Updated: 2023/09/01 17:44:27 by yerilee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "b_pipex_bonus.h"

int	ft_strlen(const char *s)
{
	int	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (ft_strdup(s2));
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
	{
		ft_free(&s1);
		return (0);
	}
	i = -1;
	while (++i < ft_strlen(s1))
		str[i] = s1[i];
	j = 0;
	while (j < ft_strlen(s2))
		str[i++] = s2[j++];
	str[i] = '\0';
	ft_free(&s1);
	return (str);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *) s1;
	p2 = (unsigned char *) s2;
	if (n <= 0)
		return (0);
	i = 0;
	while (i < n - 1 && p1[i] && p2[i])
	{
		if (p1[i] != p2[i])
			break ;
		i++;
	}
	return (p1[i] - p2[i]);
}

char	*ft_error(char *s)
{
	int	len;

	len = ft_strlen(s);
	write(2, s, len);
	write(2, "\n", 1);
	exit(0);
}
