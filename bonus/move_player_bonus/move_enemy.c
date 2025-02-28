/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <mfahmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:45:28 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/27 15:00:28 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	move_down_enemy(t_info *all, int i)
{
	if (all->map[all->position_o[i].x + 1][all->position_o[i].y] == '1'
		|| all->map[all->position_o[i].x + 1][all->position_o[i].y] == 'O')
		return ;
	prev_elemnt_enemy(all, i);
	if (all->map[all->position_o[i].x + 1][all->position_o[i].y] == 'C')
		all->prev_elemnt[i] = COINS_E;
	else if (all->map[all->position_o[i].x + 1][all->position_o[i].y] == 'E')
		all->prev_elemnt[i] = EXIT_E;
	else if (all->map[all->position_o[i].x + 1][all->position_o[i].y] == 'P')
		free_all_bonus(all, LOSE_GAME);
	all->map[++all->position_o[i].x][all->position_o[i].y] = 'O';
	all->direction_o[i] = DOWN_D;
}

void	move_up_enemy(t_info *all, int i)
{
	if (all->map[all->position_o[i].x - 1][all->position_o[i].y] == '1'
		|| all->map[all->position_o[i].x - 1][all->position_o[i].y] == 'O')
		return ;
	prev_elemnt_enemy(all, i);
	if (all->map[all->position_o[i].x - 1][all->position_o[i].y] == 'C')
		all->prev_elemnt[i] = COINS_E;
	else if (all->map[all->position_o[i].x - 1][all->position_o[i].y] == 'E')
		all->prev_elemnt[i] = EXIT_E;
	else if (all->map[all->position_o[i].x - 1][all->position_o[i].y] == 'P')
		free_all_bonus(all, LOSE_GAME);
	all->map[--all->position_o[i].x][all->position_o[i].y] = 'O';
	all->direction_o[i] = UP_D;
}

void	move_left_enemy(t_info *all, int i)
{
	if (all->map[all->position_o[i].x][all->position_o[i].y - 1] == '1'
		|| all->map[all->position_o[i].x][all->position_o[i].y - 1] == 'O')
		return ;
	prev_elemnt_enemy(all, i);
	if (all->map[all->position_o[i].x][all->position_o[i].y - 1] == 'C')
		all->prev_elemnt[i] = COINS_E;
	else if (all->map[all->position_o[i].x][all->position_o[i].y - 1] == 'E')
		all->prev_elemnt[i] = EXIT_E;
	else if (all->map[all->position_o[i].x][all->position_o[i].y - 1] == 'P')
		free_all_bonus(all, LOSE_GAME);
	all->map[all->position_o[i].x][--all->position_o[i].y] = 'O';
	all->direction_o[i] = LEFT_D;
}

void	move_right_enemy(t_info *all, int i)
{
	if (all->map[all->position_o[i].x][all->position_o[i].y + 1] == '1'
		|| all->map[all->position_o[i].x][all->position_o[i].y + 1] == 'O')
		return ;
	prev_elemnt_enemy(all, i);
	if (all->map[all->position_o[i].x][all->position_o[i].y + 1] == 'C')
		all->prev_elemnt[i] = COINS_E;
	else if (all->map[all->position_o[i].x][all->position_o[i].y + 1] == 'E')
		all->prev_elemnt[i] = EXIT_E;
	else if (all->map[all->position_o[i].x][all->position_o[i].y + 1] == 'P')
		free_all_bonus(all, LOSE_GAME);
	all->map[all->position_o[i].x][++all->position_o[i].y] = 'O';
	all->direction_o[i] = RIGHT_D;
}

int	move_enemy(t_info *all)
{
	static clock_t	prev_time;
	clock_t			now;
	double			time_diff;

	int (direction), i = 0;
	(1) && (now = clock()), time_diff = (double)(now - prev_time)
		/ CLOCKS_PER_SEC;
	if (time_diff >= 0.5)
	{
		while (i < all->how_many_o)
		{
			direction = rand() % 4;
			if (direction == 0)
				move_right_enemy(all, i);
			else if (direction == 1)
				move_left_enemy(all, i);
			else if (direction == 2)
				move_up_enemy(all, i);
			else if (direction == 3)
				move_down_enemy(all, i);
			i++;
		}
		prev_time = now;
	}
	return (0);
}
