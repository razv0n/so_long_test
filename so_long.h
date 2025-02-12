#ifndef SO_LONG_H
#define SO_LONG_H



# define WALL_XPM			"assets/sprites/wall.xpm"
# define FLOOR_XPM			"assets/sprites/floor.xpm"
# define COINS_XPM			"assets/sprites/coin-bag.xpm"
# define PLAYER_FRONT_XPM	"assets/sprites/player/front.xpm"
# define PLAYER_LEFT_XPM	"assets/sprites/player/left.xpm"
# define PLAYER_RIGHT_XPM	"assets/sprites/player/right.xpm"
# define PLAYER_BACK_XPM	"assets/sprites/player/back.xpm"
# define OPEN_EXIT_XPM		"assets/sprites/open-exit.xpm"
# define EXIT_CLOSED_XPM	"assets/sprites/exit-closed.xpm"
# define IMG_HEIGHT			32
# define IMG_WIDTH			32
// #include "mlx.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <math.h>
#include "/usr/include/minilibx-linux/mlx.h"
#include <stdio.h>

enum e_free_what_u_want
{
    free_the_position,
    free_the_map,
    free_the_wihe,
    free_the_img,
    free_all_data,
    free_t_info,
};

typedef struct t_x_y
{
    int x;
    int y;
}t_position;

typedef struct width_heigh
{
    int width;
    int height;
}t_wihe;

typedef struct imgs
{
    void *img_player;
    void *img_floor;
    void *img_wall;
    void *img_coin; 
    void *img_exit;
}t_imgs;

typedef struct info
{
    t_imgs *image;
    t_wihe *dimensions;
    t_position *position;
    void *mlx;
    void *mlx_new_win;
    char **map;
    int lenght_of_map;
    char *name_of_map;
}t_info;

int lenght_of_map(char *str);
void    check_is_rectangular(t_info *all);
void    flood_fill(t_info *all);
int     ft_print(char   *str, int std);
int      ft_len(char *str);
void    display_error(int count_E, int count_C, int count_P);
void    check_elemnts(t_info *all);
void    check_the_state_of_wall(t_info *all);
void    check_extension(char **str);
int	    ft_strcmp(const char *s1, char *s2);
void    free_map(char **map);
int	        ft_strcmp(const char *s1, char *s2);
int    ft_len(char *str);
void    count_hight_width(t_info *all);
void display_window(t_info *all);
void    submit_data_mapp(t_info *all);
void free_data(t_info *all);
void    allocate_data(t_info **all, int lenght_of_map);
#endif