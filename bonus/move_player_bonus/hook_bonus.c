/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <mfahmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:47:10 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/22 19:00:49 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void cheak_exit_game_bonus(t_info *all)
{
    if (!all->how_many_C)
        free_all_bonus(all, WIN_GAME);
}

int keycod(int key, t_info *all)
{
    if (key == ESC)
        free_all_bonus(all, EXIT_GAME);
    else if (key == KEY_w || key == KEY_up)
    {
        all->deriction = UP_D;
        move_up_bonus(all);
    }
    else if (key == KEY_s || key == KEY_down)
    {
        all->deriction = DOWN_D;
        move_down_bonus(all);
    }
    else if (key == KEY_a || key == KEY_left)
    {
        all->deriction = LEFT_D;
        move_left_bonus(all);
    }
    else if (key == KEY_d || key == KEY_right)
    {
        all->deriction = RIGHT_D;
        move_right_bonus(all);
    }
    return (0);
}
void    move_player_bonus(t_info *all)
{
    mlx_hook(all->mlx_new_win, 2, 1L<<0, keycod, all);
    mlx_loop_hook(all->mlx, animate_move, all);
    mlx_hook(all->mlx_new_win, 17, 0 ,free_all_bonus, all);
}