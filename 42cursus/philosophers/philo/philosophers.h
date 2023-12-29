/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:57:33 by yerilee           #+#    #+#             */
/*   Updated: 2023/12/29 18:33:07 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	int				eat_cnt;
	pthread_mutex_t	m_last_meal;
	long long		last_meal;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_t		thread_id;
	struct s_argv	*digning;
}	t_philo;

typedef struct s_argv
{
	int				argc;
	char			**argv;
	int				numbers_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_cnt;
	pthread_mutex_t	m_total_eat_cnt;
	int				total_eat_cnt;
	pthread_mutex_t	m_is_dead;
	int				is_dead;
	long long		created_time;
	t_philo			philo[200];
	pthread_mutex_t	fork[200];
	pthread_mutex_t	status;
}	t_argv;

int			ft_init_mutex(t_argv *digning);
void		ft_init_philo(t_argv *digning);
int			ft_init_data(t_argv *digning);

int			ft_create_philo(t_argv *digning);
void		eating(t_philo *philosopher);
void		sleeping(t_argv *digning, long long time_to_sleep);
void		*thread_routine(void *ptr);

int			check_philo_eat_all(t_philo *philosopher);
int			check_philo_dead(t_argv *digning);
int			check_total_eat(t_argv *digning);
int			check_finish(t_argv *digning);

void		mutex_destroy(t_argv *digning, t_philo *philo);
int			wait_and_cleanup_philo(t_argv *digning);

int			ft_atoi(const char *str);
long long	get_timestamp(void);
void		print_status(t_argv *digning, int philo_id, char *status);

#endif