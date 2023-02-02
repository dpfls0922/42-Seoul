/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:31:59 by yerilee           #+#    #+#             */
/*   Updated: 2023/01/30 19:27:17 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_charset(char c, char *charset)
{
	int		i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	word_count(char *str, char *charset)
{
	int		cnt;
	int		i;

	cnt = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && is_charset(str[i], charset))
			i++;
		while (str[i] && !is_charset(str[i], charset))
		{
			i++;
			cnt++;
		}
	}
	return (cnt);
}

char	*word_dup(char *str, char *charset)
{
	int		i;
	int		len;
	char	*word;

	len = 0;
	while (str[len] && !is_charset(str[len], charset))
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (0);
	i = 0;
	while (str[i] && !is_charset(str[i], charset))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**p;
	int		i;
	int		j;

	if (charset == 0)
		return (0);
	i = 0;
	p = (char **)malloc(sizeof(char *) * (word_count(str, charset) + 1));
	if (!p)
		return (0);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && is_charset(str[i], charset))
			i++;
		if (str[i] && !is_charset(str[i], charset))
			p[j++] = word_dup((str + i), charset);
		while (str[i] && !is_charset(str[i], charset))
			i++;
	}
	p[j] = 0;
	return (p);
}
