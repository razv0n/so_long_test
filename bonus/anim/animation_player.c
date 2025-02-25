/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <mfahmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:04:49 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/25 14:24:13 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int animation_player(t_info *all)
{
    static clock_t prev = 1;
    static int state = 0;
    clock_t now = clock();
    double time_diff;
    
    time_diff = (double)(now - prev) / CLOCKS_PER_SEC;

    if (all->deriction == RIGHT_D)
    {

        if (time_diff >= 0.14)
        {
            if(state % 3 == 1)
                    mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_player_right_a, all->position[PLAYER]->y * IMG_WIDTH , all->position[PLAYER]->x * IMG_HEIGHT);
            else if(state % 3 == 2)
                    mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_player_right, all->position[PLAYER]->y * IMG_WIDTH , all->position[PLAYER]->x * IMG_HEIGHT);
            else if(state % 3 == 0)
                    mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_player_close, all->position[PLAYER]->y * IMG_WIDTH , all->position[PLAYER]->x * IMG_HEIGHT);
            state ++;
            prev = now;  // Reset prev after the 2-second condition
        }
    }
        else if (all->deriction == LEFT_D)
        {
            if (time_diff >= 0.14)
            {
                if(state % 3 == 1)
                    mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_player_left_a, all->position[PLAYER]->y * IMG_WIDTH , all->position[PLAYER]->x * IMG_HEIGHT);
                else if(state % 3 == 2)
                    mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_player_left, all->position[PLAYER]->y * IMG_WIDTH , all->position[PLAYER]->x * IMG_HEIGHT);
                else if(state % 3 == 0)
                    mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_player_close, all->position[PLAYER]->y * IMG_WIDTH , all->position[PLAYER]->x * IMG_HEIGHT);
                state ++;
                prev = now;  // Reset prev after the 2-second condition
            }
        }
        else if (all->deriction == UP_D)
        {
            if (time_diff >= 0.14)
    
             {
                if(state % 3 == 1)
                    mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_player_up, all->position[PLAYER]->y * IMG_WIDTH , all->position[PLAYER]->x * IMG_HEIGHT);
                else if(state % 3 == 2)
                    mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_player_back, all->position[PLAYER]->y * IMG_WIDTH , all->position[PLAYER]->x * IMG_HEIGHT);
                else if(state % 3 == 0)
                    mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_player_close, all->position[PLAYER]->y * IMG_WIDTH , all->position[PLAYER]->x * IMG_HEIGHT);
                state ++;
                prev = now;  // Reset prev after the 2-second condition
            }
        }
        else if (all->deriction == DOWN_D)
        {
            if (time_diff >= 0.14)
            {
                if(state % 3 == 1)
                    mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_player_down, all->position[PLAYER]->y * IMG_WIDTH , all->position[PLAYER]->x * IMG_HEIGHT);
                else if(state % 3 == 2)
                    mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_player_front, all->position[PLAYER]->y * IMG_WIDTH , all->position[PLAYER]->x * IMG_HEIGHT);
                else if(state % 3 == 0)
                    mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_player_close, all->position[PLAYER]->y * IMG_WIDTH , all->position[PLAYER]->x * IMG_HEIGHT);
                state ++;
                prev = now;  // Reset prev after the 2-second condition
            }
        }
 
    return 0;  // Return 0 to keep mlx_loop_hook running
}
int animation_enemy(t_info *all)
{
    static clock_t prev_1 = 0;
    static int state_1 = 0;
    clock_t now = clock();
    double time_diff;
    int i = 0;
    
    time_diff = (double)(now - prev_1) / CLOCKS_PER_SEC;

    if (time_diff >= 0.17)
    {
        while (i < all->how_many_O)
        {
            if (all->direction_o[i] == RIGHT_D)
            {
                if (state_1 % 2 == 0)
                    mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_enemy_right2, all->position_o[i].y  * IMG_WIDTH , all->position_o[i].x * IMG_HEIGHT);
                else
                    mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_enemy_right1, all->position_o[i].y * IMG_WIDTH , all->position_o[i].x * IMG_HEIGHT);
            }
            else if (all->direction_o[i] == LEFT_D)
            {
                  if (state_1 % 2 == 0)
                    mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_enemy_left2, all->position_o[i].y  * IMG_WIDTH , all->position_o[i].x * IMG_HEIGHT);
                else
                    mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_enemy_left1, all->position_o[i].y * IMG_WIDTH , all->position_o[i].x * IMG_HEIGHT);
            }
            else if (all->direction_o[i] == UP_D)
            {
                  if (state_1 % 2 == 0)
                    mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_enemy_up2, all->position_o[i].y  * IMG_WIDTH , all->position_o[i].x * IMG_HEIGHT);
                else
                    mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_enemy_up1, all->position_o[i].y * IMG_WIDTH , all->position_o[i].x * IMG_HEIGHT);
            }
            else
            {
                  if (state_1 % 2 == 0)
                    mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_enemy_down2, all->position_o[i].y  * IMG_WIDTH , all->position_o[i].x * IMG_HEIGHT);
                else
                    mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_enemy_down1, all->position_o[i].y * IMG_WIDTH , all->position_o[i].x * IMG_HEIGHT);
            }
            i++;
        }
        state_1++;
        prev_1 = now;
    }
    return 0;  //? Return 0 to keep mlx_loop_hook running
}

int animate(t_info *all)
{
    animation_player(all);
    animation_enemy(all);
    return 0;
}
