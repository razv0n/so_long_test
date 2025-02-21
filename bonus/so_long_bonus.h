#ifndef SO_LONG_BONUS_H
#define SO_LONG_BONUS_H



# define WALL_XPM			"assets/sprites/wall.xpm"
# define FLOOR_XPM			"assets/sprites/floor.xpm"
# define COINS_XPM			"assets/sprites/coin-bag.xpm"
# define COINS_POWER        "assets/sprites/coin.xpm"
# define PLAYER_FRONT_XPM	"assets/sprites/player/semi_front.xpm"
# define PLAYER_LEFT_XPM	"assets/sprites/player/semi_left.xpm"
# define PLAYER_RIGHT_XPM	"assets/sprites/player/semi_right.xpm"
# define PLAYER_BACK_XPM	"assets/sprites/player/semi_back.xpm"
# define PLAYER_UP_XPM		"assets/sprites/player/up.xpm"
# define PLAYER_DOWN_XPM	"assets/sprites/player/down.xpm"
# define PLAYER_RIGHT_ALL    "assets/sprites/player/right.xpm"
# define PLAYER_LEFT_ALL     "assets/sprites/player/left.xpm"
# define PLAYER_CLOSE_XPM    "assets/sprites/player/close.xpm"
# define OPEN_EXIT_XPM		"assets/sprites/open-exit.xpm"
# define EXIT_CLOSED_XPM	"assets/sprites/exit-closed.xpm"
# define START_XPM          "assets/sprites/start/start.xpm"
# define START_EXIT_XPM     "assets/sprites/start/exit_game.xpm"

# define ENEMY_DOWN_1       "assets/sprites/enemy/B/en_down1.xpm"
# define ENEMY_DOWN_2       "assets/sprites/enemy/B/en_down2.xpm"
# define ENEMY_UP_1       "assets/sprites/enemy/B/en_up1.xpm"
# define ENEMY_UP_2       "assets/sprites/enemy/B/en_up2.xpm"
# define ENEMY_LEFT_1       "assets/sprites/enemy/B/en_left1.xpm"
# define ENEMY_LEFT_2       "assets/sprites/enemy/B/en_left2.xpm"
# define ENEMY_RIGHT_1       "assets/sprites/enemy/B/en_right1.xpm"
# define ENEMY_RIGHT_2       "assets/sprites/enemy/B/en_right2.xpm"

# define IMG_HEIGHT			32
# define IMG_WIDTH			32
# define ESC                 65307
# define ENTER               65293
#define KEY_w                119
#define KEY_s                115
#define KEY_a                97
#define KEY_d                100
#define KEY_up               65362
#define KEY_down             65364 
#define KEY_left             65361
#define KEY_right            65363

#include "../get_next_line/get_next_line.h"
#include "../ft_printf/ft_printf.h"
#include <fcntl.h>
#include <stdlib.h>
#include <math.h>
#include "/usr/include/minilibx-linux/mlx.h"
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
enum e_direction
{
    UP_D,
    DOWN_D,
    LEFT_D,
    RIGHT_D,
};

enum e_index
{
    EXIT,
    PLAYER,
    ENEMY,
};
enum e_msg
{
    EXIT_GAME,
    WIN_GAME,
    LOSE_GAME,
};

typedef struct t_x_y
{
    int x; //* index i
    int y; //* index j
}t_position;

typedef struct width_heigh
{
    int width;
    int height;
}t_wihe;

typedef struct imgs
{
    void *img_player_front;
    void *img_player_back;
    void *img_player_right;
    void *img_player_left;
    void *img_player_right_a;
    void *img_player_left_a;
    void *img_player_up;
    void *img_player_down;
    void *img_player_close;
    void *img_floor;
    void *img_wall;
    void *img_coin;
    void *img_exit;
    void  *img_start;
    void  *img_start_exit;
    void *img_exit_close;
    void *img_exit_open;
    void *img_enemy_down1;
    void *img_enemy_down2;
    void *img_enemy_up1;
    void *img_enemy_up2;
    void *img_enemy_left1;
    void *img_enemy_left2;
    void *img_enemy_right1;
    void *img_enemy_right2;
    void *coin_power;
}t_imgs;

typedef struct info
{
    t_imgs *image;
    t_wihe *dimensions;
    t_position *position[2];
    t_position *position_o;
    void *mlx;
    void *mlx_new_win;
    char **map;
    char *name_of_map;
    int lenght_of_map;
    int how_many_C;
    int deriction;
    int how_many_O;
    int moves_count;
    bool we_have_exit;
    bool exit_game;
}t_info;

int lenght_of_map(  char *str);
int    ft_len(char *str);
int     ft_print(char   *str, int std);
int	    ft_strcmp(const char *s1, char *s2);
int    free_all_bonus(t_info *all, int msg);
void    display_error(int count_E, int count_C, int count_P);
void    check_elemnts(t_info *all);
void    check_extension(char *str);
void    free_map(char **map);
void    count_hight_width_bonus(t_info *all);
void display_window_bonus(t_info *all);
void free_data_bonus(t_info *all);
void    move_player_bonus(t_info *all);
void free_mlx_bonus(t_info *all);
void the_start_window_bonus(t_info *all);
void  cheak_exit_game_bonus(t_info *all);
void    move_down_bonus(t_info *all);
void    move_up_bonus(t_info *all);
void    move_left_bonus(t_info *all);
int animation_enemy(t_info *all);
void    move_right_bonus(t_info *all);
void    init_data(t_info *all);
int animation_player (t_info *all);
void display_window(t_info *all);
void    allocate_data_bonus(t_info **all, int lenght_of_map);
void    move_player(t_info *all);
void cheak_exit_game(t_info *all);
int animate(t_info *all);
void    check_the_state_of_wall_bonus(t_info *all);
void    check_elemnts_bonus(t_info *all);
void    check_is_rectangular_bonus(t_info *all);
void    submit_data_map_bonus(t_info *all);
void check_errors_of_map_bonus(t_info *all);
void    flood_fill_bonus(t_info *all);
void    allocation_enemy (t_info *all);
void add_enemy(t_info *all , int x, int y, int index);
#endif