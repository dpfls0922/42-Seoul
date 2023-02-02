/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:58:03 by yerilee           #+#    #+#             */
/*   Updated: 2023/01/18 14:56:36 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int		i;

	i = 0;
	while (n && src[i])
	{
		dest[i] = src[i];
		i++;
		n--;
	}
	if (n)
	{	
		while (n)
		{
			dest[i] = '\0';
			i++;
			n--;
		}
	}
	return (dest);
}
