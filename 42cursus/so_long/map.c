/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 19:18:23 by yerilee           #+#    #+#             */
/*   Updated: 2023/08/01 15:32:38 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_check(t_game *game)
{
	is_rectangular(game);
	is_valid_map_wall(game);
	is_valid_map_params(game);
}

void	is_rectangular(t_game *game)
{
	if (game->width * game->height != ft_strlen(game->line))
		error("Map is not rectangular.\n");
}

void	is_valid_map_wall(t_game *game)
{
	int	col;
	int	end_width;

	col = 0;
	end_width = ft_strlen(game->line) - 1;
	while (col < end_width)
	{
		if (col < game->width && game->line[col] != '1')
			error("Top wall is not valid\n");
		else if (col * game->width == 0 || col % game->width == game->width - 1)
		{
			if (game->line[col] != '1')
				error("Left-Right wall is not valid\n");
		}
		else if (col > end_width - game->width && game->line[col] != '1')
			error("Bottom wall is not valid\n");
		col++;
	}
}

void	is_valid_map_params(t_game *game)
{
	int	i;
	int	end_index;

	i = 0;
	end_index = ft_strlen(game->line) - 1;
	while (i++ < end_index)
	{
		if (game->line[i] == 'E')
			game->cnt_e++;
		else if (game->line[i] == 'P')
			game->cnt_p++;
		else if (game->line[i] == 'C')
			game->cnt_c++;
		else
		{
			if (game->line[i] != '1' && game->line[i] != '0')
				error("Map parmas is not valid!\n");
		}
	}
	if (game->cnt_p != 1 || game->cnt_e != 1 || game->cnt_c <= 0)
		error("Map parmas is not valid!\n");
}
