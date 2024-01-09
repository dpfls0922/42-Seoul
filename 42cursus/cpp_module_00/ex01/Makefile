# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 17:19:16 by yerilee           #+#    #+#              #
#    Updated: 2024/01/09 17:53:58 by yerilee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	PhoneBook
CC		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98
SRCS	=	Contact.cpp main.cpp PhoneBook.cpp
OBJS	=	$(SRS:.cpp=.o)

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