/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <mfahmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 23:21:39 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/13 13:53:18 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    error_display(int count_E, int count_C, int count_P, t_info *all)
{
    if (count_E != 1)
    {
        free_data(all);
        exit(ft_print("Error\nin the exit\n", 2));
    }
    else if (count_C == 0)
    {
         free_data(all);
        exit(ft_print("Error\nin the collecter\n", 2));
    }
    else if (count_P != 1)
    {
         free_data(all);
        exit(ft_print("Error\nin the position of player\n", 2));
    }
    all->how_many_C = count_C; // *HERE save the value of the collectebrs to use it to open the exit
}

void    check_is_rectangular(t_info *all)
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
            free_data(all);
            exit(ft_print("Error\nthe map is not rectanglar\n", 2));
        }
        i++;
    }
}

int lenght_of_map(char *str)
{
    int fd;
    char *line;
    int lenght;

    fd = open(str, O_RDWR);
    if (fd == -1)
    {
        ft_print("Error\nthe file not found\n", 2);
        return (-1);
    }
    line = get_next_line(fd);
    lenght = 0;
    while (line)
    {
        lenght++;
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    return (lenght);
}

void    check_elemnts(t_info *all)
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
            else if (all->map[i][j] != '0' && all->map[i][j] != '1' && all->map[i][j] != '\n')
            {
                free_data(all);
                exit(ft_print("Error\nunknown elemnts\n", 2));
            }
            j++;
        }
        i++;
    }
    error_display(count_E, count_C, count_P, all);
}

void    check_the_state_of_wall(t_info *all)
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
                    free_data(all);
                    exit(ft_print("Error\nstate of wall\n", 2));
                }
            }
            else
            {
                if (all->map[i][0] == '1' && all->map[i][lenght - 1] == '1')
                    break;
                else
                {
                    free_data(all);
                    exit(ft_print("Error\nstate of wall\n", 2));
                }
            }
            j++;
        }
        i++;
    }
}
