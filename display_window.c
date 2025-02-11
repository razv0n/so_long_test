/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <mfahmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:09:50 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/11 14:54:27 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void display_map(t_info all)
{
    int i;
    int j;
    void *mlx;
    void *new_win;
    
    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if(map[i][j] == '0')
                mlx_put_img_to_window(mlx, new_win, all->image->img_floor, );
            else if(map[i][j] == '1')
                mlx_put_img_to_window(mlx, new_win, all->image->img_wall);
            else if(map[i][j] == 'C')
                mlx_put_img_to_window(mlx, new_win, all->image->img_coin);
            else if(map[i][j] == 'E')
                mlx_put_img_to_window(mlx, new_win, all->image->img_exit);
            else if(map[i][j] == 'P')
                mlx_put_img_to_window(mlx, new_win, all->image->img_player);  
            j++;
        }
        i++;
    }
}
void display_window(char **map)
{
	t_info *all;

    count_hight_width(map);
    mlx = mlx_init();
    all->image = malloc(sizeof(t_imgs));
    if (!all->image)
    {
        free_map(map);
        exit(1);
    }
    all->image->img_floor = mlx_xpm_file_to_image(mlx, FLOOR_XPM);
    all->image->img_wall = mlx_xpm_file_to_image(mlx, WALL_XPM);
    all->image->img_player = mlx_xpm_file_to_image(mlx, PLAYER_LEFT_XPM);
    all->image->img_exit = mlx_xpm_file_to_image(mlx, EXIT_CLOSED_XPM);
    all->image->img_coin = mlx_xpm_file_to_image(mlx, COINS_XPM);
    display_map(all);
    new_win = mlx_new_window(mlx, image->width, image->height, "so_long");
}
