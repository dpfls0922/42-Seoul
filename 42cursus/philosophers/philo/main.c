/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:56:57 by yerilee           #+#    #+#             */
/*   Updated: 2023/12/14 19:14:47 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	get_timestamp(void)
{
	struct timeval	current_time;
	long long		result;

	gettimeofday(&current_time, NULL);
	result = ((size_t)current_time.tv_sec * 1000) + ((size_t)current_time.tv_usec / 1000);
	return (result);
}

void	print_status(t_argv *digning, int philo_id, char *status)
{
	pthread_mutex_lock(&digning->status);
	if (!(digning->is_dead))
	{
		printf("[%lld] ", get_timestamp() - digning->created_time);
		printf("Philosopher %d %s\n", philo_id, status);
	}
	pthread_mutex_unlock(&digning->status);
}

void	sleeping(t_argv *digining, long long time_to_sleep)
{
	long long	begin;

	begin = get_timestamp();
	while(!(digining->is_dead))
	{
		if (get_timestamp() - begin >= time_to_sleep)
			break ;
		usleep(500);
	}
}

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
	// philosopher->digning->total++;
	pthread_mutex_lock(&philosopher->digning->eat);
	philosopher->eat_cnt++;
	pthread_mutex_unlock(&philosopher->digning->eat);
	pthread_mutex_unlock(philosopher->right_fork);
	pthread_mutex_unlock(philosopher->left_fork);
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

int	ft_create_philo(t_argv *digning, t_philo **philo)
{
	int	i;

	i = 0;
	digning->created_time = get_timestamp();
	while (i < digning->numbers_of_philo)
	{
		(*philo)[i].last_meal = get_timestamp();
		if (pthread_create(&((*philo)[i].thread_id), NULL, thread_routine, &philo[i]) != 0)
		{
			free(digning);
			return (0);
		}
		usleep(100);
		i++;
	}
	// 뮤텍스 제거
	return (1);
}

int	ft_start_mutex(t_argv *digning)
{
	int	i;

	i = 0;
	digning->fork = malloc(sizeof(pthread_mutex_t) * digning->numbers_of_philo);
	if (!digning->fork)
		return (1);
	while (i < digning->numbers_of_philo)
	{
		if (pthread_mutex_init(&digning->fork[i], NULL) != 0)
		{
			free(digning);
			return (0);
		}
		i++;
	}
	if (pthread_mutex_init(&digning->eat, NULL) != 0)
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

void	ft_init_philo(t_argv *digning, t_philo **philo)
{
	int		i;

	i = 0;
	*philo = malloc(sizeof(t_philo) * digning->numbers_of_philo);
	if (!philo)
		return ;
	while (i < digning->numbers_of_philo)
	{
		(*philo)[i].id = i + 1;
		(*philo)[i].eat_cnt = 0;
		(*philo)[i].right_fork = &digning->fork[i];
		if (i == (digning->numbers_of_philo - 1))
			(*philo)[i].left_fork = &digning->fork[0];
		else
			(*philo)[i].left_fork = &digning->fork[i + 1];
		(*philo)[i].last_meal = 0;
		(*philo)[i].last_time = 0;
		(*philo)[i].digning = digning;
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
		return (1);
	if (digning->argv[5])
	{
		digning->must_eat_cnt = ft_atoi(digning->argv[5]);
		if (digning->must_eat_cnt <= 0)
			return (1);
	}
	else
		digning->must_eat_cnt = -1;
	digning->is_dead = 0;
	digning->all_ate = 0;
	if (digning->numbers_of_philo < 1)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_argv	*digning;
	t_philo	**philo;

	philo = NULL;
	digning = (t_argv *)malloc(sizeof(t_argv));
	if (!digning)
		return (0);
	if (argc != 5 && argc != 6)
		return (-1);
	// input error check
	digning->argc = argc;
	digning->argv=argv;
	if(!ft_init_data(digning))
		return (1);
	if(!ft_start_mutex(digning))
		return (1);
	ft_init_philo(digning, philo);
	if(!ft_create_philo(digning, philo))
		return (1);
	return (0);
}
