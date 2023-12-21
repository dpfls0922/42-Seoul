/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:57:33 by yerilee           #+#    #+#             */
/*   Updated: 2023/12/21 19:05:15 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PILOSOPHERS_H
# define PILOSOPHERS_H

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct s_philo
{
	int				id;
	int				eat_cnt;
	long long		last_meal;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_t		thread_id;
	struct s_argv	*digning;
}	t_philo; 

typedef struct s_argv
{
	int			argc;
	char		**argv;
	int			numbers_of_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			must_eat_cnt;
	int			total_eat_cnt;
	int			is_dead;
	long long	created_time;
	t_philo		philo[200];

	pthread_mutex_t	fork[200];
	pthread_mutex_t	eat_cnt;
	pthread_mutex_t	status;
}	t_argv;

int		check_numeric(const char *str, int i);
int		ft_atoi(const char *str);


int		ft_init_mutex(t_argv *digning);
void	ft_init_philo(t_argv *digning);
int		ft_init_data(t_argv *digning);


#endif