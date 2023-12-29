/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:33:33 by yerilee           #+#    #+#             */
/*   Updated: 2023/12/29 17:40:35 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_argv	*digning;

	digning = (t_argv *)malloc(sizeof(t_argv));
	if (!digning)
		return (0);
	if (argc != 5 && argc != 6)
	{
		free(digning);
		return (1);
	}
	digning->argc = argc;
	digning->argv = argv;
	if (!ft_init_data(digning))
	{
		free(digning);
		return (1);
	}
	if (!ft_init_mutex(digning))
	{
		free(digning);
		return (1);
	}
	ft_init_philo(digning);
	ft_create_philo(digning);
	mutex_destroy(digning, digning->philo);
	return (0);
}
