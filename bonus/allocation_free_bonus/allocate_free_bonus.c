/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_free_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <mfahmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:59:56 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/27 14:58:38 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	init_data_bonus(t_info *all)
{
	all->moves_count = 0;
	all->exit_game = false;
	all->prev_elemnt_p = 1337;
	all->we_have_exit = false;
	all->position = NULL;
	all->how_many_o = 0;
	all->prev_elemnt = NULL;
	all->position_o = NULL;
	all->dimensions = NULL;
	all->image = NULL;
	all->map = NULL;
	all->direction_o = NULL;
	all->deriction = RIGHT_D;
}

int	free_all_bonus(t_info *all, int msg)
{
	free_mlx_bonus(all);
	free_data_bonus(all);
	if (msg == EXIT_GAME)
		ft_print("Exit Game\n", 1);
	else if (msg == LOSE_GAME)
		ft_print("You Lose\n", 1);
	else if (msg == WIN_GAME)
		ft_print("You Win\n", 1);
	exit(1);
}

void	allocate_data_bonus(t_info **all, int lenght_of_map)
{
	*all = malloc(sizeof(t_info));
	if (!*all)
		exit(1);
	init_data_bonus(*all);
	(*all)->position = malloc(sizeof(t_position));
	if (!(*all)->position)
		return (free_data_bonus(*all), exit(1));
	(*all)->dimensions = malloc(sizeof(t_wihe));
	if (!(*all)->dimensions)
		return (free_data_bonus(*all), exit(1));
	(*all)->image = malloc(sizeof(t_imgs));
	if (!(*all)->image)
		return (free_data_bonus(*all), exit(1));
	init_img(*all);
	(*all)->lenght_of_map = lenght_of_map;
	(*all)->map = malloc(sizeof(char *) * ((*all)->lenght_of_map + 1));
	if (!(*all)->map)
		return (free_data_bonus(*all), exit(1));
}

void	free_data_bonus(t_info *all)
{
	if (all->dimensions)
		free(all->dimensions);
	if (all->position)
		free(all->position);
	if (all->image)
		free(all->image);
	if (all->map)
		free_map(all->map);
	if (all->position_o)
		free(all->position_o);
	if (all->direction_o)
		free(all->direction_o);
	if (all->prev_elemnt)
		free(all->prev_elemnt);
	if (all)
		free(all);
}

void	free_mlx_bonus(t_info *all)
{
	if (all->image->img_player_left)
		mlx_destroy_image(all->mlx, all->image->img_player_left);
	if (all->image->img_player_right)
		mlx_destroy_image(all->mlx, all->image->img_player_right);
	if (all->image->img_player_front)
		mlx_destroy_image(all->mlx, all->image->img_player_front);
	if (all->image->img_player_back)
		mlx_destroy_image(all->mlx, all->image->img_player_back);
	if (all->image->img_player_left_a)
		mlx_destroy_image(all->mlx, all->image->img_player_left_a);
	if (all->image->img_player_right_a)
		mlx_destroy_image(all->mlx, all->image->img_player_right_a);
	if (all->image->img_player_close)
		mlx_destroy_image(all->mlx, all->image->img_player_close);
	if (all->image->img_player_up)
		mlx_destroy_image(all->mlx, all->image->img_player_up);
	if (all->image->img_player_down)
		mlx_destroy_image(all->mlx, all->image->img_player_down);
	free_mlx_bonus2(all);
	free_mlx_bonus3(all);
}
