/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:57:33 by yerilee           #+#    #+#             */
/*   Updated: 2023/12/12 15:12:21 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PILOSOPHERS_H
# define PILOSOPHERS_H

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define N 5
#define THINKING 2
#define HUNGRY 1
#define EATING 0
#define LEFT (phnum + 4) % N
#define RIGHT (phnum + 1) % N

typedef struct s_philo
{
	int			id;
	int			right_fork;
	int			left_fork;
	int			eat_cnt;
	int			last_meal;
	int			last_time;
	pthread_t	thread_id;
	t_argv		*arg;
}	t_philo;

typedef struct s_argv
{
	int		argc;
	char	**argv;
	int		numbers_of_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		must_eat;
	int		is_dead;
	int		all_ate;
	t_philo	philo[200];

	pthread_mutex_t	eat;
	pthread_mutex_t	fork[200];
	pthread_mutex_t	output;
}	t_argv;

#endif