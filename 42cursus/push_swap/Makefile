# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 15:43:10 by yerilee           #+#    #+#              #
#    Updated: 2023/09/28 17:23:41 by yerilee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c\
		command_pa_pb.c command_ra_rb_rr.c command_rra_rrb_rrr.c command_sa_sb_ss.c\
		ft_atoi.c ft_split.c ft_free.c\
		check.c greedy.c min.c pivot.c push_pop.c run_rb_ra.c sort.c stack.c

SRCS_BONUS = push_swap_bonus.c\
		command_pa_pb_bonus.c command_ra_rb_rr_bonus.c command_rra_rrb_rrr_bonus.c command_sa_sb_ss_bonus.c\
		ft_atoi_bonus.c ft_split_bonus.c ft_free_bonus.c\
		gnl_bonus.c gnl_utils_bonus.c\
		check_bonus.c print_error_success_bonus.c push_pop_bonus.c stack_bonus.c

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