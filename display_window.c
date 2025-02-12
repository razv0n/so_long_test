/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <mfahmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:09:50 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/12 21:01:21 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void display_map(t_info *all)
{
    int j, i = 0;
    while (all->map[i])
    {
        j = 0;
        while (all->map[i][j])
        {
            if(all->map[i][j] == '0')
                mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_floor, j * IMG_WIDTH , i * IMG_HEIGHT);
            else if(all->map[i][j] == '1')
                mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_wall, j * IMG_WIDTH , i * IMG_HEIGHT);
            else if(all->map[i][j] == 'C')
                mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_coin, j * IMG_WIDTH , i * IMG_HEIGHT);
            else if(all->map[i][j] == 'E')
                mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_exit, j * IMG_WIDTH , i * IMG_HEIGHT);
            else if(all->map[i][j] == 'P')
            {
                mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_player, j * IMG_WIDTH , i * IMG_HEIGHT);
                all->position->x =  i;
                all->position->y =  j;
            }
            j++;
        }
        i++;
    }
}

void display_window(t_info *all)
{
    int i;
    int j;
    
    i = j = 0;
    count_hight_width(all);
    all->image = malloc(sizeof(t_imgs));
    if (!all->image)
    {
        free_data(all);
        exit(1);
    }
    all->mlx = mlx_init();
    //  printf("the width os  :%d the hieght is : %d\n",all->dimensions->width, all->dimensions->height);
    all->mlx_new_win = mlx_new_window(all->mlx,all->dimensions->height * IMG_HEIGHT, all->dimensions->width * IMG_WIDTH,"so_long");
    all->image->img_floor = mlx_xpm_file_to_image(all->mlx, FLOOR_XPM, &i, &j);
    all->image->img_wall = mlx_xpm_file_to_image(all->mlx, WALL_XPM, &i, &j);
    all->image->img_player = mlx_xpm_file_to_image(all->mlx, PLAYER_LEFT_XPM,  &i, &j);
    all->image->img_exit = mlx_xpm_file_to_image(all->mlx, EXIT_CLOSED_XPM, &i, &j);
    all->image->img_coin = mlx_xpm_file_to_image(all->mlx, COINS_XPM, &i, &j);
    display_map(all);
    mlx_loop(all->mlx);
}
