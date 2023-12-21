/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:06:24 by yerilee           #+#    #+#             */
/*   Updated: 2023/12/21 19:06:49 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	sleeping(t_argv *digning, long long time_to_sleep)
{
	long long	begin;

	begin = get_timestamp();
	while(!(digning->is_dead))
	{
		if (get_timestamp() - begin >= time_to_sleep)
			break ;
		usleep(500);
	}
}
