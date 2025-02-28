/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <mfahmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:47:10 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/27 14:50:38 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	cheak_exit_game(t_info *all)
{
	if (!all->how_many_c)
	{
		ft_printf("move : %d\n", ++all->moves_count);
		free_all(all);
		exit(ft_print("congrate u won\n", 1));
	}
}

int	keycode(int key, t_info *all)
{
	if (key == ESC)
		free_all(all);
	else if (key == KEY_W || key == KEY_UP)
		move_up(all);
	else if (key == KEY_S || key == KEY_DOWN)
		move_down(all);
	else if (key == KEY_A || key == KEY_LEFT)
		move_left(all);
	else if (key == KEY_D || key == KEY_RIGHT)
		move_right(all);
	return (0);
}

void	move_player(t_info *all)
{
	mlx_hook(all->mlx_new_win, 2, 1L << 0, keycode, all);
	mlx_hook(all->mlx_new_win, 17, 0, free_all, all);
}
