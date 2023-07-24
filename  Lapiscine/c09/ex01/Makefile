CC = gcc
CFLAGS = -Wall -Wextra -Werror
TARGET = libft.a
SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I includes/

$(TARGET) : $(OBJS)
	ar -rc $(TARGET) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all
