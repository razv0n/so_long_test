/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <mfahmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:17:22 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/27 14:51:15 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WALL_XPM "assets/sprites/wall.xpm"
# define FLOOR_XPM "assets/sprites/floor.xpm"
# define COINS_XPM "assets/sprites/coin-bag.xpm"
# define PLAYER_FRONT_XPM "assets/sprites/player/semi_front.xpm"
# define PLAYER_LEFT_XPM "assets/sprites/player/semi_left.xpm"
# define PLAYER_RIGHT_XPM "assets/sprites/player/semi_right.xpm"
# define PLAYER_BACK_XPM "assets/sprites/player/semi_back.xpm"
# define OPEN_EXIT_XPM "assets/sprites/open-exit.xpm"
# define EXIT_CLOSED_XPM "assets/sprites/exit-closed.xpm"
# define START_XPM "assets/sprites/start/START_1.xpm"
# define START_EXIT_XPM "assets/sprites/start/EXIT_1.xpm"
# define IMG_HEIGHT 32
# define IMG_WIDTH 32
# define ESC 65307
# define ENTER 65293
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# include "/usr/include/minilibx-linux/mlx.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>

enum			e_elemnt
{
	EXIT_E = 10,
	COINS_E,
};

typedef struct t_x_y
{
	int	x;
	int	y;
}				t_position;

typedef struct width_heigh
{
	int			width;
	int			height;
}				t_wihe;

typedef struct imgs
{
	void		*img_player_front;
	void		*img_player_back;
	void		*img_player_right;
	void		*img_player_left;
	void		*img_floor;
	void		*img_wall;
	void		*img_coin;
	void		*img_exit_close;
	void		*img_start_exit;
	void		*img_start;
}				t_imgs;

typedef struct info
{
	t_imgs		*image;
	t_wihe		*dimensions;
	t_position	*position;
	void		*mlx;
	void		*mlx_new_win;
	char		**map;
	char		*name_of_map;
	int			lenght_of_map;
	int			how_many_c;
	int			moves_count;
	int			prev_elemnt;
	bool		exit_game;
}				t_info;

int				lenght_of_map(char *str);
int				ft_len(char *str);
int				ft_len(char *str);
int				ft_print(char *str, int std);
int				ft_strcmp(const char *s1, char *s2);
int				ft_strcmp(const char *s1, char *s2);
int				free_all(t_info *all);
void			init_data(t_info *all, int lenght_of_map);
void			check_is_rectangular(t_info *all);
void			flood_fill(t_info *all);
void			display_error(int count_E, int count_C, int count_P);
void			check_elemnts(t_info *all);
void			check_error_wall(int i, int j, t_info *all);
void			check_the_state_of_wall(t_info *all);
void			check_extension(char *str);
void			free_map(char **map);
void			count_hight_width(t_info *all);
void			display_window(t_info *all);
void			submit_data_map(t_info *all);
void			free_data(t_info *all);
void			allocate_data(t_info **all, int lenght_of_map);
void			move_player(t_info *all);
void			free_mlx(t_info *all);
void			the_start_window(t_info *all);
void			check_errors_of_map(t_info *all);
void			cheak_exit_game(t_info *all);
void			move_down(t_info *all);
void			move_up(t_info *all);
void			add_player_m(t_info *all, int i, int j);
void			move_left(t_info *all);
void			move_right(t_info *all);
void			prev_elemnt_m(t_info *all);
#endif
