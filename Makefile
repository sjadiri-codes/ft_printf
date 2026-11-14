NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c \
	   srcs/ft_print_str.c \
	   srcs/ft_print_decimal.c \
	   srcs/ft_print_u_decimal.c \
	   srcs/ft_putchar.c \
	   srcs/ft_print_hexadecimal.c \
	   srcs/ft_print_address.c 

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o : %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: clean fclean all re
