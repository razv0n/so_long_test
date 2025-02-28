/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <mfahmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:04:49 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/27 14:58:38 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	animation_player(t_info *all, int *state, clock_t *prev, clock_t now)
{
	double	time_diff;

	time_diff = (double)(now - *prev) / CLOCKS_PER_SEC;
	if (time_diff >= 0.17)
	{
		update_player(all, *state);
		if (all->deriction == UP_D)
			update_player_up(all, *state);
		else if (all->deriction == DOWN_D)
			update_player_down(all, *state);
		*prev = now;
		(*state)++;
	}
	return (0);
}

int	animation_enemy(t_info *all, int *state_1, clock_t *prev_1, clock_t now)
{
	double	time_diff;
	int		i;

	time_diff = (double)(now - *prev_1) / CLOCKS_PER_SEC;
	i = 0;
	if (time_diff >= 0.17)
	{
		while (i < all->how_many_o)
		{
			update_enemy(all, *state_1, i);
			i++;
		}
		*prev_1 = now;
		(*state_1)++;
	}
	return (0);
}

int	animate(t_info *all)
{
	clock_t			now;
	static clock_t	prev_1 = 0;
	static int		state_1 = 0;
	static clock_t	prev = 0;
	static int		state = 0;

	now = clock();
	animation_player(all, &state, &prev, now);
	animation_enemy(all, &state_1, &prev_1, now);
	return (0);
}
