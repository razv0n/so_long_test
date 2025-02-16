/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_window_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <mfahmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:09:50 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/16 22:48:57 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"
#include <time.h>
int animation(t_info *all)
{
    static clock_t prev = 1;
    static int state = 0;
    clock_t now = clock();
    double time_diff;
    
    time_diff = (double)(now - prev) / CLOCKS_PER_SEC;

    if (all->deriction == RIGHT_D)
    {

        if (time_diff >= 0.07)
        {
            if(state % 3 == 1)
                    mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_player_right_a, all->position->y * IMG_WIDTH , all->position->x * IMG_HEIGHT);
            else if(state % 3 == 2)
                    mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_player_right, all->position->y * IMG_WIDTH , all->position->x * IMG_HEIGHT);
            else if(state % 3 == 0)
                    mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_player_close, all->position->y * IMG_WIDTH , all->position->x * IMG_HEIGHT);
            state ++;
            prev = now;  // Reset prev after the 2-second condition
        }
    }
        else if (all->deriction == LEFT_D)
        {
            if (time_diff >= 0.07)
            {
                if(state % 3 == 1)
                    mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_player_left_a, all->position->y * IMG_WIDTH , all->position->x * IMG_HEIGHT);
                else if(state % 3 == 2)
                    mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_player_left, all->position->y * IMG_WIDTH , all->position->x * IMG_HEIGHT);
                else if(state % 3 == 0)
                    mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_player_close, all->position->y * IMG_WIDTH , all->position->x * IMG_HEIGHT);
                state ++;
                prev = now;  // Reset prev after the 2-second condition
            }
        }
        else if (all->deriction == UP_D)
        {
            if (time_diff >= 0.07)
            {
                if(state % 3 == 1)
                    mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_player_up, all->position->y * IMG_WIDTH , all->position->x * IMG_HEIGHT);
                else if(state % 3 == 2)
                    mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_player_back, all->position->y * IMG_WIDTH , all->position->x * IMG_HEIGHT);
                else if(state % 3 == 0)
                    mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_player_close, all->position->y * IMG_WIDTH , all->position->x * IMG_HEIGHT);
                state ++;
                prev = now;  // Reset prev after the 2-second condition
            }
        }
        else if (all->deriction == DOWN_D)
        {
            if (time_diff >= 0.07)
            {
                if(state % 3 == 1)
                    mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_player_down, all->position->y * IMG_WIDTH , all->position->x * IMG_HEIGHT);
                else if(state % 3 == 2)
                    mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_player_front, all->position->y * IMG_WIDTH , all->position->x * IMG_HEIGHT);
                else if(state % 3 == 0)
                    mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_player_close, all->position->y * IMG_WIDTH , all->position->x * IMG_HEIGHT);
                state ++;
                prev = now;  // Reset prev after the 2-second condition
            }
        }
 
    return 0;  // Return 0 to keep mlx_loop_hook running
}


void display_map_bonus(t_info *all)
{
    int j, i = 0;
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
                all->position_exit->x =  i;
                all->position_exit->y =  j;
            }
            else if(all->map[i][j] == 'P')
            {
                all->position->x =  i;
                all->position->y =  j;
                all->deriction = RIGHT_D;
                animation(all);
            }
            j++;
        }
        i++;
    }
}

void display_window_bonus(t_info *all)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    all->mlx = mlx_init();
    the_start_window(all);
    mlx_destroy_display(all->mlx);
    free(all->mlx);
    all->mlx = mlx_init();
    all->mlx_new_win = mlx_new_window(all->mlx, all->dimensions->height * IMG_HEIGHT, all->dimensions->width * IMG_WIDTH, "so_long");
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
    display_map_bonus(all);
    move_player_bonus(all);
    mlx_loop(all->mlx);
}
