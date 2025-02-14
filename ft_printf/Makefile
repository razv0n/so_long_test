FUN = printf_utilis.c printf_utilis_2.c ft_printf.c
CC = cc
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
OBJ = $(FUN:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar -rcs $(NAME) $(OBJ)
%.o : %.c
	$(CC) $(CFLAGS) -c $<
clean :
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)
re : fclean all

.PHONY : fclean clean all re