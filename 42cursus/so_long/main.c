/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:34:33 by yerilee           #+#    #+#             */
/*   Updated: 2023/07/26 21:49:26 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	game_init(t_game *game, char *map)
{
	game->mlx = mlx_init();
	game->img = img_init(game->mlx);
	setting_map(game, map);
	if (!map_check(game))
	{
		printf("map_check Error!\n");
		exit(0);
	}
	//path_check(game);
	game->win = mlx_new_window(game->mlx, game->width * 64, game->height * 64, "so_long");
	setting_img(game);
}

void	setting_map(t_game *game, char *map)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd <= 0)
	{
		write(1, "File Error\n", 11);
		exit(0);
	}

	game->line = get_next_line(fd);
	game->width = ft_strlen(game->line) - 1;
	game->height = 0;
	game->walk_cnt = 0;
	while (1)
	{
		game->height++;
		line = get_next_line(fd);
		if (line && is_rectangular(line, game->width))
			game->line = ft_append_map(game->line, line);
		else
			break ;
	}
	free(line);
	line = 0;
	return ;
}

char	*ft_append_map(char *prev_line, char *new_line)
{
	int		i;
	int		j;
	int		len1;
	int		len2;
	char	*str;

	if (!prev_line)
		len1 = 0;
	else
		len1 = ft_strlen(prev_line);
	len2 = ft_strlen(new_line);
	str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (j < len1)
	{
		if (prev_line[j] != '\n')
			str[i++] = prev_line[j];
		j++;
	}
	j = 0;
	while (j < len2)
		str[i++] = new_line[j++];
	str[i] = '\0';
	return (str);
}

int	is_rectangular(char *line, int game_width)
{
	if (ft_strlen(line) - 1 != game_width)
	{
		printf("Map is not rectangular.\n");
		return (0);
	}
	return (1);
}

int	map_check(t_game *game)
{
	if (!is_valid_map_wall(game))
		return (0);
	if (!is_valid_map_params(game))
		return (0);
	return (1);
}

int	is_valid_map_wall(t_game *game)
{
	int	col;
	int	line_width;

	col = 0;
	line_width = ft_strlen(game->line) - 1;
	while (col < line_width)
	{
		if (col < game->width && game->line[col] != '1')
		{
			printf("Top wall is not valid\n");
			return (0);
		}
		else if (col * game->width == 0 || col % game->width == game->width - 1)
		{
			if (game->line[col] != '1')
			{
				printf("Left-Right wall is not valid\n");
				return (0);
			}
		}
		else if (col > line_width - game->width && game->line[col] != '1')
		{
			printf("Bottom wall is not valid\n");
			return (0);
		}
		col++;
	}
	return (1);
}

int	is_valid_map_params(t_game *game)
{
	int	i;
	int	line_width;

	i = 0;
	game->cnt_p = 0;
	game->cnt_e = 0;
	game->cnt_c = 0;
	game->current_c = 0;
	line_width = ft_strlen(game->line) - 1;
	while (i++ < line_width)
	{
		if (game->line[i] == 'E')
			game->cnt_e++;
		else if (game->line[i] == 'P')
			game->cnt_p++;
		else if (game->line[i] == 'C')
			game->cnt_c++;
	}
	if (game->cnt_p != 1 || game->cnt_e != 1 || game->cnt_c <= 0)
		return (0);
	return (1);
}

// 가능한 경로 있는지 확인 -> dfs로 확인할 것
// void	path_check(t_game *game)
// {
// }

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
	{
		game->line[i] = 'P';
		if (game->line[game->locate] != 'E')
			game->line[game->locate] = '0';
		game->locate = i;
		setting_img(game);
	}
	else if (game->line[i] == '1')
		return ;
	else if (game->line[i] == 'C')
	{
		game->current_c++;
		game->line[i] = 'P';
		if (game->line[game->locate] != 'E')
			game->line[game->locate] = '0';
		game->locate = i;
		setting_img(game);
	}
	else if (game->line[i] == 'E')
	{	
		if (game->cnt_c == game->current_c)
		{
			game->walk_cnt++;
			printf("Total walk count : %d\n", game->walk_cnt);
			exit(0);
		}
		else
		{
			game->line[i] = 'P';
			if (game->line[game->locate] != 'E')
				game->line[game->locate] = '0';
			game->locate = i;
			setting_img(game);
			game->line[i] = 'E';
		}
	}
	print_walk_cnt(game);
}

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	print_walk_cnt(t_game *game)
{
	game->walk_cnt++;
	printf("%d\n", game->walk_cnt);
	return (game->walk_cnt);
}

t_img	img_init(void *mlx)
{
	t_img	img;
	int		width;
	int		height;

	img.dino = mlx_xpm_file_to_image(mlx, "./images/dino.xpm", &width, &height);
	img.exit = mlx_xpm_file_to_image(mlx, "./images/exit.xpm", &width, &height);
	img.flower = mlx_xpm_file_to_image(mlx, "./images/flower.xpm", &width, &height);
	img.land = mlx_xpm_file_to_image(mlx, "./images/land.xpm", &width, &height);
	img.wall = mlx_xpm_file_to_image(mlx, "./images/wall.xpm", &width, &height);
	return (img);
}

void	setting_img(t_game *game)
{
	int	hei;
	int	wid;

	hei = 0;
	while (hei < game->height)
	{
		wid = 0;
		while (wid < game->width)
		{
			put_img_to_map(game, wid, hei);
			wid++;
		}
		hei++;
	}
}

void	put_img_to_map(t_game *game, int w, int h)
{
	if (game->line[h * game->width + w] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img.wall, w * 64, h * 64);
	else if (game->line[h * game->width + w] == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img.dino, w * 64, h * 64);
		game->locate = h * game->width + w;
	}
	else if (game->line[h * game->width + w] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img.flower, w * 64, h * 64);
	else if (game->line[h * game->width + w] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img.exit, w * 64, h * 64);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->img.land, w * 64, h * 64);

}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		printf("argc != 2\n");
		return (0);
	}
	if (ft_memcmp(ft_strchr(argv[1], '.'), ".ber", 5) != 0)
	{
		printf("This file is not .ber file.\n");
		return (0);
	}
	game = malloc(sizeof(t_game));
	if (!game)
		return (0);
	game_init(game, argv[1]);
	mlx_hook(game->win, KEY_PRESS, 0, &key_press, game);
	mlx_hook(game->win, KEY_EXIT, 0, &exit_game, game);
	mlx_loop(game->mlx);
	return (0);
}
