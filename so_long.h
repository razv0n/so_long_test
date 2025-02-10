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

// #include "mlx.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <math.h>
#include "/usr/include/minilibx-linux/mlx.h"
#include <stdio.h>

typedef struct t_x_y
{
    int x;
    int y;
}t_position;

typedef struct width_heigh
{
    int img_width;
    int img_height;
}t_wihe;
int lenght_of_map(char *str);
void    check_is_rectangular(char **map);
void    flood_fill(char **map);
int     ft_print(char   *str, int std);
int      ft_len(char *str);
void    display_error(int count_E, int count_C, int count_P);
void    check_elemnts(char **map);
void    check_the_state_of_wall(char **map, char *str);
void    check_extension(char **str);
int	    ft_strcmp(const char *s1, char *s2);
void    free_map(char **map);
int	        ft_strcmp(const char *s1, char *s2);
int    ft_len(char *str);



#endif