/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <mfahmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:22:11 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/25 18:32:03 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	move_down_bonus(t_info *all)
{
	if (all->map[all->position[PLAYER]->x + 1][all->position[PLAYER]->y] == '1')
		return ;
    cheak_prev_elemnt(all);
	if (all->map[all->position[PLAYER]->x
		+ 1][all->position[PLAYER]->y] == 'C')
		all->how_many_C--;
	else if (all->map[all->position[PLAYER]->x
		+ 1][all->position[PLAYER]->y] == 'O')
		free_all_bonus(all, LOSE_GAME);
	else if (all->map[all->position[PLAYER]->x
		+ 1][all->position[PLAYER]->y] == 'E')
	{
		cheak_exit_game_bonus(all);
        all->prev_elemnt_p = EXIT_E;
	}
	all->map[++all->position[PLAYER]->x][all->position[PLAYER]->y] = 'P';
	str_window(all);
}

void	move_up_bonus(t_info *all)
{
	if (all->map[all->position[PLAYER]->x - 1][all->position[PLAYER]->y] == '1')
		return ;
    cheak_prev_elemnt(all);
	if (all->map[all->position[PLAYER]->x
		- 1][all->position[PLAYER]->y] == 'C')
		all->how_many_C--;
	else if (all->map[all->position[PLAYER]->x
		- 1][all->position[PLAYER]->y] == 'O')
		free_all_bonus(all, LOSE_GAME);
	else if (all->map[all->position[PLAYER]->x
		- 1][all->position[PLAYER]->y] == 'E')
	{
		cheak_exit_game_bonus(all);
		all->prev_elemnt_p = EXIT_E;
	}
	all->map[--all->position[PLAYER]->x][all->position[PLAYER]->y] = 'P';
	str_window(all);
}

void	move_left_bonus(t_info *all)
{
	if (all->map[all->position[PLAYER]->x][all->position[PLAYER]->y - 1] == '1')
		return ;
	cheak_prev_elemnt(all);
    if (all->map[all->position[PLAYER]->x][all->position[PLAYER]->y
		- 1] == 'C')
		all->how_many_C--;
	else if (all->map[all->position[PLAYER]->x][all->position[PLAYER]->y
		- 1] == 'O')
		free_all_bonus(all, LOSE_GAME);
	else if (all->map[all->position[PLAYER]->x][all->position[PLAYER]->y
		- 1] == 'E')
	{
		cheak_exit_game_bonus(all);
        all->prev_elemnt_p = EXIT_E;
	}
	all->map[all->position[PLAYER]->x][--all->position[PLAYER]->y] = 'P';
	str_window(all);
}

void	move_right_bonus(t_info *all)
{
	if (all->map[all->position[PLAYER]->x][all->position[PLAYER]->y + 1] == '1')
		return ;
    cheak_prev_elemnt(all);
	if (all->map[all->position[PLAYER]->x][all->position[PLAYER]->y
		+ 1] == 'C')
		all->how_many_C--;
	else if (all->map[all->position[PLAYER]->x][all->position[PLAYER]->y
		+ 1] == 'O')
		free_all_bonus(all, LOSE_GAME);
	else if (all->map[all->position[PLAYER]->x][all->position[PLAYER]->y
		+ 1] == 'E')
	{
		cheak_exit_game_bonus(all);
        all->prev_elemnt_p = EXIT_E;
	}
	all->map[all->position[PLAYER]->x][++all->position[PLAYER]->y] = 'P';
	str_window(all);
}
