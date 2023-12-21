/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:33:33 by yerilee           #+#    #+#             */
/*   Updated: 2023/12/21 19:16:59 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	mutex_destroy(t_argv *digning, t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&digning->status);
	pthread_mutex_destroy(&digning->eat_cnt);
	while (i < digning->numbers_of_philo)
	{
		pthread_detach(philo[i].thread_id);
		pthread_mutex_destroy(philo[i].right_fork);
		pthread_mutex_destroy(philo[i].left_fork);
		i++;
	}
}

int ft_join_destroy(t_argv *digning)
{
	int	i;

	if (check_dead(digning))
	{
		mutex_destroy(digning, digning->philo);
		free(digning);
		return (0);
	}
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

int	main(int argc, char **argv)
{
	t_argv	*digning;

	digning = (t_argv *)malloc(sizeof(t_argv));
	if (!digning)
		return (0);
	if (argc != 5 && argc != 6)
		return (-1);
	// input error check
	digning->argc = argc;
	digning->argv = argv;
	if(!ft_init_data(digning))
		return (1);
	if(!ft_init_mutex(digning))
		return (1);
	ft_init_philo(digning);
	if(!ft_create_philo(digning))
		return (1);
	return (0);
}
