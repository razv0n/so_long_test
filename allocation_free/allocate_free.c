/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <mfahmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:59:56 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/24 10:15:02 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    init_data(t_info *all)
{
     all->moves_count = 0;
     all->exit_game = false;
    all->prev_elemnt = 1337;
    all->position = NULL;
    all->dimensions = NULL;
    all->image = NULL;
   all->map = NULL;
}

int    free_all(t_info *all)
{
        free_mlx(all);
        free_data(all);
        exit(ft_print("exit game\n", 1));
}

void    allocate_data(t_info **all, int lenght_of_map)
{
    *all = malloc(sizeof(t_info));
    if (!*all)
        exit(1);
    init_data(*all);
    (*all)->position = malloc(sizeof(t_position));
    if (!(*all)->position)
        return (free_data(*all), exit(1));
    (*all)->dimensions = malloc(sizeof(t_wihe));
    if (!(*all)->dimensions)
        return (free_data(*all), exit(1));
    (*all)->image = malloc(sizeof(t_imgs));
    if(!(*all)->image)
        return (free_data(*all), exit(1));
    (*all)->lenght_of_map = lenght_of_map;
    (*all)->map = malloc(sizeof(char*) * ((*all)->lenght_of_map + 1));
    if (!(*all)->map)
        return (free_data(*all), exit(1));
}

void free_data(t_info *all)
{
    if (all->dimensions)
        free(all->dimensions);
    if (all->position)
        free(all->position);
    if (all->image)
        free(all->image);
    if (all->map)
        free_map(all->map);
    if (all)
        free(all);
}
void free_mlx(t_info *all)
{
    mlx_destroy_image(all->mlx, all->image->img_player_front);
    mlx_destroy_image(all->mlx, all->image->img_player_back);
    mlx_destroy_image(all->mlx, all->image->img_player_right);
    mlx_destroy_image(all->mlx, all->image->img_player_left);
    mlx_destroy_image(all->mlx, all->image->img_floor);
    mlx_destroy_image(all->mlx, all->image->img_wall);
    mlx_destroy_image(all->mlx, all->image->img_coin);
    mlx_destroy_image(all->mlx, all->image->img_exit_close);
    mlx_destroy_window(all->mlx, all->mlx_new_win);
    mlx_destroy_display(all->mlx);
    free(all->mlx);
}
void free_map(char **map)
{
    int i;

    i = 0;
    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}
