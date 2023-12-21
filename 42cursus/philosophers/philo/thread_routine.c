/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:09:21 by yerilee           #+#    #+#             */
/*   Updated: 2023/12/21 19:10:17 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	grabbing_fork(t_philo *philosopher)
{
	pthread_mutex_lock(philosopher->right_fork);
	print_status(philosopher->digning, philosopher->id, "has taken a fork");
	pthread_mutex_lock(philosopher->left_fork);
	print_status(philosopher->digning, philosopher->id, "has taken a fork");
}

void	eating(t_philo *philosopher)
{
	grabbing_fork(philosopher);
	print_status(philosopher->digning, philosopher->id, "is eating");
	philosopher->last_meal = get_timestamp();
	sleeping(philosopher->digning, philosopher->digning->time_to_eat);
	philosopher->digning->total_eat_cnt++;
	pthread_mutex_lock(&philosopher->digning->eat_cnt);
	philosopher->eat_cnt++;
	pthread_mutex_unlock(&philosopher->digning->eat_cnt);
	pthread_mutex_unlock(philosopher->right_fork);
	pthread_mutex_unlock(philosopher->left_fork);
}

void	sleeping(t_argv *digning, long long time_to_sleep)
{
	long long	begin;

	begin = get_timestamp();
	while(!(digning->is_dead))
	{
		if (get_timestamp() - begin >= time_to_sleep)
			break ;
		usleep(500);
	}
}

void	print_status(t_argv *digning, int philo_id, char *status)
{
	pthread_mutex_lock(&digning->status);
	if (!(digning->is_dead))
	{
		printf("%lld ", get_timestamp() - digning->created_time);
		printf("%d %s\n", philo_id, status);
	}
	pthread_mutex_unlock(&digning->status);
}

void	*thread_routine(void *ptr)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)ptr;
	while (!(philosopher->digning->is_dead)
		&& (philosopher->eat_cnt != philosopher->digning->must_eat_cnt))
	{
		eating(philosopher);
		print_status(philosopher->digning, philosopher->id, "is sleeping");
		sleeping(philosopher->digning, philosopher->digning->time_to_sleep);
		print_status(philosopher->digning, philosopher->id, "is thinking");
	}
	return (NULL);
}
