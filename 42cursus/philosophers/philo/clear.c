/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:16:07 by yerilee           #+#    #+#             */
/*   Updated: 2023/12/30 01:08:47 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	mutex_destroy(t_argv *digning, t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&digning->status);
	pthread_mutex_destroy(&digning->m_is_dead);
	pthread_mutex_destroy(&digning->m_total_eat_cnt);
	while (i < digning->numbers_of_philo)
	{
		pthread_mutex_destroy(&philo[i].m_last_meal);
		pthread_mutex_destroy(philo[i].right_fork);
		pthread_mutex_destroy(philo[i].left_fork);
		i++;
	}
	free(digning);
}

int	wait_and_cleanup_philo(t_argv *digning)
{
	int	i;

	i = 0;
	while (i < digning->numbers_of_philo)
	{
		if (pthread_join(digning->philo[i].thread_id, NULL) != 0)
		{
			free(digning);
			return (0);
		}
		i++;
	}
	return (1);
}
