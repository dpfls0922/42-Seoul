/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:16:41 by yerilee           #+#    #+#             */
/*   Updated: 2023/12/29 18:16:42 by yerilee          ###   ########.fr       */
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
		pthread_mutex_lock(&digning->philo[i].m_last_meal);
		digning->philo[i].last_meal = get_timestamp();
		pthread_mutex_unlock(&digning->philo[i].m_last_meal);
		p = &digning->philo[i];
		if (pthread_create(&p->thread_id, NULL, &thread_routine, p) != 0)
		{
			free(digning);
			return (0);
		}
		i++;
	}
	check_finish(digning);
	wait_and_cleanup_philo(digning);
	return (1);
}
