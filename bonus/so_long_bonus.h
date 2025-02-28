/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <mfahmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:51:57 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/27 16:08:12 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define WALL_XPM "assets/sprites/wall.xpm"
# define FLOOR_XPM "assets/sprites/floor.xpm"
# define COINS_XPM "assets/sprites/coin-bag.xpm"
# define PLAYER_FRONT_XPM "assets/sprites/player/semi_front.xpm"
# define PLAYER_LEFT_XPM "assets/sprites/player/semi_left.xpm"
# define PLAYER_RIGHT_XPM "assets/sprites/player/semi_right.xpm"
# define PLAYER_BACK_XPM "assets/sprites/player/semi_back.xpm"
# define PLAYER_UP_XPM "assets/sprites/player/up.xpm"
# define PLAYER_DOWN_XPM "assets/sprites/player/down.xpm"
# define PLAYER_RIGHT_ALL "assets/sprites/player/right.xpm"
# define PLAYER_LEFT_ALL "assets/sprites/player/left.xpm"
# define PLAYER_CLOSE_XPM "assets/sprites/player/close.xpm"
# define EXIT_CLOSED_XPM "assets/sprites/exit-closed.xpm"
# define START_XPM "assets/sprites/start/START_1.xpm"
# define START_EXIT_XPM "assets/sprites/start/EXIT_1.xpm"

# define ENEMY_DOWN_1 "assets/sprites/enemy/B/en_down1.xpm"
# define ENEMY_DOWN_2 "assets/sprites/enemy/B/en_down2.xpm"
# define ENEMY_UP_1 "assets/sprites/enemy/B/en_up1.xpm"
# define ENEMY_UP_2 "assets/sprites/enemy/B/en_up2.xpm"
# define ENEMY_LEFT_1 "assets/sprites/enemy/B/en_left1.xpm"
# define ENEMY_LEFT_2 "assets/sprites/enemy/B/en_left2.xpm"
# define ENEMY_RIGHT_1 "assets/sprites/enemy/B/en_right1.xpm"
# define ENEMY_RIGHT_2 "assets/sprites/enemy/B/en_right2.xpm"
# define STR_WIN "assets/sprites/str.xpm"

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

# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "/usr/include/minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# include <time.h>

enum			e_direction
{
	UP_D = 1,
	DOWN_D,
	LEFT_D,
	RIGHT_D,
};

enum			e_msg
{
	EXIT_GAME,
	WIN_GAME,
	LOSE_GAME,
};
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
	void		*img_player_right_a;
	void		*img_player_left_a;
	void		*img_player_up;
	void		*img_player_down;
	void		*img_player_close;
	void		*img_floor;
	void		*img_wall;
	void		*img_coin;
	void		*img_exit;
	void		*img_start;
	void		*img_start_exit;
	void		*img_exit_close;
	void		*img_enemy_down1;
	void		*img_enemy_down2;
	void		*img_enemy_up1;
	void		*img_enemy_up2;
	void		*img_enemy_left1;
	void		*img_enemy_left2;
	void		*img_enemy_right1;
	void		*img_enemy_right2;
	void		*img_str;
}				t_imgs;

typedef struct info
{
	t_imgs		*image;
	t_wihe		*dimensions;
	t_position	*position;
	t_position	*position_o;
	void		*mlx;
	void		*mlx_new_win;
	char		**map;
	char		*name_of_map;
	int			lenght_of_map;
	int			how_many_c;
	int			deriction;
	int			*direction_o;
	int			how_many_o;
	int			moves_count;
	int			prev_elemnt_p;
	int			*prev_elemnt;
	bool		we_have_exit;
	bool		exit_game;
}				t_info;

int				lenght_of_map(char *str);
int				ft_len(char *str);
int				ft_print(char *str, int std);
int				ft_strcmp(const char *s1, char *s2);
int				free_all_bonus(t_info *all, int msg);
int				move_enemy(t_info *all);
int				animate(t_info *all);
int				animate_move(t_info *all);
char			*ft_itoa(int nm);
void			display_error(int count_E, int count_C, int count_P);
void			check_elemnts(t_info *all);
void			check_extension(char *str);
void			str_window(t_info *all);
void			free_map(char **map);
void			count_hight_width_bonus(t_info *all);
void			display_window_bonus(t_info *all);
void			free_data_bonus(t_info *all);
void			move_player_bonus(t_info *all);
void			free_mlx_bonus(t_info *all);
void			the_start_window_bonus(t_info *all);
void			cheak_exit_game_bonus(t_info *all);
void			move_down_bonus(t_info *all);
void			move_up_bonus(t_info *all);
void			init_data_bonus(t_info *all);
void			move_left_bonus(t_info *all);
void			move_right_bonus(t_info *all);
void			display_window(t_info *all);
void			allocate_data_bonus(t_info **all, int lenght_of_map);
void			check_the_state_of_wall_bonus(t_info *all);
void			check_elemnts_bonus(t_info *all);
void			check_is_rectangular_bonus(t_info *all);
void			submit_data_map_bonus(t_info *all);
void			check_errors_of_map_bonus(t_info *all);
void			flood_fill_bonus(t_info *all);
void			allocation_enemy(t_info *all);
void			add_enemy(t_info *all, int x, int y, int index);
void			free_mlx_bonus2(t_info *all);
void			free_mlx_bonus3(t_info *all);
void			init_img(t_info *all);
void			cheak_prev_elemnt(t_info *all);
void			check_if_state_wall(int i, int j, t_info *all);
void			add_exit(t_info *all, int i, int j);
void			add_player(t_info *all, int i, int j);
void			cheak_if_null(t_info *all);
void			add_images_bonus2(t_info *all, int i, int j);
void			update_enemy(t_info *all, int state_1, int i);
void			update_player_up(t_info *all, int state);
void			update_player_down(t_info *all, int state);
void			update_player(t_info *all, int state);
void			prev_elemnt_enemy(t_info *all, int i);
#endif