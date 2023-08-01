/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 19:19:47 by yerilee           #+#    #+#             */
/*   Updated: 2023/08/01 14:58:34 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	path_check(t_game *game)
{
	char	*path_dfs;

	path_dfs = ft_strdup(game->line);
	if (!path_dfs)
		return ;
	game->path_valid = 0;
	game->path_check_c = 0;
	dfs(game, game->locate, path_dfs);
	free(path_dfs);
	if (game->path_valid != 1 || (game->cnt_c != game->path_check_c))
		error("No path\n");
}

void	dfs(t_game *game, int location, char *map)
{
	int	up;
	int	down;
	int	left;
	int	right;

	up = location - game->width;
	down = location + game->width;
	left = location - 1;
	right = location + 1;
	if (map[location] == 'C')
		game->path_check_c++;
	if (map[location] == 'E')
		game->path_valid = 1;
	map[location] = '1';
	if (check_move(up, game) && map[up] != '1')
		dfs(game, up, map);
	if (check_move(down, game) && map[down] != '1')
		dfs(game, down, map);
	if (check_move(left, game) && map[left] != '1')
		dfs(game, left, map);
	if (check_move(right, game) && map[right] != '1')
		dfs(game, right, map);
}

int	check_move(int i, t_game *game)
{
	int	end_index;

	end_index = game->width * game->height - 1;
	if (0 <= i && i <= end_index)
		return (1);
	return (0);
}
