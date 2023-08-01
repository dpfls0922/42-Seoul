/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 19:22:06 by yerilee           #+#    #+#             */
/*   Updated: 2023/08/01 13:59:56 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_game(game);
	else if (keycode == KEY_W)
		move_player(game, game->locate - game->width);
	else if (keycode == KEY_S)
		move_player(game, game->locate + game->width);
	else if (keycode == KEY_A)
		move_player(game, game->locate - 1);
	else if (keycode == KEY_D)
		move_player(game, game->locate + 1);
	return (0);
}

void	move_player(t_game *game, int i)
{
	if (game->line[i] == '0')
		player_loaction_init(game, i, 0);
	else if (game->line[i] == '1')
		return ;
	else if (game->line[i] == 'C')
	{
		game->current_c++;
		player_loaction_init(game, i, 0);
	}
	else if (game->line[i] == 'E')
	{	
		if (game->cnt_c == game->current_c)
		{
			game->walk_cnt++;
			ft_printf("Total walk count : %d\n", game->walk_cnt);
			exit(0);
		}
		else
		{
			player_loaction_init(game, i, 1);
			game->line[i] = 'E';
		}
	}
	print_walk_cnt(game);
}

void	player_loaction_init(t_game *game, int i, int flag)
{
	game->line[i] = 'P';
	if (game->line[game->locate] != 'E')
		game->line[game->locate] = '0';
	game->locate = i;
	setting_img(game, flag);
}

int	print_walk_cnt(t_game *game)
{
	game->walk_cnt++;
	ft_printf("%d\n", game->walk_cnt);
	return (game->walk_cnt);
}

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}
