/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:34:33 by yerilee           #+#    #+#             */
/*   Updated: 2023/08/01 16:23:10 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_game *game, char *map)
{
	game->cnt_p = 0;
	game->cnt_e = 0;
	game->cnt_c = 0;
	game->current_c = 0;
	game->height = 0;
	game->walk_cnt = 0;
	game->mlx = mlx_init();
	game->img = img_init(game->mlx);
	setting_map(game, map);
	map_check(game);
	path_check(game);
	game->win = mlx_new_window(game->mlx, game->width * 64,
			game->height * 64, "so_long");
	setting_img(game, 0);
}

void	setting_map(t_game *game, char *map)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		error("File Error\n");
	game->line = get_next_line(fd);
	if (ft_strlen(game->line) == 0)
		error("Empty\n");
	game->width = ft_strlen(game->line) - 1;
	while (1)
	{
		if (ft_memcmp(line, "\n", 1) != 0)
			game->height++;
		line = get_next_line(fd);
		if (line && (ft_strlen(line) - 1 == game->width
				|| ft_strlen(line) == game->width))
			game->line = ft_append_map(game->line, line,
					ft_strlen(game->line), ft_strlen(line));
		else
			break ;
		ft_free_string(line);
	}
	check_player_index(game, game->line);
	ft_free_string(line);
}

char	*ft_append_map(char *prev_line, char *new_line, int len1, int len2)
{
	int		i;
	int		j;
	char	*str;

	str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!str)
	{
		ft_free_string(prev_line);
		return (0);
	}
	i = 0;
	j = -1;
	while (++j < len1)
		if (prev_line[j] != '\n')
			str[i++] = prev_line[j];
	j = -1;
	while (++j < len2)
		if (new_line[j] != '\n')
			str[i++] = new_line[j];
	str[i] = '\0';
	ft_free_string(prev_line);
	return (str);
}

void	check_player_index(t_game *game, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'P')
			game->locate = i;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		error("argc != 2\n");
	if (ft_strrchr(argv[1], '.') == 0
		|| ft_memcmp(ft_strrchr(argv[1], '.'), ".ber\0", 5) != 0)
		error("This file is not .ber file.\n");
	game = malloc(sizeof(t_game));
	if (!game)
		return (0);
	game_init(game, argv[1]);
	mlx_hook(game->win, KEY_PRESS, 0, &key_press, game);
	mlx_hook(game->win, KEY_EXIT, 0, &exit_game, game);
	mlx_loop(game->mlx);
	return (0);
}
