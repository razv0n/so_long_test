/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <mfahmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:09:50 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/11 16:05:16 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void display_map(t_info *all, char **map)
{
    int i;
    int j;
    
    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if(map[i][j] == '0')
                mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_floor, i + IMG_WIDTH , j + IMG_HEIGHT);
            else if(map[i][j] == '1')
                mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_wall, i + IMG_WIDTH , j + IMG_HEIGHT);
            else if(map[i][j] == 'C')
                mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_coin, i + IMG_WIDTH , j + IMG_HEIGHT);
            else if(map[i][j] == 'E')
                mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_exit, i + IMG_WIDTH , j + IMG_HEIGHT);
            else if(map[i][j] == 'P')
                mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_player, i + IMG_WIDTH , j + IMG_HEIGHT);  
            j++;
        }
        i++;
    }
}
void display_window(char **map)
{
	t_info *all;
    int i;
    int j;
    
    i = j = 0;
    all = malloc(sizeof(t_info));
    if (!all)
    {
        free_map(map); //? u should change this
        exit(1);
    }
    count_hight_width(map, all);
    all->mlx = mlx_init();
    all->mlx_new_win = mlx_new_window(all->mlx, all->dimensions->width, all->dimensions->height, "so_long");
    all->image = malloc(sizeof(t_imgs));
    if (!all->image)
    {
        free_map(map);
        exit(1);
    }
    all->image->img_floor = mlx_xpm_file_to_image(all->mlx, FLOOR_XPM, &i, &j);
    all->image->img_wall = mlx_xpm_file_to_image(all->mlx, WALL_XPM, &i, &j);
    all->image->img_player = mlx_xpm_file_to_image(all->mlx, PLAYER_LEFT_XPM,  &i, &j);
    all->image->img_exit = mlx_xpm_file_to_image(all->mlx, EXIT_CLOSED_XPM, &i, &j);
    all->image->img_coin = mlx_xpm_file_to_image(all->mlx, COINS_XPM, &i, &j);
    display_map(all, map);
    mlx_loop(all->mlx);
}
