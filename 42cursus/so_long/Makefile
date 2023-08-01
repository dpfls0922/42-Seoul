# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/20 20:58:07 by yerilee           #+#    #+#              #
#    Updated: 2023/07/29 19:25:15 by yerilee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c\
		img.c \
		key.c \
		map.c \
		path.c \
		error_free.c \
		Libft/ft_memcmp.c \
		Libft/ft_strrchr.c \
		Libft/ft_strlenn.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \
		ft_printf/ft_printf.c \
		ft_printf/ft_printf_detail.c \

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) :$(OBJS)
	make -C mlx
	$(CC) $(CFLAGS) -L ./mlx -lmlx -framework OpenGL -framework AppKit -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	make clean -C mlx
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re