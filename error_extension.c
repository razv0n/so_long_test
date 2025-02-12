/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <mfahmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:50:42 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/12 21:21:54 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
void    check_extension(char **str)
{
    int i;

    i = 0;
    while (str[1][i])
    {
        if(str[1][i] == '.')
            break;
        i++;
    }
    if(!str[1][i] || !i || ft_strcmp(".ber", str[1] + i))
        exit(ft_print("Error\n", 2));
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
