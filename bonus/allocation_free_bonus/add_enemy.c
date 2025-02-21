/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_enemy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <mfahmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:36:41 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/21 16:41:07 by mfahmi           ###   ########.fr       */
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
    }
}

void add_enemy(t_info *all , int x, int y, int index)
{   
    all->position_o[index].x = x;
    all->position_o[index].y = y;
}