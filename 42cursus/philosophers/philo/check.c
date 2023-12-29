/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:08:01 by yerilee           #+#    #+#             */
/*   Updated: 2023/12/29 17:56:08 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_total_eat(t_argv *digning)
{
	int	total;

	pthread_mutex_lock(&digning->m_total_eat_cnt);
	total = digning->total_eat_cnt;
	pthread_mutex_unlock(&digning->m_total_eat_cnt);
	if ((digning->must_eat_cnt != 0) && (digning->numbers_of_philo == total))
	{
		pthread_mutex_lock(&digning->m_is_dead);
		digning->is_dead = 1;
		pthread_mutex_unlock(&digning->m_is_dead);
		return (1);
	}
	return (0);
}

int	check_finish(t_argv *digning)
{
	int			i;
	long long	now;
	long long	last_meal;

	while (1)
	{
		if (check_total_eat(digning))
			return (1);
		i = 0;
		while (i < digning->numbers_of_philo)
		{
			now = get_timestamp();
			pthread_mutex_lock(&digning->philo[i].m_last_meal);
			last_meal = digning->philo[i].last_meal;
			pthread_mutex_unlock(&digning->philo[i].m_last_meal);
			if ((now - last_meal) > digning->time_to_die)
			{
				pthread_mutex_lock(&digning->m_is_dead);
				digning->is_dead = 1;
				pthread_mutex_unlock(&digning->m_is_dead);
				pthread_mutex_lock(&digning->status);
				printf("%lld %d died\n", now - digning->created_time, i + 1);
				pthread_mutex_unlock(&digning->status);
				return (1);
			}
			i++;
		}
	}
	return (0);
}
