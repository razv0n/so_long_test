/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <mfahmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:22:11 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/22 18:47:05 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void    move_down_bonus(t_info *all)
{
    if (all->map[all->position[PLAYER]->x + 1][all->position[PLAYER]->y] == '1')
        return;
    else if (all->map[all->position[PLAYER]->x + 1][all->position[PLAYER]->y] == 'C')
        all->how_many_C--;
    else if (all->map[all->position[PLAYER]->x + 1][all->position[PLAYER]->y] == 'O')
        free_all_bonus(all, LOSE_GAME);
    else if (all->map[all->position[PLAYER]->x + 1][all->position[PLAYER]->y] == 'E')
    {
        cheak_exit_game_bonus(all);
        all->we_have_exit = true;
    }
    if (all->we_have_exit && all->map[all->position[PLAYER]->x + 1][all->position[PLAYER]->y] != 'E')
    {
        all->map[all->position[PLAYER]->x][all->position[PLAYER]->y] = 'E';
        all->we_have_exit = false;
        mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_exit_close, all->position[PLAYER]->y * IMG_WIDTH , all->position[PLAYER]->x * IMG_HEIGHT);
    }
    else
    {
        all->map[all->position[PLAYER]->x][all->position[PLAYER]->y] = '0';
        mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_floor, all->position[PLAYER]->y * IMG_WIDTH , all->position[PLAYER]->x * IMG_HEIGHT);
    }
    all->map[++all->position[PLAYER]->x][all->position[PLAYER]->y] = 'P';
    str_window(all);
}

void    move_up_bonus(t_info *all)
{
    if (all->map[all->position[PLAYER]->x - 1][all->position[PLAYER]->y] == '1')
        return;
    else if (all->map[all->position[PLAYER]->x - 1][all->position[PLAYER]->y] == 'C')
        all->how_many_C--;
    else if (all->map[all->position[PLAYER]->x - 1][all->position[PLAYER]->y] == 'O')
        free_all_bonus(all, LOSE_GAME);
    else if (all->map[all->position[PLAYER]->x - 1][all->position[PLAYER]->y] == 'E')
    {
        cheak_exit_game_bonus(all);
        all->we_have_exit = true;
    }
    if (all->we_have_exit && all->map[all->position[PLAYER]->x - 1][all->position[PLAYER]->y] != 'E')
    {
        all->map[all->position[PLAYER]->x][all->position[PLAYER]->y] = 'E';
        mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_exit_close, all->position[PLAYER]->y * IMG_WIDTH , all->position[PLAYER]->x * IMG_HEIGHT);
        all->we_have_exit = false;
    }
    else
    {
        all->map[all->position[PLAYER]->x][all->position[PLAYER]->y] = '0';
        mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_floor, all->position[PLAYER]->y * IMG_WIDTH , all->position[PLAYER]->x * IMG_HEIGHT);
    }
    all->map[--all->position[PLAYER]->x][all->position[PLAYER]->y] = 'P';
    str_window(all);
}

void    move_left_bonus(t_info *all)
{
    if (all->map[all->position[PLAYER]->x][all->position[PLAYER]->y - 1] == '1')
        return;
    else if (all->map[all->position[PLAYER]->x][all->position[PLAYER]->y - 1] == 'C')
        all->how_many_C--;
    else if (all->map[all->position[PLAYER]->x][all->position[PLAYER]->y - 1] == 'O')
        free_all_bonus(all, LOSE_GAME);
    else if (all->map[all->position[PLAYER]->x][all->position[PLAYER]->y - 1] == 'E')
    {
        cheak_exit_game_bonus(all);
        all->we_have_exit = true;
    }
     if (all->we_have_exit && all->map[all->position[PLAYER]->x][all->position[PLAYER]->y - 1]!= 'E')
    {
        all->map[all->position[PLAYER]->x][all->position[PLAYER]->y] = 'E';
        mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_exit_close, all->position[PLAYER]->y * IMG_WIDTH , all->position[PLAYER]->x * IMG_HEIGHT);
        all->we_have_exit = false;
    }
    else
    {
        all->map[all->position[PLAYER]->x][all->position[PLAYER]->y] = '0';
        mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_floor, all->position[PLAYER]->y * IMG_WIDTH , all->position[PLAYER]->x * IMG_HEIGHT);
    }
    all->map[all->position[PLAYER]->x][--all->position[PLAYER]->y] = 'P';
    str_window(all);
}

void    move_right_bonus(t_info *all)
{
    if (all->map[all->position[PLAYER]->x][all->position[PLAYER]->y + 1] == '1')
        return ;
    else if (all->map[all->position[PLAYER]->x][all->position[PLAYER]->y + 1] == 'C')
        all->how_many_C--;
    else if (all->map[all->position[PLAYER]->x][all->position[PLAYER]->y + 1] == 'O')
        free_all_bonus(all, LOSE_GAME);
    else if (all->map[all->position[PLAYER]->x][all->position[PLAYER]->y + 1] == 'E')
    {
        cheak_exit_game_bonus(all);
        all->we_have_exit = true;
    }
    if (all->we_have_exit && all->map[all->position[PLAYER]->x][all->position[PLAYER]->y + 1] != 'E')
    {
        all->map[all->position[PLAYER]->x][all->position[PLAYER]->y] = 'E';
        mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_exit_close, all->position[PLAYER]->y * IMG_WIDTH , all->position[PLAYER]->x * IMG_HEIGHT);
        all->we_have_exit = false;
    }
    else
    {
        all->map[all->position[PLAYER]->x][all->position[PLAYER]->y] = '0';
        mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_floor, all->position[PLAYER]->y * IMG_WIDTH , all->position[PLAYER]->x * IMG_HEIGHT);
    }
    all->map[all->position[PLAYER]->x][++all->position[PLAYER]->y] = 'P';
    str_window(all);
}
