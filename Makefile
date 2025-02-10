CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
FUN = error_extension.c main.c error_map.c helper.c get_next_line.c get_next_line_utils.c free_map.c
OBG = $(FUN:.c=.o)
NAME = so_long

all: $(NAME)

$(NAME): $(OBG)
	$(CC) $(CFLAGS) $^ -o $(NAME)
%.o: %.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm -rf $(OBG)
fclean : clean
	rm -rf $(NAME)