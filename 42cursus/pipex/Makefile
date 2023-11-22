# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/24 16:08:20 by yerilee           #+#    #+#              #
#    Updated: 2023/11/23 01:46:18 by yerilee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_BONUS = pipex_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = Mandatory/m_pipex.c Mandatory/m_pipex_utils.c Mandatory/m_split.c

SRCS_BONUS = Bonus/b_pipex_bonus.c Bonus/b_pipex_utils_bonus.c Bonus/b_split_bonus.c Bonus/b_gnl_bonus.c Bonus/b_gnl_utils_bonus.c Bonus/b_here_doc_bonus.c

OBJS = $(SRCS:.c=.o)

OBJSB = $(SRCS_BONUS:.c=.o)

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	
$(NAME_BONUS): $(OBJSB)
	$(CC) $(CFLAGS) $(OBJSB) -o $(NAME_BONUS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJSB)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: clean fclean all re bonus