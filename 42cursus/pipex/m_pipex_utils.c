/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_pipex_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:14:10 by yerilee           #+#    #+#             */
/*   Updated: 2023/09/01 17:44:32 by yerilee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "m_pipex.h"

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

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
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
