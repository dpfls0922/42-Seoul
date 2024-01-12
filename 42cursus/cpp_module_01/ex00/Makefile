# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 17:11:27 by yerilee           #+#    #+#              #
#    Updated: 2024/01/12 17:21:32 by yerilee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	BraiiiiiiinnnzzzZ
CC		=	c++
FLAGS	=	-Wall -Wextra -std=c++98
SRCS	=	Zomie.cpp main.cpp
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