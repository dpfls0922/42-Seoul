/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:02:37 by yerilee           #+#    #+#             */
/*   Updated: 2023/12/21 19:03:42 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_init_mutex(t_argv *digning)
{
	int	i;

	i = 0;
	while (i < digning->numbers_of_philo)
	{
		if (pthread_mutex_init(&digning->fork[i], NULL) != 0)
		{
			free(digning);
			return (0);
		}
		i++;
	}
	if (pthread_mutex_init(&digning->eat_cnt, NULL) != 0)
	{
		free(digning);
		return (0);
	}
	if (pthread_mutex_init(&digning->status, NULL) != 0)
	{
		free(digning);
		return (0);
	}
	return (1);
}

void	ft_init_philo(t_argv *digning)
{
	int	i;

	i = 0;
	while (i < digning->numbers_of_philo)
	{
		digning->philo[i].id = i + 1;
		digning->philo[i].eat_cnt = 0;
		digning->philo[i].digning = digning;
		digning->philo[i].right_fork = &digning->fork[i];
		if (i == (digning->numbers_of_philo - 1))
			digning->philo[i].left_fork = &digning->fork[0];
		else
			digning->philo[i].left_fork = &digning->fork[i + 1];
		digning->philo[i].last_meal = 0;
		i++;
	}
}

int	ft_init_data(t_argv *digning)
{
	digning->numbers_of_philo = ft_atoi(digning->argv[1]);
	digning->time_to_die = ft_atoi(digning->argv[2]);
	digning->time_to_eat = ft_atoi(digning->argv[3]);
	digning->time_to_sleep = ft_atoi(digning->argv[4]);
	if (digning->numbers_of_philo <= 0 || digning->time_to_die < 0
		|| digning->time_to_eat < 0 || digning->time_to_sleep < 0)
		return (0);
	if (digning->argv[5])
	{
		digning->must_eat_cnt = ft_atoi(digning->argv[5]);
		if (digning->must_eat_cnt <= 0)
			return (0);
	}
	else
		digning->must_eat_cnt = -1;
	digning->is_dead = 0;
	return (1);
}