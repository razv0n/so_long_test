/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <mfahmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:09:50 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/11 12:01:49 by mfahmi           ###   ########.fr       */
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


void display_map(void *img_floor, void *img_wall, void *img_coin, void *img_exit, void *img_player)
{
    int i;
    int j;
    void *mlx;
    void *new_win
    mlx = mlx_init();
    new_win = mlx_new_window(mlx, , ,"so_long");
    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if(map[i][j] == '0')
                mlx_put_img_to_window(mlx, new_win,)
            else if(map[i][j] == '1')
                mlx_put
            else if(map[i][j] == 'C')
            else if(map[i][j] == 'E')
            else if(map[i][j] == 'P')
        
            j++:
        }
        i++;
    }
}
void display_window(char **map)
{
	void	*img_floor, *img_wall, *img_coin, *img_exit, *img_player;
	void	*mlx;
    void    *mlx_win;

        
                img_floor = mlx_xpm_file_to_image(mlx, FLOOR_XPM);
                img_wall = mlx_xpm_file_to_image(mlx, WALL_XPM);
                img_player = mlx_xpm_file_to_image(mlx, PLAYER_LEFT_XPM);
                img_exit = mlx_xpm_file_to_image(mlx, EXIT_CLOSED_XPM);
                img_coin = mlx_xpm_file_to_image(mlx, COINS_XPM);
}