/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_window_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <mfahmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:23:08 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/24 10:10:28 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"
int    free_mlx_start_page_bonus(t_info *all)
{
        mlx_destroy_image(all->mlx, all->image->img_start);
        mlx_destroy_image(all->mlx, all->image->img_start_exit);
        mlx_destroy_window(all->mlx, all->mlx_new_win);
        mlx_destroy_display(all->mlx);
        free(all->mlx);
        free_data_bonus(all);
        exit(1);
}

int     key_bonus(int key, t_info *all)
{
    if (key == ENTER && !all->exit_game)
    {
        mlx_destroy_image(all->mlx, all->image->img_start);
        mlx_destroy_image(all->mlx, all->image->img_start_exit);
        mlx_destroy_window(all->mlx, all->mlx_new_win);
        mlx_loop_end(all->mlx);
    }
    if (key == KEY_up)
    {
        all->exit_game = false;
        mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_start, all->dimensions->width , all->dimensions->height);
    }
    if (key == KEY_down)
    {
        all->exit_game = true;
        mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_start_exit, all->dimensions->width , all->dimensions->height);
    }
    if ((key == ENTER && all->exit_game) || key == ESC)
       free_mlx_start_page_bonus(all);
    return 0;
}

void the_start_window_bonus(t_info *all)
{
    int i , j = 0;
    i = 0;
    all->mlx_new_win = mlx_new_window(all->mlx, 1800, 1000, "so_long");
    all->image->img_start = mlx_xpm_file_to_image(all->mlx, START_XPM, &i, &j);
    all->image->img_start_exit = mlx_xpm_file_to_image(all->mlx, START_EXIT_XPM, &i, &j);
    mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_start, all->dimensions->width , all->dimensions->height);
    mlx_hook(all->mlx_new_win, 2, 1L<<0, key_bonus, all);
    mlx_hook(all->mlx_new_win, 17, 0 ,free_mlx_start_page_bonus, all);
    mlx_loop(all->mlx);
}
