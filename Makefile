CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
FUN =  move.c allocate_free.c display_window.c error_extension.c main.c error_map.c helper.c get_next_line.c get_next_line_utils.c hook.c
OBG = $(FUN:.c=.o)
NAME = so_long
LINKING = -L/usr/include/minilibx-linux -lmlx -lXext -lX11 -lm
LIBFTPRINTF_DIR = ./ft_printf
LIBFTPRINTF = $(LIBFTPRINTF_DIR)/libftprintf.a

all: $(NAME)

$(NAME): $(OBG) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) $^ $(LINKING) -o $(NAME)
$(LIBFTPRINTF):
	make -C $(LIBFTPRINTF_DIR)
%.o: %.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm -rf $(OBG)
fclean : clean
	rm -rf $(NAME)
re : fclean all