/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:08:01 by yerilee           #+#    #+#             */
/*   Updated: 2023/12/26 16:31:35 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_total_eat(t_argv *digning)
{
	if (digning->argc == 6)
	{
		if (digning->total_eat_cnt
			>= digning->numbers_of_philo * digning->must_eat_cnt)
			return (1);
	}
	return (0);
}

int	check_finish(t_argv *digning)
{
	long long	current_time;
	long long	last_meal_time;

	while (digning->numbers_of_philo >= 1)
	{
		if (check_total_eat(digning))
			return (1);
		current_time = get_timestamp();
		last_meal_time = digning->philo[0].last_meal;
		if (current_time - last_meal_time >= digning->time_to_die)
		{
			digning->is_dead = 1;
			pthread_mutex_lock(&digning->status);
			printf("%lld 1 died\n", current_time - digning->created_time);
			pthread_mutex_unlock(&digning->status);
			return (1);
		}
	}
	return (0);
}
