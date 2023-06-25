/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:35:23 by yerilee           #+#    #+#             */
/*   Updated: 2023/04/11 21:00:28 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*res;
	void	*temp;

	if (!f || !del)
		return (NULL);
	newlst = 0;
	while (lst)
	{
		temp = (*f)(lst->content);
		res = ft_lstnew(temp);
		if (!res)
		{
			ft_lstclear(&newlst, del);
			free(temp);
			return (NULL);
		}
		ft_lstadd_back(&newlst, res);
		lst = lst->next;
	}
	return (newlst);
}
