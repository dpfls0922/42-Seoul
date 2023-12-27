/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:08:01 by yerilee           #+#    #+#             */
/*   Updated: 2023/12/27 14:46:58 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_total_eat(t_argv *digning)
{
	if ((digning->must_eat_cnt != -1)
		&& (digning->numbers_of_philo == digning->total_eat_cnt))
	{
		digning->is_dead = 1;
		return (1);
	}
	return (0);
}

int	check_finish(t_argv *digning)
{
	int			i;
	long long	now;

	while (!digning->is_dead)
	{
		if (check_total_eat(digning))
			break ;
		i = 0;
		while (i < digning->numbers_of_philo)
		{
			now = get_timestamp();
			if ((now - digning->philo[i].last_meal) >= digning->time_to_die)
			{
				digning->is_dead = 1;
				pthread_mutex_lock(&digning->status);
				printf("%lld %d died\n", now - digning->created_time, i + 1);
				pthread_mutex_unlock(&digning->status);
				break ;
			}
			i++;
		}
	}
	return (0);
}
