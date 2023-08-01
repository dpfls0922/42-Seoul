/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:39:10 by yerilee           #+#    #+#             */
/*   Updated: 2023/08/01 14:58:56 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "Libft/libft.h"
# include "gnl/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include "mlx/mlx.h"

# define KEY_ESC 53
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define KEY_EXIT 17

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

typedef struct s_img {
	void	*dongle;
	void	*exit;
	void	*flower;
	void	*land;
	void	*wall;
}	t_img;

typedef struct s_game {
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	int		cnt_p;
	int		cnt_e;
	int		cnt_c;
	int		current_c;
	char	*line;
	t_img	img;
	int		locate;
	int		walk_cnt;
	int		path_valid;
	int		path_check_c;
}	t_game;

void	game_init(t_game *game, char *map);
void	setting_map(t_game *game, char *map);
char	*ft_append_map(char *prev_line, char *new_line, int len1, int len2);
void	check_player_index(t_game *game, char *line);

void	map_check(t_game *game);
void	is_rectangular(t_game *game);
void	is_valid_map_wall(t_game *game);
void	is_valid_map_params(t_game *game);

void	path_check(t_game *game);
void	dfs(t_game *game, int location, char *map);
int		check_move(int i, t_game *game);

t_img	img_init(void *mlx);
void	setting_img(t_game *game, int flag);
void	put_img_to_map(t_game *game, int w, int h, int flag);

int		key_press(int keycode, t_game *game);
void	move_player(t_game *game, int i);
void	player_loaction_init(t_game *game, int i, int flag);
int		print_walk_cnt(t_game *game);
int		exit_game(t_game *game);

void	error(char *s);
void	ft_free_string(char *s);

#endif