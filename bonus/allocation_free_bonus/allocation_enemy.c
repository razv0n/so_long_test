/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_enemy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <mfahmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:36:41 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/25 18:55:01 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"


void    allocation_enemy (t_info *all)
{
    if (all->how_many_O > 0)
    {
        all->position_o = malloc(sizeof(t_position) * all->how_many_O);
        if (!all->position_o)
            free_all_bonus(all, 1337);
        all->direction_o = ft_calloc (sizeof(t_position), all->how_many_O);
        if (!all->position_o)
            free_all_bonus(all, 1337);
        all->prev_elemnt = ft_calloc (sizeof(t_position), all->how_many_O);
        if (!all->prev_elemnt)
            free_all_bonus(all, 1337);
    }
}

void add_enemy(t_info *all , int x, int y, int index)
{
    all->position_o[index].x = x;
    all->position_o[index].y = y;
}
void add_player(t_info *all, int i, int j)
{
    all->position[PLAYER]->x =  i;
    all->position[PLAYER]->y =  j;
    mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_player_close, j * IMG_WIDTH , i * IMG_HEIGHT);
}
void add_exit(t_info *all, int i, int j)
{
    mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_exit_close, j * IMG_WIDTH , i * IMG_HEIGHT);
    all->position[EXIT]->x =  i;
    all->position[EXIT]->y =  j;
}