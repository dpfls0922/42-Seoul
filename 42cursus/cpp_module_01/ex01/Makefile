# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 17:11:27 by yerilee           #+#    #+#              #
#    Updated: 2024/01/12 21:42:40 by yerilee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	HordOfZombies
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -std=c++98
SRCS		=	main.cpp Zombie.cpp ZombieHorde.cpp
OBJS		=	$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all


.PHONY: clean fclean all re