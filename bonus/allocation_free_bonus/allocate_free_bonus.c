/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_free_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <mfahmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:59:56 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/16 16:19:54 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

// void    init_data(t_info *all)
// {
//      all->moves_count = 0;
//      all->exit_game = false;
//     all->we_have_exit = false;
//     all->position = NULL;
//     all->dimensions = NULL;
//     all->image = NULL;
//    all->map = NULL;
//    all->position_exit = NULL;
// }

int    free_all_bonus(t_info *all)
{
        free_mlx_bonus(all);
        free_data_bonus(all);
        exit(ft_print("exit game\n", 1));
}

void    allocate_data_bonus(t_info **all, int lenght_of_map)
{
    *all = malloc(sizeof(t_info));
    if (!*all)
        exit(1);
       (*all)->moves_count = 0;
     (*all)->exit_game = false;
    (*all)->we_have_exit = false;
    (*all)->position = NULL;
    (*all)->dimensions = NULL;
    (*all)->image = NULL;
   (*all)->map = NULL;
   (*all)->position_exit = NULL;
    (*all)->position_exit = malloc(sizeof(t_position));
    if (!(*all)->position_exit)
        return (free_data_bonus(*all), exit(1));
    (*all)->position = malloc(sizeof(t_position));
    if (!(*all)->position)
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
    if (all->position)
        free(all->position);
    if (all->image)
        free(all->image);
    if (all->map)
        free_map(all->map);
    if (all->position_exit)
        free(all->position_exit);
    if (all)
        free(all);
}
void free_mlx_bonus(t_info *all)
{
    mlx_destroy_image(all->mlx, all->image->img_player_front);
    mlx_destroy_image(all->mlx, all->image->img_player_back);
    mlx_destroy_image(all->mlx, all->image->img_player_right);
    mlx_destroy_image(all->mlx, all->image->img_player_left);
    mlx_destroy_image(all->mlx, all->image->img_floor);
    mlx_destroy_image(all->mlx, all->image->img_wall);
    mlx_destroy_image(all->mlx, all->image->img_coin);
    mlx_destroy_image(all->mlx, all->image->img_exit_close);
    mlx_destroy_image(all->mlx, all->image->img_exit_open);
    mlx_destroy_image(all->mlx, all->image->img_player_close);
    mlx_destroy_image(all->mlx, all->image->img_player_right_a);
    mlx_destroy_image(all->mlx, all->image->img_player_left_a);
    mlx_destroy_image(all->mlx, all->image->img_player_up);
    mlx_destroy_image(all->mlx, all->image->img_player_down);
    mlx_destroy_window(all->mlx, all->mlx_new_win);
    mlx_destroy_display(all->mlx);
    free(all->mlx);
}

