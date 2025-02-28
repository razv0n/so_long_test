/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_enemy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <mfahmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:41:07 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/26 16:58:24 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	update_enemy_right(t_info *all, int state_1, int i)
{
	if (state_1 % 2 == 0)
		mlx_put_image_to_window(all->mlx, all->mlx_new_win,
			all->image->img_enemy_right2, all->position_o[i].y * IMG_WIDTH,
			all->position_o[i].x * IMG_HEIGHT);
	else
		mlx_put_image_to_window(all->mlx, all->mlx_new_win,
			all->image->img_enemy_right1, all->position_o[i].y * IMG_WIDTH,
			all->position_o[i].x * IMG_HEIGHT);
}

void	update_enemy_left(t_info *all, int state_1, int i)
{
	if (state_1 % 2 == 0)
		mlx_put_image_to_window(all->mlx, all->mlx_new_win,
			all->image->img_enemy_left2, all->position_o[i].y * IMG_WIDTH,
			all->position_o[i].x * IMG_HEIGHT);
	else
		mlx_put_image_to_window(all->mlx, all->mlx_new_win,
			all->image->img_enemy_left1, all->position_o[i].y * IMG_WIDTH,
			all->position_o[i].x * IMG_HEIGHT);
}

void	update_enemy_up(t_info *all, int state_1, int i)
{
	if (state_1 % 2 == 0)
		mlx_put_image_to_window(all->mlx, all->mlx_new_win,
			all->image->img_enemy_up2, all->position_o[i].y * IMG_WIDTH,
			all->position_o[i].x * IMG_HEIGHT);
	else
		mlx_put_image_to_window(all->mlx, all->mlx_new_win,
			all->image->img_enemy_up1, all->position_o[i].y * IMG_WIDTH,
			all->position_o[i].x * IMG_HEIGHT);
}

void	update_enemy_down(t_info *all, int state_1, int i)
{
	if (state_1 % 2 == 0)
		mlx_put_image_to_window(all->mlx, all->mlx_new_win,
			all->image->img_enemy_down2, all->position_o[i].y * IMG_WIDTH,
			all->position_o[i].x * IMG_HEIGHT);
	else
		mlx_put_image_to_window(all->mlx, all->mlx_new_win,
			all->image->img_enemy_down1, all->position_o[i].y * IMG_WIDTH,
			all->position_o[i].x * IMG_HEIGHT);
}

void	update_enemy(t_info *all, int state_1, int i)
{
	if (all->direction_o[i] == RIGHT_D)
		update_enemy_right(all, state_1, i);
	else if (all->direction_o[i] == LEFT_D)
		update_enemy_left(all, state_1, i);
	else if (all->direction_o[i] == UP_D)
		update_enemy_up(all, state_1, i);
	else if (all->direction_o[i] == DOWN_D)
		update_enemy_down(all, state_1, i);
}
