/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:09:21 by yerilee           #+#    #+#             */
/*   Updated: 2023/12/29 17:59:58 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eating(t_philo *philosopher)
{
	pthread_mutex_lock(philosopher->left_fork);
	print_status(philosopher->digning, philosopher->id, "has taken a fork");
	if (philosopher->digning->numbers_of_philo != 1)
	{
		pthread_mutex_lock(philosopher->right_fork);
		print_status(philosopher->digning, philosopher->id, "has taken a fork");
		print_status(philosopher->digning, philosopher->id, "is eating");
		pthread_mutex_lock(&philosopher->m_last_meal);
		philosopher->last_meal = get_timestamp();
		pthread_mutex_unlock(&philosopher->m_last_meal);
		sleeping(philosopher->digning, philosopher->digning->time_to_eat);
		philosopher->eat_cnt++;
		pthread_mutex_unlock(philosopher->right_fork);
	}
	pthread_mutex_unlock(philosopher->left_fork);
}

void	sleeping(t_argv *digning, long long time_to_sleep)
{
	int			die;
	long long	begin;

	begin = get_timestamp();
	while (1)
	{
		die = check_philo_dead(digning);
		if (die)
			break ;
		if (get_timestamp() - begin >= time_to_sleep)
			break ;
		usleep(200);
	}
}

void	*thread_routine(void *ptr)
{
	int		die;
	t_argv	*digning;
	t_philo	*philosopher;

	philosopher = (t_philo *)ptr;
	digning = philosopher->digning;
	if (philosopher->id % 2 == 0 && digning->numbers_of_philo != 1)
		sleeping(digning, digning->time_to_eat);
	while (1)
	{
		die = check_philo_dead(digning);
		if (die)
			break ;
		if (digning->numbers_of_philo - 1 == philosopher->id
			&& philosopher->eat_cnt == 0)
			usleep(1);
		eating(philosopher);
		if (philosopher->digning->must_eat_cnt == philosopher->eat_cnt)
		{
			pthread_mutex_lock(&digning->m_total_eat_cnt);
			philosopher->digning->total_eat_cnt++;
			pthread_mutex_unlock(&digning->m_total_eat_cnt);
			break ;
		}
		print_status(digning, philosopher->id, "is sleeping");
		sleeping(digning, digning->time_to_sleep);
		print_status(digning, philosopher->id, "is thinking");
	}
	return (NULL);
}
