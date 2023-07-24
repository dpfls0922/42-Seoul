/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:34:33 by yerilee           #+#    #+#             */
/*   Updated: 2023/07/24 23:18:56 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	game_init(t_game *game, char *map)
{
	char	*map_line;
	game->width = 13;
	game->height = 5;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->width * 64, game->height * 64, "so_long");

	//game->img = img_init(game->mlx);
	map_line = setting_map(game, map);
	is_valid_map_wall(game->line, game->width);
	//map_check(game);
	//path_check(game);
	//setting_img(game);
}

char	*setting_map(t_game *game, char *map)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd <= 0)
		write(1, "File Error\n", 11);

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
	return (game->line);
}

int	is_rectangular(char *line, unsigned long game_width)
{
	printf("%zu\n", ft_strlen(line) - 1);

	if (ft_strlen(line) - 1 != game_width)
	{
		printf("Map is not rectangular.\n");
		return (0);
	}
	return (1);
}

int	is_valid_map_wall(char *line, unsigned long game_width)
{
	unsigned long	col;
	unsigned long	line_width;

	col = 0;
	line_width = ft_strlen(line) - 1;
	while (col < line_width)
	{
		printf("col : %lu\n", col);

		if (col < game_width && line[col] != '1')
		{
			printf("Top wall is not valid\n");
			return (0);
		}
		else if (col * game_width == 0 || col % game_width == game_width - 1)
		{
			if (line[col] != '1')
			{
				printf("Left-Right wall is not valid\n");
				return (0);
			}
		}
		else if (col > line_width - game_width && line[col] != '1')
		{
			printf("Bottom wall is not valid\n");
			return (0);
		}
		col++;
	}
	return (1);
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

// map_check(game)
	// 파일의 가로 세로 길이 가져와서 테두리 부분 check_map_wall(line) 함수로 유효성 확인하기
	// 1 -> 벽, 0 -> 지나갈 수 있는 공간, P -> 플레이어 위치, C -> 콜렉터, E -> 탈출구
	// P, E는 1개 존재, C는 1개 이상 존재 조건 확인하기

// path_check(game);
	// 가능한 경로 있는지 확인 -> dfs로 확인할 것

// int check_map_wall(char *line)
// {

// }

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_game(game);
	// else if (keycode == KEY_W)
	// 	move_up(game);
	// else if (keycode == KEY_S)
	// 	move_down(game);
	// else if (keycode == KEY_A)
	// 	move_left(game);
	// else if (keycode == KEY_D)
	// 	move_right(game);
	return (0);
}


// void	move_up(t_game *game) //y++;
// {
// }

// void	move_down(t_game *game) // y--;
// {
// }

// void	move_left(t_game *game) // x--;
// {
// }

// void	move_right(t_game *game) // x++;
// {
// }

int	main(int argc, char **argv)
{
	(void)argc;
	t_game	*game;
	t_img	*img1;
	// t_img	*img2;
	// t_img	*img3;
	// t_img	*img4;
	int img_width;
	int img_height;
	if (argc != 2)
	{
		printf("argc != 2\n");
		return (0);
	}
	game = malloc(sizeof(t_game));
	if (!game)
		return (0);
	 game_init(game, argv[1]);
	img1 = mlx_xpm_file_to_image(game->mlx, "./images/dino.xpm", &img_width, &img_height);
	mlx_put_image_to_window(game->mlx, game->win, img1, 0, 0);
	// mlx_hook(game->win, KEY_PRESS, 0, &key_press, game);
	// mlx_hook(game->win, KEY_EXIT, 0, &exit_game, game);
	mlx_loop(game->mlx);
	return (0);
}
