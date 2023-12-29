/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:37:44 by yerilee           #+#    #+#             */
/*   Updated: 2023/12/29 18:01:26 by yerilee          ###   ########.fr       */
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
