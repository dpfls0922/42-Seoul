/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:33:57 by yerilee           #+#    #+#             */
/*   Updated: 2023/07/26 21:33:31 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*src;

	if (!s1)
		return (0);
	src = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!src)
		return (0);
	i = 0;
	while (s1[i])
	{
		src[i] = s1[i];
		i++;
	}
	src[i] = '\0';
	return (src);
}

char	*ft_strjoin(char *s1, char *s2, int len1, int len2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (ft_strdup(s2));
	str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!str)
	{
		ft_free(&s1);
		return (0);
	}
	i = -1;
	while (++i < len1)
		str[i] = s1[i];
	j = 0;
	while (j < len2)
		str[i++] = s2[j++];
	str[i] = '\0';
	ft_free(&s1);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	if (!s)
		return (0);
	str = (char *)s;
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	return (0);
}

void	ft_free(char **p)
{
	if (*p)
	{
		free(*p);
		*p = 0;
	}
	return ;
}
