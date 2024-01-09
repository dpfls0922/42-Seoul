# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 20:54:00 by yerilee           #+#    #+#              #
#    Updated: 2024/01/09 17:13:43 by yerilee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	megaphone
CC		=	c++
FLAGS	=	-Wall -Wextra -std=c++98
SRCS	=	megaphone.cpp
OBJS	=	$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all


.PHONY: clean fclean all re