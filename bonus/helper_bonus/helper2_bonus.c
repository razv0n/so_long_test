/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <mfahmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 21:05:28 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/25 20:56:11 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void    free_mlx_bonus2(t_info *all)
{
    if (all->image->img_enemy_up1)
        mlx_destroy_image(all->mlx, all->image->img_enemy_up1);
    if (all->image->img_enemy_left1)
        mlx_destroy_image(all->mlx, all->image->img_enemy_left1);
    if (all->image->img_enemy_down1)
        mlx_destroy_image(all->mlx, all->image->img_enemy_down1);
    if (all->image->img_enemy_down2)
        mlx_destroy_image(all->mlx, all->image->img_enemy_down2);
    if (all->image->img_enemy_up2)
        mlx_destroy_image(all->mlx, all->image->img_enemy_up2);
    if (all->image->img_enemy_right1)
        mlx_destroy_image(all->mlx, all->image->img_enemy_right1);
    if (all->image->img_enemy_right2)
        mlx_destroy_image(all->mlx, all->image->img_enemy_right2);
    if (all->image->img_enemy_left2)
        mlx_destroy_image(all->mlx, all->image->img_enemy_left2);
    if (all->image->img_floor)
        mlx_destroy_image(all->mlx, all->image->img_floor);
    if (all->image->img_wall)
        mlx_destroy_image(all->mlx, all->image->img_wall);
    if (all->image->img_str)
        mlx_destroy_image(all->mlx, all->image->img_str);
}

void    free_mlx_bonus3(t_info *all)
{
    if (all->image->img_exit_close)
        mlx_destroy_image(all->mlx, all->image->img_exit_close);
    if (all->image->img_coin)
        mlx_destroy_image(all->mlx, all->image->img_coin);
    if (all->mlx_new_win)
        mlx_destroy_window(all->mlx, all->mlx_new_win);
    if (all->mlx)
    {
        mlx_destroy_display(all->mlx);
        free(all->mlx);
    }
}

void init_img(t_info *all)
{
 
    all->image->img_player_front = NULL;
    all->image->img_player_down = NULL;
    all->image->img_player_back = NULL;
    all->image->img_player_left = NULL;
    all->image->img_player_right = NULL;
    all->image->img_player_up = NULL;
    all->image->img_player_right_a = NULL;
    all->image->img_player_left_a = NULL;
    all->image->img_floor = NULL;
    all->image->img_coin = NULL;
    all->image->img_start = NULL;
    all->image->img_player_close = NULL;
    all->image->img_wall = NULL;
    all->image->img_str = NULL;
    all->image->img_exit_close = NULL;
    all->image->img_enemy_down1 = NULL;
    all->image->img_enemy_right1 = NULL;
    all->image->img_enemy_up1 = NULL;
    all->image->img_enemy_left1 = NULL;
    all->image->img_enemy_up2 = NULL;
    all->image->img_enemy_down2 = NULL;
    all->image->img_enemy_left2 = NULL;
    all->image->img_enemy_right2 = NULL;
}
void check_if_state_wall(int i, int j, t_info *all)
{
    if (all->map[i][j] != '1' && all->map[i][j] != '\n')
    {
        free_data_bonus(all);
        exit(ft_print("Error\nstate of wall\n", 2));
    }
}

void add_images_bonus2(t_info *all, int i, int j)
{
    all->image->img_coin = mlx_xpm_file_to_image(all->mlx, COINS_XPM, &i, &j);
	all->image->img_enemy_down1 = mlx_xpm_file_to_image(all->mlx, ENEMY_DOWN_1,
			&i, &j);
	all->image->img_enemy_down2 = mlx_xpm_file_to_image(all->mlx, ENEMY_DOWN_2,
			&i, &j);
	all->image->img_enemy_up1 = mlx_xpm_file_to_image(all->mlx, ENEMY_UP_1, &i,
			&j);
	all->image->img_enemy_up2 = mlx_xpm_file_to_image(all->mlx, ENEMY_UP_2, &i,
			&j);
	all->image->img_enemy_left1 = mlx_xpm_file_to_image(all->mlx, ENEMY_LEFT_1,
			&i, &j);
	all->image->img_enemy_left2 = mlx_xpm_file_to_image(all->mlx, ENEMY_LEFT_2,
			&i, &j);
	all->image->img_enemy_right2 = mlx_xpm_file_to_image(all->mlx,
			ENEMY_RIGHT_2, &i, &j);
	all->image->img_enemy_right1 = mlx_xpm_file_to_image(all->mlx,
			ENEMY_RIGHT_1, &i, &j);
    all->image->img_str = mlx_xpm_file_to_image(all->mlx, STR_WIN, &i, &j);
}
