/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <mfahmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:59:56 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/13 18:20:03 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    allocate_data(t_info **all, int lenght_of_map)
{
    *all = malloc(sizeof(t_info));
    if (!*all)
        return (free(*all), exit(1));
    (*all)->we_have_exit = false;
    (*all)->position = NULL;
    (*all)->dimensions = NULL;
    (*all)->image = NULL;
   (*all)->map = NULL;
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
