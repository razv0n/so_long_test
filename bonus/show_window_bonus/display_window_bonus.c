/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_window_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +\       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:09:50 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/17 14:59:05 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"
void    add_images_bonus(t_info *all)
{
    int i, j;
    i = j = 32;
    all->image->img_floor = mlx_xpm_file_to_image(all->mlx, FLOOR_XPM, &i, &j);
    all->image->img_wall = mlx_xpm_file_to_image(all->mlx, WALL_XPM, &i, &j);
    all->image->img_player_front = mlx_xpm_file_to_image(all->mlx, PLAYER_FRONT_XPM,  &i, &j);
    all->image->img_player_left = mlx_xpm_file_to_image(all->mlx, PLAYER_LEFT_XPM,  &i, &j);
    all->image->img_player_close = mlx_xpm_file_to_image(all->mlx, PLAYER_CLOSE_XPM,  &i, &j);
    all->image->img_player_right = mlx_xpm_file_to_image(all->mlx, PLAYER_RIGHT_XPM,  &i, &j);
    all->image->img_player_back = mlx_xpm_file_to_image(all->mlx, PLAYER_BACK_XPM,  &i, &j);
    all->image->img_player_right_a = mlx_xpm_file_to_image(all->mlx, PLAYER_RIGHT_ALL,  &i, &j);
    all->image->img_player_left_a = mlx_xpm_file_to_image(all->mlx, PLAYER_LEFT_ALL,  &i, &j);
    all->image->img_player_up = mlx_xpm_file_to_image(all->mlx, PLAYER_UP_XPM,  &i, &j);
    all->image->img_player_down = mlx_xpm_file_to_image(all->mlx, PLAYER_DOWN_XPM,  &i, &j);
    all->image->img_exit_close = mlx_xpm_file_to_image(all->mlx, EXIT_CLOSED_XPM, &i, &j);
    all->image->img_exit_open = mlx_xpm_file_to_image(all->mlx, OPEN_EXIT_XPM, &i, &j);
    all->image->img_coin = mlx_xpm_file_to_image(all->mlx, COINS_XPM, &i, &j);
    all->image->img_enemy_down1 = mlx_xpm_file_to_image(all->mlx, ENEMY_DOWN_1, &i, &j);
    all->image->img_enemy_down2 = mlx_xpm_file_to_image(all->mlx, ENEMY_DOWN_2, &i, &j);
    all->image->img_enemy_up1 = mlx_xpm_file_to_image(all->mlx, ENEMY_UP_1, &i, &j);
    all->image->img_enemy_up2 = mlx_xpm_file_to_image(all->mlx, ENEMY_UP_2, &i, &j);
    all->image->img_enemy_left1 = mlx_xpm_file_to_image(all->mlx, ENEMY_LEFT_1, &i, &j);
    all->image->img_enemy_left2 = mlx_xpm_file_to_image(all->mlx, ENEMY_LEFT_2, &i, &j);
    all->image->img_enemy_right2 = mlx_xpm_file_to_image(all->mlx, ENEMY_RIGHT_2, &i, &j);
    all->image->img_enemy_right1 = mlx_xpm_file_to_image(all->mlx, ENEMY_RIGHT_1, &i, &j);
    all->image->img_str = mlx_xpm_file_to_image(all->mlx, STR_WIN, &i, &j);
}

void display_map_bonus(t_info *all)
{
    int j, index_enemy, i = 0;
    index_enemy = 0;
    while (all->map[i])
    {
        j = 0;
        while (all->map[i][j])
        {
            if(all->map[i][j] == '0')
                mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_floor, j * IMG_WIDTH , i * IMG_HEIGHT);
            else if(all->map[i][j] == '1')
                mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_wall, j * IMG_WIDTH , i * IMG_HEIGHT);
            else if(all->map[i][j] == 'C')
                    mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_coin, j * IMG_WIDTH , i * IMG_HEIGHT);
            else if(all->map[i][j] == 'E')
            {
                mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_exit_close, j * IMG_WIDTH , i * IMG_HEIGHT);
                all->position[EXIT]->x =  i;
                all->position[EXIT]->y =  j;
            }
            else if(all->map[i][j] == 'P')
            {
                all->position[PLAYER]->x =  i;
                all->position[PLAYER]->y =  j;
                all->deriction = RIGHT_D;
            }
            else if (all->map[i][j] == 'O')
            {
                all->position_o[index_enemy].x = i;
                all->position_o[index_enemy].y = j;
                index_enemy++;
            }
            j++;
        }
        i++;
    }
}

void display_window_bonus(t_info *all)
{
    all->mlx = mlx_init();
    the_start_window_bonus(all);
    mlx_destroy_display(all->mlx);
    free(all->mlx);
    all->mlx = mlx_init();
    all->mlx_new_win = mlx_new_window(all->mlx, all->dimensions->height * IMG_HEIGHT, all->dimensions->width * IMG_WIDTH, "so_long");
    add_images_bonus(all);
    display_map_bonus(all);
    move_player_bonus(all);
    mlx_loop(all->mlx);
}
