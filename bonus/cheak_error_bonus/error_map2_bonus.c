/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <mfahmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:50:42 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/25 15:15:01 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void    check_elemts_bonus(t_info *all)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (all->map[i])
    {
        j = 0;
        while(all->map[i][j])
        {
            if(all->map[i][j] == 'C' || all->map[i][j] == 'E' || all->map[i][j] == 'P')
            {
                free_data_bonus(all);
                exit(ft_print("Error\nOne of elemnts can't be reach\n", 2));                
            }
            j++;
        }
        i++;
    }   
}

void    flood_fill_aux_bonus(t_info *all, int i, int j)
{
    if (i < 0 || j < 0  || !all->map[i] || !all->map[i][j] || all->map[i][j] == '1' || all->map[i][j] == 'F')
        return;
    all->map[i][j] = 'F';
    flood_fill_aux_bonus(all, i + 1, j);
    flood_fill_aux_bonus(all, i - 1, j);
    flood_fill_aux_bonus(all, i, j + 1);
    flood_fill_aux_bonus(all, i, j - 1);

}

void    flood_fill_bonus(t_info *all)
{
    
    int i;
    int j;

    i = 0;
    while (all->map[i])
    {
        j = 0;
        while(all->map[i][j])
        {
            if(all->map[i][j] == 'P')
                break;
            j++;
        }
        if(all->map[i][j] == 'P')
            break;        
        i++;
    }
    flood_fill_aux_bonus(all, i, j);
    check_elemts_bonus(all);
}

void check_errors_of_map_bonus(t_info *all)
{
    if (!all->map[0])
    {
        free_data_bonus(all);
        exit(1);
    }
    check_is_rectangular_bonus(all);
    check_elemnts_bonus(all);
    check_the_state_of_wall_bonus(all);
    flood_fill_bonus(all);
    free_map(all->map);
    all->map = malloc((all->lenght_of_map + 1) * sizeof(char *));
    if (!all->map)
    {
        free_data_bonus(all);
        exit(1);
    }
    submit_data_map_bonus(all);
}
