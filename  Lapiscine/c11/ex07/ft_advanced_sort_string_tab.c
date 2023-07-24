/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:44:09 by yerilee           #+#    #+#             */
/*   Updated: 2023/02/01 10:38:11 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		is_sorted;
	int		i;
	char	*temp;

	is_sorted = 0;
	while (!is_sorted)
	{
		i = 0;
		is_sorted = 1;
		while (tab[i] != 0)
		{
			if (tab[i + 1] && cmp(tab[i], tab[i + 1]) > 0)
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
				is_sorted = 0;
			}
			i++;
		}
	}
}
