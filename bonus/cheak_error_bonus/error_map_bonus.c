/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <mfahmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 23:21:39 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/21 16:55:29 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void    error_display_bonus(int count_E, int count_C, int count_P, t_info *all)
{
    if (count_E != 1)
    {
        free_data_bonus(all);
        exit(ft_print("Error\nin the exit\n", 2));
    }
    else if (count_C == 0)
    {
         free_data_bonus(all);
        exit(ft_print("Error\nin the collecter\n", 2));
    }
    else if (count_P != 1)
    {
         free_data_bonus(all);
        exit(ft_print("Error\nin the position of player\n", 2));
    }
    all->how_many_C = count_C;
}

void    check_is_rectangular_bonus(t_info *all)
{
    int lenght;
    int i;

    i = 0;
    lenght = ft_len(all->map[i]);
    while (all->map[i])
    {
        if (all->map[i + 1] == NULL)
            lenght --;
        if (lenght != ft_len(all->map[i]))
        {
            free_data_bonus(all);
            exit(ft_print("Error\nthe map is not rectanglar\n", 2));
        }
        i++;
    }
}

void    check_elemnts_bonus(t_info *all)
{
    int (count_E), (count_C), (count_P), (i), (j);
    i = 0;
    count_P = 0;
    count_E = 0;
    count_C = 0;
    
    while(all->map[i])
    {
        j = 0;
        while(all->map[i][j])
        {
            if (all->map[i][j] == 'C')
                count_C++;
            else if (all->map[i][j] == 'E')
                count_E++;
            else if (all->map[i][j] == 'P')
                count_P++;
            else if (all->map[i][j] == 'O')
                all->how_many_O++;
            else if (all->map[i][j] != '0' && all->map[i][j] != '1' && all->map[i][j] != '\n' && all->map[i][j] != 'O')
            {
                free_data_bonus(all);
                exit(ft_print("Error\nunknown elemnts\n", 2));
            }
            j++;
        }
        i++;
    }
    error_display_bonus(count_E, count_C, count_P, all);
}

void    check_the_state_of_wall_bonus(t_info *all)
{
    int (i), (j), (lenght), (total_lenght);
    total_lenght = lenght_of_map(all->name_of_map) - 1;
    lenght = ft_strlen(all->map[0]) - 1;
    i = 0;
    while(all->map[i])
    {
        j = 0;
        while (all->map[i][j])
        {
            if (!i || i == total_lenght)
            {
                if (all->map[i][j] != '1' && all->map[i][j] != '\n')
                {
                    free_data_bonus(all);
                    exit(ft_print("Error\nstate of wall\n", 2));
                }
            }
            else
            {
                if (all->map[i][0] == '1' && all->map[i][lenght - 1] == '1')
                    break;
                else
                {
                    free_data_bonus(all);
                    exit(ft_print("Error\nstate of wall\n", 2));
                }
            }
            j++;
        }
        i++;
    }
}

