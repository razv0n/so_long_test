/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <mfahmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:38:44 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/27 14:47:57 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_error_wall(int i, int j, t_info *all)
{
	if (all->map[i][j] != '1' && all->map[i][j] != '\n')
	{
		free_data(all);
		exit(ft_print("Error\nState Of Wall\n", 2));
	}
}

void	prev_elemnt_m(t_info *all)
{
	if (all->prev_elemnt == EXIT_E)
	{
		all->map[all->position->x][all->position->y] = 'E';
		mlx_put_image_to_window(all->mlx, all->mlx_new_win,
			all->image->img_exit_close, all->position->y * IMG_WIDTH,
			all->position->x * IMG_HEIGHT);
		all->prev_elemnt = 1337;
	}
	else
	{
		all->map[all->position->x][all->position->y] = '0';
		mlx_put_image_to_window(all->mlx, all->mlx_new_win,
			all->image->img_floor, all->position->y * IMG_WIDTH,
			all->position->x * IMG_HEIGHT);
	}
}

void	add_player_m(t_info *all, int i, int j)
{
	mlx_put_image_to_window(all->mlx, all->mlx_new_win,
		all->image->img_player_front, j * IMG_WIDTH, i * IMG_HEIGHT);
	all->position->x = i;
	all->position->y = j;
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
