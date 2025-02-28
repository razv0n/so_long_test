/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <mfahmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:43:17 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/27 14:36:24 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	update_player_right(t_info *all, int state)
{
	if (state % 3 == 1)
		mlx_put_image_to_window(all->mlx, all->mlx_new_win,
			all->image->img_player_right_a, all->position->y
			* IMG_WIDTH, all->position->x * IMG_HEIGHT);
	else if (state % 3 == 2)
		mlx_put_image_to_window(all->mlx, all->mlx_new_win,
			all->image->img_player_right, all->position->y * IMG_WIDTH,
			all->position->x * IMG_HEIGHT);
	else if (state % 3 == 0)
		mlx_put_image_to_window(all->mlx, all->mlx_new_win,
			all->image->img_player_close, all->position->y * IMG_WIDTH,
			all->position->x * IMG_HEIGHT);
}

void	update_player_left(t_info *all, int state)
{
	if (state % 3 == 1)
		mlx_put_image_to_window(all->mlx, all->mlx_new_win,
			all->image->img_player_left_a, all->position->y * IMG_WIDTH,
			all->position->x * IMG_HEIGHT);
	else if (state % 3 == 2)
		mlx_put_image_to_window(all->mlx, all->mlx_new_win,
			all->image->img_player_left, all->position->y * IMG_WIDTH,
			all->position->x * IMG_HEIGHT);
	else if (state % 3 == 0)
		mlx_put_image_to_window(all->mlx, all->mlx_new_win,
			all->image->img_player_close, all->position->y * IMG_WIDTH,
			all->position->x * IMG_HEIGHT);
}

void	update_player(t_info *all, int state)
{
	if (all->deriction == RIGHT_D)
		update_player_right(all, state);
	else if (all->deriction == LEFT_D)
		update_player_left(all, state);
}

void	update_player_up(t_info *all, int state)
{
	if (state % 3 == 1)
		mlx_put_image_to_window(all->mlx, all->mlx_new_win,
			all->image->img_player_up, all->position->y * IMG_WIDTH,
			all->position->x * IMG_HEIGHT);
	else if (state % 3 == 2)
		mlx_put_image_to_window(all->mlx, all->mlx_new_win,
			all->image->img_player_back, all->position->y * IMG_WIDTH,
			all->position->x * IMG_HEIGHT);
	else if (state % 3 == 0)
		mlx_put_image_to_window(all->mlx, all->mlx_new_win,
			all->image->img_player_close, all->position->y * IMG_WIDTH,
			all->position->x * IMG_HEIGHT);
}

void	update_player_down(t_info *all, int state)
{
	if (state % 3 == 1)
		mlx_put_image_to_window(all->mlx, all->mlx_new_win,
			all->image->img_player_down, all->position->y * IMG_WIDTH,
			all->position->x * IMG_HEIGHT);
	else if (state % 3 == 2)
		mlx_put_image_to_window(all->mlx, all->mlx_new_win,
			all->image->img_player_front, all->position->y * IMG_WIDTH,
			all->position->x * IMG_HEIGHT);
	else if (state % 3 == 0)
		mlx_put_image_to_window(all->mlx, all->mlx_new_win,
			all->image->img_player_close, all->position->y * IMG_WIDTH,
			all->position->x * IMG_HEIGHT);
}
