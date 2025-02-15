/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <mfahmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:47:10 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/15 18:38:40 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void cheak_exit_game(t_info *all)
{
    if (!all->how_many_C)
    {
        ft_printf("move : %d\n", ++all->moves_count);
        free_mlx(all);
        free_data(all);
        exit(ft_print("congrate u won\n", 1));
    }
}

int keycode(int key, t_info *all)
{
    if (key == ESC)
        free_all(all);
    else if (key == KEY_w || key == KEY_up)
        move_up(all);
    else if (key == KEY_s || key == KEY_down)
        move_down(all);
    else if (key == KEY_a || key == KEY_left)
        move_left(all);
    else if (key == KEY_d || key == KEY_right)
        move_right(all);
    if (!all->how_many_C)
        mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_exit_open, all->position_exit->y * IMG_WIDTH , all->position_exit->x * IMG_HEIGHT);
    return (0);
}
void    move_player(t_info *all)
{
    mlx_hook(all->mlx_new_win, 2, 1L<<0, keycode, all);
    mlx_hook(all->mlx_new_win, 17, 0 ,free_all, all);
}