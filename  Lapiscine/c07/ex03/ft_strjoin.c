/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:32:00 by yerilee           #+#    #+#             */
/*   Updated: 2023/01/31 14:29:40 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_totallen(int size, char **strs, char *sep)
{
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		if (i == size - 1)
			break ;
		len += ft_strlen(sep);
		i++;
	}
	return (len);
}

char	*ft_allcpy(int size, char *p, char **strs, char *sep)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			p[k++] = strs[i][j++];
		if (i == size - 1)
			break ;
		j = 0;
		while (sep[j])
			p[k++] = sep[j++];
		i++;
	}
	p[k] = 0;
	return (p);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		len;
	char	*p;

	if (size == 0)
	{
		p = (char *)malloc(sizeof(char) * 1);
		p[0] = 0;
		return (p);
	}
	len = ft_totallen(size, strs, sep);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (0);
	ft_allcpy(size, p, strs, sep);
	return (p);
}

#include<stdio.h>
int main()
{
    printf("\n--ex03--\n\n");
    char    *strs[] = {"My", "Name", "is", "soonhyung", "!"};
    char    *sep = "+-+";
    char    *joined;
    joined = ft_strjoin(5, strs, sep);
    printf("ft_strjoin(0, strs, sep)\n");
    printf("address : %p\n", joined);
    printf("%s\n\n", joined);
    joined = ft_strjoin(0, strs, sep);
    printf("ft_strjoin(0, strs, sep)\n");
    printf("address : %p\n", joined);
    printf("%s\n\n", joined);
}