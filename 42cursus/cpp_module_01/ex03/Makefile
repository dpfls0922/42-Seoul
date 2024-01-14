# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 22:32:03 by yerilee           #+#    #+#              #
#    Updated: 2024/01/14 12:05:31 by yerilee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Weapon
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
SRCS		=	HumanA.cpp HumanB.cpp main.cpp Weapon.cpp
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