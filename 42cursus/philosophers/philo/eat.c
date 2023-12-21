/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:04:26 by yerilee           #+#    #+#             */
/*   Updated: 2023/12/21 19:04:49 by yerilee          ###   ########.fr       */
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
