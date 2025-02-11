CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
FUN =  display_window.c error_extension.c main.c error_map.c helper.c get_next_line.c get_next_line_utils.c free_map.c
OBG = $(FUN:.c=.o)
NAME = so_long
LINKING = -L/usr/include/minilibx-linux -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBG)
	$(CC) $(CFLAGS) $^ $(LINKING) -o $(NAME)
%.o: %.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm -rf $(OBG)
fclean : clean
	rm -rf $(NAME)