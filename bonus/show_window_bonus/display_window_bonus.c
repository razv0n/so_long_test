/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_window_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+\       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:09:50 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/17 14:59:05 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	add_images_bonus(t_info *all, int i, int j)
{
	all->image->img_floor = mlx_xpm_file_to_image(all->mlx, FLOOR_XPM, &i, &j);
	all->image->img_wall = mlx_xpm_file_to_image(all->mlx, WALL_XPM, &i, &j);
	all->image->img_player_front = mlx_xpm_file_to_image(all->mlx,
			PLAYER_FRONT_XPM, &i, &j);
	all->image->img_player_left = mlx_xpm_file_to_image(all->mlx,
			PLAYER_LEFT_XPM, &i, &j);
	all->image->img_player_close = mlx_xpm_file_to_image(all->mlx,
			PLAYER_CLOSE_XPM, &i, &j);
	all->image->img_player_right = mlx_xpm_file_to_image(all->mlx,
			PLAYER_RIGHT_XPM, &i, &j);
	all->image->img_player_back = mlx_xpm_file_to_image(all->mlx,
			PLAYER_BACK_XPM, &i, &j);
all->image->img_player_right_a = mlx_xpm_file_to_image(all->mlx,
			PLAYER_RIGHT_ALL, &i, &j);
	all->image->img_player_left_a = mlx_xpm_file_to_image(all->mlx,
			PLAYER_LEFT_ALL, &i, &j);
	all->image->img_player_up = mlx_xpm_file_to_image(all->mlx, PLAYER_UP_XPM,
			&i, &j);
	all->image->img_player_down = mlx_xpm_file_to_image(all->mlx,
			PLAYER_DOWN_XPM, &i, &j);
	all->image->img_exit_close = mlx_xpm_file_to_image(all->mlx, EXIT_CLOSED_XPM,
			&i, &j);
	add_images_bonus2(all, i, j);
    cheak_if_null(all);
}

void	display_map_bonus(t_info *all)
{
	int j, index_enemy, i = 0;
	index_enemy = 0;
	while (all->map[i])
	{
		j = 0;
		while (all->map[i][j])
		{
			if (all->map[i][j] == '0')
				mlx_put_image_to_window(all->mlx, all->mlx_new_win,
					all->image->img_floor, j * IMG_WIDTH, i * IMG_HEIGHT);
			else if (all->map[i][j] == '1')
				mlx_put_image_to_window(all->mlx, all->mlx_new_win,
					all->image->img_wall, j * IMG_WIDTH, i * IMG_HEIGHT);
			else if (all->map[i][j] == 'C')
				mlx_put_image_to_window(all->mlx, all->mlx_new_win,
					all->image->img_coin, j * IMG_WIDTH, i * IMG_HEIGHT);
			else if (all->map[i][j] == 'E')
				add_exit(all, i, j);
			else if (all->map[i][j] == 'P')
				add_player(all, i, j);
			else if (all->map[i][j] == 'O')
				add_enemy(all, i, j, index_enemy++);
            j++;
		}
		i++;
	}
}

void	display_window_bonus(t_info *all)
{
	int i, j = 0;
	i = 0;
	all->mlx = mlx_init();
	if (!all->mlx)
        free_all_bonus(all, 1337);
	the_start_window_bonus(all);
	mlx_destroy_display(all->mlx);
	free(all->mlx);
	all->mlx = mlx_init();
	if (!all->mlx)
		free_all_bonus(all, 1337);
	all->mlx_new_win = mlx_new_window(all->mlx, all->dimensions->height
			* IMG_HEIGHT, all->dimensions->width * IMG_WIDTH, "so_long");
	if (!all->mlx_new_win)
		free_all_bonus(all, 1337);
	add_images_bonus(all, i, j);
	display_map_bonus(all);
	move_player_bonus(all);
	mlx_loop(all->mlx);
}
