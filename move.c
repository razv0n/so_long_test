/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <mfahmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:47:10 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/13 18:37:32 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void cheak_exit_game(t_info *all)
{
    if (!all->how_many_C)
    {
        free_data(all);
        exit(ft_print("congrate u won\n", 1));
    }
}
void    move_down(t_info *all)
{
    if (all->map[all->position->x + 1][all->position->y] == '1')
        return;
    else if (all->map[all->position->x + 1][all->position->y] == 'C')
        all->how_many_C--;
    else if (all->map[all->position->x + 1][all->position->y] == 'E')
    {
        cheak_exit_game(all);
        all->we_have_exit = true;
    }
    if (all->we_have_exit && all->map[all->position->x + 1][all->position->y] != 'E')
    {
        cheak_exit_game(all);
        all->map[all->position->x][all->position->y] = 'E';
        all->we_have_exit = false;
        mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_exit, all->position->y * IMG_WIDTH , all->position->x * IMG_HEIGHT);
    }
    else
    {
        all->map[all->position->x][all->position->y] = '0';
        mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_floor, all->position->y * IMG_WIDTH , all->position->x * IMG_HEIGHT);
    }
    all->map[++all->position->x][all->position->y] = 'P';
    mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_player_front, all->position->y * IMG_WIDTH , all->position->x * IMG_HEIGHT);
}

void    move_up(t_info *all)
{
    if (all->map[all->position->x - 1][all->position->y] == '1')
        return;
    else if (all->map[all->position->x - 1][all->position->y] == 'C')
        all->how_many_C--;
    else if (all->map[all->position->x - 1][all->position->y] == 'E')
    {
        cheak_exit_game(all);
        all->we_have_exit = true;
    }
    if (all->we_have_exit && all->map[all->position->x - 1][all->position->y] != 'E')
    {
        all->map[all->position->x][all->position->y] = 'E';
        mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_exit, all->position->y * IMG_WIDTH , all->position->x * IMG_HEIGHT);
        all->we_have_exit = false;
    }
    else
    {
        all->map[all->position->x][all->position->y] = '0';
        mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_floor, all->position->y * IMG_WIDTH , all->position->x * IMG_HEIGHT);
    }
    all->map[--all->position->x][all->position->y] = 'P';
    mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_player_back, all->position->y * IMG_WIDTH , all->position->x * IMG_HEIGHT);
}

void    move_left(t_info *all)
{
    if (all->map[all->position->x][all->position->y - 1] == '1')
        return;
    else if (all->map[all->position->x][all->position->y - 1] == 'C')
        all->how_many_C--;
    else if (all->map[all->position->x][all->position->y - 1] == 'E')
    {
        cheak_exit_game(all);
        all->we_have_exit = true;
    }
     if (all->we_have_exit && all->map[all->position->x][all->position->y - 1]!= 'E')
    {
        cheak_exit_game(all);
        all->map[all->position->x][all->position->y] = 'E';
        mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_exit, all->position->y * IMG_WIDTH , all->position->x * IMG_HEIGHT);
        all->we_have_exit = false;
    }
    else
    {
        all->map[all->position->x][all->position->y] = '0';
        mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_floor, all->position->y * IMG_WIDTH , all->position->x * IMG_HEIGHT);
    }
    all->map[all->position->x][--all->position->y] = 'P';
    mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_player_left, all->position->y * IMG_WIDTH , all->position->x * IMG_HEIGHT);
}

void    move_right(t_info *all)
{
    if (all->map[all->position->x][all->position->y + 1] == '1')
        return ;
    else if (all->map[all->position->x][all->position->y + 1] == 'C')
        all->how_many_C--;
    else if (all->map[all->position->x][all->position->y + 1] == 'E')
    {
        cheak_exit_game(all);
        all->we_have_exit = true;
    }
    if (all->we_have_exit && all->map[all->position->x][all->position->y + 1] != 'E')
    {
        cheak_exit_game(all);
        all->map[all->position->x][all->position->y] = 'E';
        mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_exit, all->position->y * IMG_WIDTH , all->position->x * IMG_HEIGHT);
        all->we_have_exit = false;
    }
    else
    {
        all->map[all->position->x][all->position->y] = '0';
        mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_floor, all->position->y * IMG_WIDTH , all->position->x * IMG_HEIGHT);
    }
    all->map[all->position->x][++all->position->y] = 'P';
    mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_player_right, all->position->y * IMG_WIDTH , all->position->x * IMG_HEIGHT);
}

int keycode(int key, t_info *all)
{
    if (key == ESC)
    {
        mlx_destroy_window(all->mlx, all->mlx_new_win);  //? Destroy the window
        mlx_destroy_display(all->mlx);
        // mlx_destroy_image(all->mlx, all->image);
        free(all->mlx);
        free_data(all);
        exit(ft_print("Exit game\n", 2));
    }
    if (key == KEY_w || key == KEY_up)
        move_up(all);
    else if (key == KEY_s || key == KEY_down)
        move_down(all);
    else if (key == KEY_a || key == KEY_left)
        move_left(all);
    else if (key == KEY_d || key == KEY_right)
        move_right(all);
    return (0);
}
void    move_player(t_info *all)
{
    mlx_hook(all->mlx_new_win, 2, 1L<<0, keycode, all);
}