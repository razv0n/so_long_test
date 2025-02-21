CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
FUN =  ./move_player/move.c ./allocation_free/allocate_free.c ./show_window/display_window.c ./cheak_error/error_map2.c ./main/main.c ./cheak_error/error_map.c ./helper/helper.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c ./move_player/hook.c ./show_window/start_window.c 
OBG = $(FUN:.c=.o)
NAME = so_long

LINKING = -L/usr/include/minilibx-linux -lmlx -lXext -lX11 -lm
LIBFTPRINTF_DIR = ./ft_printf
LIBFTPRINTF = $(LIBFTPRINTF_DIR)/libftprintf.a
MOVE_PLAYER_DIR = move_player
ALLOCATION_FREE_DIR = allocation_free
SHOW_WINDOW_DIR = show_window
CHEAK_ERROR_DIR = cheak_error
MAIN_DIR = main
HELPER_DIR = helper
GET_NEXT_LINE_DIR = get_next_line
FUN_BNS = ./bonus/anim/animation_player.c ./allocation_free/allocate_free.c ./bonus/allocation_free_bonus/add_enemy.c ./bonus/move_player_bonus/move_bonus.c ./bonus/allocation_free_bonus/allocate_free_bonus.c ./bonus/cheak_error_bonus/error_map2_bonus.c ./bonus/cheak_error_bonus/error_map_bonus.c  ./bonus/helper_bonus/helper_bonus.c   ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c ./bonus/show_window_bonus/start_window_bonus.c  ./bonus/show_window_bonus/display_window_bonus.c  ./bonus/main_bonus/main_bonus.c  ./helper/helper.c  ./bonus/move_player_bonus/hook_bonus.c ./show_window/start_window.c ./cheak_error/error_map.c ./cheak_error/error_map2.c
OGJ_BNS = $(FUN_BNS:.c=.o)

GREEN = \033[32m
RESET = \033[0m
BLACK = \033[30m
RED = \033[31m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m

all: BANNER $(NAME)

$(NAME): $(OBG) $(LIBFTPRINTF)
	@echo "$(BLUE)Compiling project...$(RESET)"
	$(CC) $(CFLAGS) $^ $(LINKING) -o $(NAME)
	@echo "$(GREEN)✅ Build Successful!$(RESET)"

$(LIBFTPRINTF):
	make -C $(LIBFTPRINTF_DIR)

%.o: %.c
	@echo "$(BLUE)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

%.o: $(MOVE_PLAYER_DIR)/%.c
	@echo "$(BLUE)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

%.o: $(ALLOCATION_FREE_DIR)/%.c
	@echo "$(BLUE)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

%.o: $(SHOW_WINDOW_DIR)/%.c
	@echo "$(BLUE)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

%.o: $(CHEAK_ERROR_DIR)/%.c
	@echo "$(BLUE)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

%.o: $(MAIN_DIR)/%.c
	@echo "$(BLUE)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

%.o: $(HELPER_DIR)/%.c
	@echo "$(BLUE)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

%.o: $(GET_NEXT_LINE_DIR)/%.c
	@echo "$(BLUE)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

%.o: bonus/move_player_bonus/%.c
	@echo "$(BLUE)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

%.o: bonus/allocation_free_bonus/%.c
	@echo "$(BLUE)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

%.o: bonus/main_bonus/%.c
	@echo "$(BLUE)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

%.o: bonus/show_window_bonus/%.c
	@echo "$(BLUE)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

%.o: bonus/anim/%.c
	@echo "$(BLUE)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

%.o: bonus/helper_bonus/%.c
	@echo "$(BLUE)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

%.o: bonus/cheak_error_bonus/%.c
	@echo "$(BLUE)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

bonus: BANNER $(OGJ_BNS) $(LIBFTPRINTF)
	@echo "$(BLUE)Compiling bonus project...$(RESET)"
	$(CC) $(CFLAGS) $^ $(LINKING) -o so_long_bonus
	@echo "$(GREEN)✅ Bonus Build Successful!$(RESET)"

clean:
	@echo "$(CYAN)🧹 Cleaning object files...$(RESET)"
	rm -rf $(OBG) $(OGJ_BNS)

fclean: clean
	@echo "$(CYAN)🗑️ Removing executable...$(RESET)"
	rm -rf $(NAME) so_long_bonus BANNER

re: fclean all

BANNER:
	@sleep 0.2
	@echo "$(MAGENTA)		███████╗ ██████╗      ██╗      ██████╗ ███╗   ██╗ ██████╗$(RESET)"
	@sleep 0.1
	@echo "$(MAGENTA)		██╔════╝██╔═══██╗     ██║     ██╔═══██╗████╗  ██║██╔════╝$(RESET)"
	@sleep 0.1
	@echo "$(MAGENTA)		███████╗██║   ██║     ██║     ██║   ██║██╔██╗ ██║██║  ███╗$(RESET)"
	@sleep 0.1
	@echo "$(MAGENTA)		╚════██║██║   ██║     ██║     ██║   ██║██║╚██╗██║██║   ██║$(RESET)"
	@sleep 0.1
	@echo "$(MAGENTA)		███████║╚██████╔╝     ███████╗╚██████╔╝██║ ╚████║╚██████╔╝$(RESET)"
	@sleep 0.1
	@echo "$(MAGENTA)		╚══════╝ ╚═════╝      ╚══════╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝$(RESET)"
	@echo ""
	@echo "		$(CYAN)✨ Welcome to $(YELLOW)so_long $(CYAN)✨$(RESET)"
	@echo ""
	@echo "		$(GREEN)🌟 Project created by: $(YELLOW)Moncef $(GREEN)🌟$(RESET)"
	@echo "		$(GREEN)🏫 School: $(YELLOW)1337 Coding School $(GREEN)🏫$(RESET)"
	@echo "		$(GREEN)🔑 Login: $(YELLOW)mfahmi $(GREEN)🔑$(RESET)"
	@echo ""
	@echo "		$(BLUE)🚀 Ready to explore? Let’s get started! 🚀$(RESET)"
	@echo ""
	@echo "		$(RED)❤️  Enjoy using the project! ❤️$(RESET)"
	@touch BANNER

.PHONY: re fclean clean all BANNER bonus