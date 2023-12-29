/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:08:01 by yerilee           #+#    #+#             */
/*   Updated: 2023/12/29 21:43:00 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_philo_eat_all(t_philo *philosopher)
{
	int	eat_all;

	eat_all = 0;
	if (philosopher->digning->must_eat_cnt == philosopher->eat_cnt)
	{
		pthread_mutex_lock(&philosopher->digning->m_total_eat_cnt);
		philosopher->digning->total_eat_cnt++;
		pthread_mutex_unlock(&philosopher->digning->m_total_eat_cnt);
		eat_all = 1;
	}
	return (eat_all);
}

int	check_philo_dead(t_argv *digning)
{
	int	die;

	die = 0;
	pthread_mutex_lock(&digning->m_is_dead);
	die = digning->is_dead;
	pthread_mutex_unlock(&digning->m_is_dead);
	return (die);
}

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
			last_meal = get_last_meal(&digning->philo[i]);
			if ((now - last_meal) > digning->time_to_die)
			{
				update_is_dead(digning);
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
