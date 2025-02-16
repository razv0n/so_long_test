/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <mfahmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:22:11 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/16 18:37:40 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void    move_down_bonus(t_info *all)
{
    if (all->map[all->position->x + 1][all->position->y] == '1')
        return;
    else if (all->map[all->position->x + 1][all->position->y] == 'C')
        all->how_many_C--;
    else if (all->map[all->position->x + 1][all->position->y] == 'E')
    {
        cheak_exit_game_bonus(all);
        all->we_have_exit = true;
    }
    if (all->we_have_exit && all->map[all->position->x + 1][all->position->y] != 'E')
    {
        all->map[all->position->x][all->position->y] = 'E';
        all->we_have_exit = false;
        mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_exit_close, all->position->y * IMG_WIDTH , all->position->x * IMG_HEIGHT);
    }
    else
    {
        all->map[all->position->x][all->position->y] = '0';
        mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_floor, all->position->y * IMG_WIDTH , all->position->x * IMG_HEIGHT);
    }
    all->map[++all->position->x][all->position->y] = 'P';
    mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_player_close,  all->position->y * IMG_WIDTH , all->position->x * IMG_HEIGHT);
    mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_player_front, all->position->y * IMG_WIDTH , all->position->x * IMG_HEIGHT);
    ft_printf("move : %d\n", ++all->moves_count);
}

void    move_up_bonus(t_info *all)
{
    if (all->map[all->position->x - 1][all->position->y] == '1')
        return;
    else if (all->map[all->position->x - 1][all->position->y] == 'C')
        all->how_many_C--;
    else if (all->map[all->position->x - 1][all->position->y] == 'E')
    {
        cheak_exit_game_bonus(all);
        all->we_have_exit = true;
    }
    if (all->we_have_exit && all->map[all->position->x - 1][all->position->y] != 'E')
    {
        all->map[all->position->x][all->position->y] = 'E';
        mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_exit_close, all->position->y * IMG_WIDTH , all->position->x * IMG_HEIGHT);
        all->we_have_exit = false;
    }
    else
    {
        all->map[all->position->x][all->position->y] = '0';
        mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_floor, all->position->y * IMG_WIDTH , all->position->x * IMG_HEIGHT);
    }
    all->map[--all->position->x][all->position->y] = 'P';
    mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_player_close,  all->position->y * IMG_WIDTH , all->position->x * IMG_HEIGHT);
    mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_player_back, all->position->y * IMG_WIDTH , all->position->x * IMG_HEIGHT);
    ft_printf("move : %d\n", ++all->moves_count);
}

void    move_left_bonus(t_info *all)
{
    if (all->map[all->position->x][all->position->y - 1] == '1')
        return;
    else if (all->map[all->position->x][all->position->y - 1] == 'C')
        all->how_many_C--;
    else if (all->map[all->position->x][all->position->y - 1] == 'E')
    {
        cheak_exit_game_bonus(all);
        all->we_have_exit = true;
    }
     if (all->we_have_exit && all->map[all->position->x][all->position->y - 1]!= 'E')
    {
        all->map[all->position->x][all->position->y] = 'E';
        mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_exit_close, all->position->y * IMG_WIDTH , all->position->x * IMG_HEIGHT);
        all->we_have_exit = false;
    }
    else
    {
        all->map[all->position->x][all->position->y] = '0';
        mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_floor, all->position->y * IMG_WIDTH , all->position->x * IMG_HEIGHT);
    }
    all->map[all->position->x][--all->position->y] = 'P';
    mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_player_close,  all->position->y * IMG_WIDTH , all->position->x * IMG_HEIGHT);
    mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_player_left, all->position->y * IMG_WIDTH , all->position->x * IMG_HEIGHT);
    ft_printf("move : %d\n", ++all->moves_count);
}

void    move_right_bonus(t_info *all)
{
    if (all->map[all->position->x][all->position->y + 1] == '1')
        return ;
    else if (all->map[all->position->x][all->position->y + 1] == 'C')
        all->how_many_C--;
    else if (all->map[all->position->x][all->position->y + 1] == 'E')
    {
        cheak_exit_game_bonus(all);
        all->we_have_exit = true;
    }
    if (all->we_have_exit && all->map[all->position->x][all->position->y + 1] != 'E')
    {
        all->map[all->position->x][all->position->y] = 'E';
        mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_exit_close, all->position->y * IMG_WIDTH , all->position->x * IMG_HEIGHT);
        all->we_have_exit = false;
    }
    else
    {
        all->map[all->position->x][all->position->y] = '0';
        mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_floor, all->position->y * IMG_WIDTH , all->position->x * IMG_HEIGHT);
    }
    all->map[all->position->x][++all->position->y] = 'P';
    mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_player_close,  all->position->y * IMG_WIDTH , all->position->x * IMG_HEIGHT);
    mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_player_right, all->position->y * IMG_WIDTH , all->position->x * IMG_HEIGHT);
    ft_printf("move : %d\n", ++all->moves_count);
}
