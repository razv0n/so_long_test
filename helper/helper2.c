/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <mfahmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:38:44 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/24 15:37:59 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    check_error_wall(int i, int j, t_info *all)
{
     if (all->map[i][j] != '1' && all->map[i][j] != '\n')
    {
         free_data(all);
         exit(ft_print("Error\nState Of Wall\n", 2));
    }
}
