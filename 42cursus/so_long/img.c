/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 19:21:16 by yerilee           #+#    #+#             */
/*   Updated: 2023/08/01 16:34:48 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	img_init(void *mlx)
{
	t_img	img;
	int		width;
	int		height;

	img.dongle = mlx_xpm_file_to_image(mlx,
			"./textures/dongle.xpm", &width, &height);
	img.exit = mlx_xpm_file_to_image(mlx,
			"./textures/exit.xpm", &width, &height);
	img.flower = mlx_xpm_file_to_image(mlx,
			"./textures/flower.xpm", &width, &height);
	img.land = mlx_xpm_file_to_image(mlx,
			"./textures/land.xpm", &width, &height);
	img.wall = mlx_xpm_file_to_image(mlx,
			"./textures/wall.xpm", &width, &height);
	if (!img.dongle || !img.exit || !img.flower || !img.land || !img.wall)
		error("Invalid img\n");
	return (img);
}

void	setting_img(t_game *game, int flag)
{
	int	hei;
	int	wid;

	hei = 0;
	while (hei < game->height)
	{
		wid = 0;
		while (wid < game->width)
		{
			put_img_to_map(game, wid, hei, flag);
			wid++;
		}
		hei++;
	}
}

void	put_img_to_map(t_game *game, int w, int h, int flag)
{
	if (game->line[h * game->width + w] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.wall, w * 64, h * 64);
	else if (game->line[h * game->width + w] == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.land, w * 64, h * 64);
		if (flag == 1)
			mlx_put_image_to_window(game->mlx, game->win,
				game->img.exit, w * 64, h * 64);
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.dongle, w * 64, h * 64);
		game->locate = h * game->width + w;
	}
	else if (game->line[h * game->width + w] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.flower, w * 64, h * 64);
	else if (game->line[h * game->width + w] == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.exit, w * 64, h * 64);
	else
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.land, w * 64, h * 64);
}
