/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <mfahmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:10:37 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/17 16:45:51 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void    submit_data_map_bonus(t_info *all)
{
        int fd, i;

        fd = open(all->name_of_map, O_RDWR);
        if (fd == -1)
        {
            free_data_bonus(all);
            exit(1);
        }
        i = 0;
        all->map[i] = get_next_line(fd);
        while(all->map[i])
        {
            i++;
            all->map[i] = get_next_line(fd);
        }
        all->map[i] = NULL;
        close(fd);
}

void    count_hight_width_bonus(t_info *all)
{
    int i;

    i = 0;
    while (all->map[i])
        i++;
    all->dimensions->width = i;
    all->dimensions->height = ft_len(all->map[0]) - 1; //* -1 for the new line
}
