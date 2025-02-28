/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper3_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <mfahmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:32:40 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/27 14:41:15 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	cheak_if_null(t_info *all)
{
	if (!all->image->img_floor || !all->image->img_str
		|| !all->image->img_enemy_right1 || !all->image->img_enemy_right2
		|| !all->image->img_enemy_left2 || !all->image->img_enemy_left1
		|| !all->image->img_enemy_up2 || !all->image->img_enemy_up1
		|| !all->image->img_enemy_down2 || !all->image->img_enemy_down1
		|| !all->image->img_coin || !all->image->img_exit_close
		|| !all->image->img_player_down || !all->image->img_floor
		|| !all->image->img_wall || !all->image->img_player_front
		|| !all->image->img_player_left || !all->image->img_player_close
		|| !all->image->img_player_right || !all->image->img_player_back
		|| !all->image->img_player_right_a || !all->image->img_player_left_a
		|| !all->image->img_player_up)
		free_all_bonus(all, 1337);
}

void	cheak_prev_elemnt(t_info *all)
{
	if (all->prev_elemnt_p == EXIT_E)
	{
		all->map[all->position->x][all->position->y] = 'E';
		mlx_put_image_to_window(all->mlx, all->mlx_new_win,
			all->image->img_exit_close, all->position->y * IMG_WIDTH,
			all->position->x * IMG_HEIGHT);
		all->prev_elemnt_p = 1337;
	}
	else
	{
		all->map[all->position->x][all->position->y] = '0';
		mlx_put_image_to_window(all->mlx, all->mlx_new_win,
			all->image->img_floor, all->position->y * IMG_WIDTH,
			all->position->x * IMG_HEIGHT);
	}
}

void	prev_elemnt_enemy(t_info *all, int i)
{
	if (all->prev_elemnt[i] == EXIT_E)
	{
		all->map[all->position_o[i].x][all->position_o[i].y] = 'E';
		mlx_put_image_to_window(all->mlx, all->mlx_new_win,
			all->image->img_exit_close, all->position_o[i].y * IMG_WIDTH,
			all->position_o[i].x * IMG_HEIGHT);
		all->prev_elemnt[i] = 1337;
	}
	else if (all->prev_elemnt[i] == COINS_E)
	{
		all->map[all->position_o[i].x][all->position_o[i].y] = 'C';
		mlx_put_image_to_window(all->mlx, all->mlx_new_win,
			all->image->img_coin, all->position_o[i].y * IMG_WIDTH,
			all->position_o[i].x * IMG_HEIGHT);
		all->prev_elemnt[i] = 1337;
	}
	else
	{
		all->map[all->position_o[i].x][all->position_o[i].y] = '0';
		mlx_put_image_to_window(all->mlx, all->mlx_new_win,
			all->image->img_floor, all->position_o[i].y * IMG_WIDTH,
			all->position_o[i].x * IMG_HEIGHT);
	}
}

int	animate_move(t_info *all)
{
	move_enemy(all);
	animate(all);
	return (0);
}
