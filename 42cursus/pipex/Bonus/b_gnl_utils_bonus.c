/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_gnl_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:21:57 by yerilee           #+#    #+#             */
/*   Updated: 2023/08/24 15:47:44 by yerilee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "b_pipex_bonus.h"

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
