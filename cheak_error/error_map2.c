/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <mfahmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:50:42 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/24 11:37:08 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    check_elemts(t_info *all)
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
                free_data(all);
                exit(ft_print("Error\none of elemnts can't be reach\n", 2));                
            }
            j++;
        }
        i++;
    }   
}

void    check_extension(char *str)
{
    int i;
    int fd;

    i = 0;
    fd = open(str, O_RDWR);
    if (fd == -1)
        exit(ft_print("Error\nthe file not found\n", 1));
    close(fd);
    while (str[i])
    {
        if(str[i] == '.')
            break;
        i++;
    }
    if(!str[i] || str[i - 1] == '/' || ft_strcmp(".ber", str + i))
        exit(ft_print("Error\nUnsupported File Extension\n", 2));
}

void    flood_fill_aux(t_info *all, int i, int j)
{
    if (i < 0 || j < 0  || !all->map[i] || !all->map[i][j] || all->map[i][j] == '1' || all->map[i][j] == 'F')
        return;
    all->map[i][j] = 'F';
    flood_fill_aux(all, i + 1, j);
    flood_fill_aux(all, i - 1, j);
    flood_fill_aux(all, i, j + 1);
    flood_fill_aux(all, i, j - 1);

}

void    flood_fill(t_info *all)
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
    flood_fill_aux(all, i, j);
    check_elemts(all);
}

void check_errors_of_map(t_info *all)
{
    // if (!all->map[0]) // ? what is this 
    // {
    //     free_data(all);
    //     exit(1);
    // }
    check_is_rectangular(all);
    check_elemnts(all);
    check_the_state_of_wall(all);
    flood_fill(all);
    free_map(all->map);
    all->map = malloc((all->lenght_of_map + 1) * sizeof(char *));
    if (!all->map)
    {
        free_data(all);
        exit(1);
    }
    submit_data_map(all);
}
