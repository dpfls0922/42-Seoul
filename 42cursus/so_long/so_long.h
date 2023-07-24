/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:39:10 by yerilee           #+#    #+#             */
/*   Updated: 2023/07/24 23:18:06 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "gnl/get_next_line.h"
# include "mlx/mlx.h"

# define KEY_ESC 53
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define KEY_EXIT 17

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

typedef struct s_game {
	void			*mlx;
	void			*win;
	unsigned long	width;
	unsigned long	height;
	char			*line;
	unsigned long	walk_cnt;
}	t_game;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

void	game_init(t_game *game, char *map);
char	*setting_map(t_game *game, char *map);
int		check_line(char *line, int line_len, t_game *game, int i);
char	*ft_append_map(char *prev_line, char *new_line);
int		is_valid_line(char *line, unsigned long game_width);
int		is_rectangular(char *line, unsigned long game_width);
int		is_valid_map_wall(char *line, unsigned long game_width);

#endif