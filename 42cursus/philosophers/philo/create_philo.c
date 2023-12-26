/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:20:59 by yerilee           #+#    #+#             */
/*   Updated: 2023/12/26 16:30:29 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_create_philo(t_argv *digning)
{
	int		i;
	t_philo	*p;

	i = 0;
	digning->created_time = get_timestamp();
	while (i < digning->numbers_of_philo)
	{
		digning->philo[i].last_meal = get_timestamp();
		p = &digning->philo[i];
		if (pthread_create(&p->thread_id, NULL, &thread_routine, p) != 0)
		{
			free(digning);
			return (0);
		}
		i++;
	}
	if (!ft_join_destroy(digning))
		return (0);
	return (1);
}
