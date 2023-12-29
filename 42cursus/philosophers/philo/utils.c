/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:37:44 by yerilee           #+#    #+#             */
/*   Updated: 2023/12/29 21:43:47 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	get_timestamp(void)
{
	struct timeval	current_time;
	long long		result;

	gettimeofday(&current_time, NULL);
	result = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (result);
}

long long	get_last_meal(t_philo *philo)
{
	long long	last_meal;

	pthread_mutex_lock(&philo->m_last_meal);
	last_meal = philo->last_meal;
	pthread_mutex_unlock(&philo->m_last_meal);
	return (last_meal);
}

void	update_is_dead(t_argv *digning)
{
	pthread_mutex_lock(&digning->m_is_dead);
	digning->is_dead = 1;
	pthread_mutex_unlock(&digning->m_is_dead);
}

void	print_status(t_argv *digning, int philo_id, char *status)
{
	int	die;

	die = check_philo_dead(digning);
	pthread_mutex_lock(&digning->status);
	if (!die)
	{
		printf("%lld ", get_timestamp() - digning->created_time);
		printf("%d %s\n", philo_id + 1, status);
	}
	pthread_mutex_unlock(&digning->status);
}

int	ft_atoi(const char *str)
{
	long	n;
	long	sign;

	n = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + *str - '0';
		str++;
	}
	if ((sign * n) > 2147483647 || (sign * n) < -2147483648)
		return (-1);
	if ((*str < '0' || *str > '9') && *str != 0)
		return (-1);
	return (sign * n);
}
