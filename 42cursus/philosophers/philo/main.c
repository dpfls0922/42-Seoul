/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:56:57 by yerilee           #+#    #+#             */
/*   Updated: 2023/12/13 15:37:32 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_init_data(t_argv *digning)
{
	digning->numbers_of_philo = ft_atoi(digning->argv[1]);
	digning->time_to_die = ft_atoi(digning->argv[2]);
	digning->time_to_eat = ft_atoi(digning->argv[3]);
	digning->time_to_sleep = ft_atoi(digning->argv[4]);
	if (digning->numbers_of_philo <= 0 || digning->time_to_die < 0
		|| digning->time_to_eat < 0 || digning->time_to_sleep < 0)
		return (1);
	if (digning->argv[5])
	{
		digning->must_eat = ft_atoi(digning->argv[5]);
		if (digning->must_eat <= 0)
			return (1);
	}
	else
		digning->must_eat = -1;
	digning->is_dead = 0;
	digning->all_ate = 0;
	if (digning->numbers_of_philo < 1)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_argv *digning;

	digning = (t_argv *)malloc(sizeof(t_argv));
	if (!digning)
		return (0);
	if (argc != 5 && argc != 6)
		return (-1);
	digning->argc = argc;
	digning->argv=argv;
	if(!ft_init_data(digning))
		return (1);
	if(!ft_start_mutex(digning))
		return (1);
	ft_init_philo(digning);
	if(!ft_create_philo(digning))
		return (1);
	return (0);
}
