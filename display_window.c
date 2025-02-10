/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <mfahmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:09:50 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/10 19:15:36 by mfahmi           ###   ########.fr       */
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

void display_window(char **map)
{
	void	*img;
	void	*mlx;
    void    *mlx_win;
    int i;
    int j;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080);
    while(map[i])
    {
        while(map[i][j])
        {
            if (map[i][j] == '0')
            else if (map[i][j] == '1')
            else if (map[i][j] == 'P')
            else if (map[i][j] == 'E')
            else if (map[i][j] == 'C')
            j++;
        }
        i++;
    }
    mlx_loop(mlx);
}