/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <mfahmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:22:11 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/27 14:50:38 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_down(t_info *all)
{
	if (all->map[all->position->x + 1][all->position->y] == '1')
		return ;
	prev_elemnt_m(all);
	if (all->map[all->position->x + 1][all->position->y] == 'C')
		all->how_many_c--;
	else if (all->map[all->position->x + 1][all->position->y] == 'E')
	{
		cheak_exit_game(all);
		all->prev_elemnt = EXIT_E;
	}
	all->map[++all->position->x][all->position->y] = 'P';
	mlx_put_image_to_window(all->mlx, all->mlx_new_win,
		all->image->img_player_front, all->position->y * IMG_WIDTH,
		all->position->x * IMG_HEIGHT);
	ft_printf("move : %d\n", ++all->moves_count);
}

void	move_up(t_info *all)
{
	if (all->map[all->position->x - 1][all->position->y] == '1')
		return ;
	prev_elemnt_m(all);
	if (all->map[all->position->x - 1][all->position->y] == 'C')
		all->how_many_c--;
	else if (all->map[all->position->x - 1][all->position->y] == 'E')
	{
		cheak_exit_game(all);
		all->prev_elemnt = EXIT_E;
	}
	all->map[--all->position->x][all->position->y] = 'P';
	mlx_put_image_to_window(all->mlx, all->mlx_new_win,
		all->image->img_player_back, all->position->y * IMG_WIDTH,
		all->position->x * IMG_HEIGHT);
	ft_printf("move : %d\n", ++all->moves_count);
}

void	move_left(t_info *all)
{
	if (all->map[all->position->x][all->position->y - 1] == '1')
		return ;
	prev_elemnt_m(all);
	if (all->map[all->position->x][all->position->y - 1] == 'C')
		all->how_many_c--;
	else if (all->map[all->position->x][all->position->y - 1] == 'E')
	{
		cheak_exit_game(all);
		all->prev_elemnt = EXIT_E;
	}
	all->map[all->position->x][--all->position->y] = 'P';
	mlx_put_image_to_window(all->mlx, all->mlx_new_win,
		all->image->img_player_left, all->position->y * IMG_WIDTH,
		all->position->x * IMG_HEIGHT);
	ft_printf("move : %d\n", ++all->moves_count);
}

void	move_right(t_info *all)
{
	if (all->map[all->position->x][all->position->y + 1] == '1')
		return ;
	prev_elemnt_m(all);
	if (all->map[all->position->x][all->position->y + 1] == 'C')
		all->how_many_c--;
	else if (all->map[all->position->x][all->position->y + 1] == 'E')
	{
		cheak_exit_game(all);
		all->prev_elemnt = EXIT_E;
	}
	all->map[all->position->x][++all->position->y] = 'P';
	mlx_put_image_to_window(all->mlx, all->mlx_new_win,
		all->image->img_player_right, all->position->y * IMG_WIDTH,
		all->position->x * IMG_HEIGHT);
	ft_printf("move : %d\n", ++all->moves_count);
}
