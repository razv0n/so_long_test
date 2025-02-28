/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <mfahmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:23:08 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/26 17:56:52 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	free_mlx_start_page(t_info *all)
{
	mlx_destroy_image(all->mlx, all->image->img_start);
	mlx_destroy_image(all->mlx, all->image->img_start_exit);
	mlx_destroy_window(all->mlx, all->mlx_new_win);
	mlx_destroy_display(all->mlx);
	free(all->mlx);
	free_data(all);
	exit(1);
}

int	key(int key, t_info *all)
{
	if (key == ENTER && !all->exit_game)
	{
		mlx_destroy_image(all->mlx, all->image->img_start);
		mlx_destroy_image(all->mlx, all->image->img_start_exit);
		mlx_destroy_window(all->mlx, all->mlx_new_win);
		mlx_loop_end(all->mlx);
	}
	if (key == KEY_UP)
	{
		all->exit_game = false;
		mlx_put_image_to_window(all->mlx, all->mlx_new_win,
			all->image->img_start, all->dimensions->width,
			all->dimensions->height);
	}
	if (key == KEY_DOWN)
	{
		all->exit_game = true;
		mlx_put_image_to_window(all->mlx, all->mlx_new_win,
			all->image->img_start_exit, all->dimensions->width,
			all->dimensions->height);
	}
	if ((key == ENTER && all->exit_game) || key == ESC)
		free_mlx_start_page(all);
	return (0);
}

void	the_start_window(t_info *all)
{
	int (i), (j) = 0;
	i = 0;
	all->mlx_new_win = mlx_new_window(all->mlx, 1800, 1000, "so_long");
	if (!all->mlx_new_win)
		free_all(all);
	all->image->img_start = mlx_xpm_file_to_image(all->mlx, START_XPM, &i, &j);
	if (!all->image->img_start)
		free_all(all);
	all->image->img_start_exit = mlx_xpm_file_to_image(all->mlx, START_EXIT_XPM,
			&i, &j);
	if (!all->image->img_start_exit)
	{
		mlx_destroy_image(all->mlx, all->image->img_start);
		free_all(all);
	}
	mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_start,
		all->dimensions->width, all->dimensions->height);
	mlx_hook(all->mlx_new_win, 17, 0, free_mlx_start_page, all);
	mlx_hook(all->mlx_new_win, 2, 1L << 0, key, all);
	mlx_loop(all->mlx);
}
