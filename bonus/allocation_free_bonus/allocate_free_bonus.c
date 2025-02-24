/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_free_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <mfahmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:59:56 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/23 15:07:21 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void    init_data_bonus(t_info *all)
{
    all->moves_count = 0;
    all->exit_game = false;
    all->we_have_exit = false;
    all->position[PLAYER] = NULL;
    all->how_many_O = 0;
    all->prev_elemnt = NULL;
    all->position_o = NULL;
    all->dimensions = NULL;
    all->image = NULL;
    all->map = NULL;
    all->direction_o = NULL;
    all->position[EXIT] = NULL;
}

int    free_all_bonus(t_info *all, int msg)
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

void    allocate_data_bonus(t_info **all, int lenght_of_map)
{
    *all = malloc(sizeof(t_info));
    if (!*all)
        exit(1);
    init_data_bonus(*all);
    (*all)->position[EXIT] = malloc(sizeof(t_position));
    if (!(*all)->position[EXIT])
        return (free_data_bonus(*all), exit(1));
    (*all)->position[PLAYER] = malloc(sizeof(t_position));
    if (!(*all)->position[PLAYER])
        return (free_data_bonus(*all), exit(1));
    (*all)->dimensions = malloc(sizeof(t_wihe));
    if (!(*all)->dimensions)
        return (free_data_bonus(*all), exit(1));
    (*all)->image = malloc(sizeof(t_imgs));
    if(!(*all)->image)
        return (free_data_bonus(*all), exit(1));
    (*all)->lenght_of_map = lenght_of_map;
    (*all)->map = malloc(sizeof(char*) * ((*all)->lenght_of_map + 1));
    if (!(*all)->map)
        return (free_data_bonus(*all), exit(1));
}

void free_data_bonus(t_info *all)
{
    if (all->dimensions)
        free(all->dimensions);
    if (all->position[PLAYER])
        free(all->position[PLAYER]);
    if (all->image)
        free(all->image);
    if (all->map)
        free_map(all->map);
    if (all->position_o)
        free(all->position_o);
    if (all->position[EXIT])
        free(all->position[EXIT]);
    if (all->direction_o)
        free(all->direction_o);
    if (all->prev_elemnt)
        free(all->prev_elemnt);
    if (all)
        free(all);
}
void free_mlx_bonus(t_info *all)
{
    mlx_destroy_image(all->mlx, all->image->img_player_left);
    mlx_destroy_image(all->mlx, all->image->img_player_right);
    mlx_destroy_image(all->mlx, all->image->img_player_front);
    mlx_destroy_image(all->mlx, all->image->img_player_back);
    mlx_destroy_image(all->mlx, all->image->img_player_left_a);
    mlx_destroy_image(all->mlx, all->image->img_player_right_a);
    mlx_destroy_image(all->mlx, all->image->img_player_close);
    mlx_destroy_image(all->mlx, all->image->img_player_up);
    mlx_destroy_image(all->mlx, all->image->img_player_down);
    mlx_destroy_image(all->mlx, all->image->img_coin);
    mlx_destroy_image(all->mlx, all->image->img_exit_close);
    mlx_destroy_image(all->mlx, all->image->img_exit_open);
    mlx_destroy_image(all->mlx, all->image->img_enemy_up1);
    mlx_destroy_image(all->mlx, all->image->img_enemy_left1);
    mlx_destroy_image(all->mlx, all->image->img_enemy_down1);
    mlx_destroy_image(all->mlx, all->image->img_enemy_down2);
    mlx_destroy_image(all->mlx, all->image->img_enemy_up2);
    mlx_destroy_image(all->mlx, all->image->img_enemy_right1);
    mlx_destroy_image(all->mlx, all->image->img_enemy_right2);
    mlx_destroy_image(all->mlx, all->image->img_enemy_left2);
    mlx_destroy_image(all->mlx, all->image->img_floor);
    mlx_destroy_image(all->mlx, all->image->img_wall);
    mlx_destroy_image(all->mlx, all->image->img_str);
    mlx_destroy_window(all->mlx, all->mlx_new_win);
    mlx_destroy_display(all->mlx);
    free(all->mlx);
}

