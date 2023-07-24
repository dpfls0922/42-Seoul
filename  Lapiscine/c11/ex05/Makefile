CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = do-op

SRCS = srcs/ft_add.c srcs/ft_sub.c srcs/ft_mul.c srcs/ft_div.c srcs/ft_mod.c srcs/ft_atoi.c srcs/ft_putnbr.c srcs/main.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean :
	rm -rf $(OBJS)
	
fclean : clean
	rm -rf $(NAME)

re: fclean all
