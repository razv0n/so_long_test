/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <mfahmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 23:21:39 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/10 17:14:38 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    error_display(int count_E, int count_C, int count_P, char **map)
{
    if (count_E != 1)
    {
        free_map(map);
        exit(ft_print("Error\nin the exit\n", 2));
    }
    else if (count_C == 0)
    {
        free_map(map);
        exit(ft_print("Error\nin the collecter\n", 2));
    }
    else if (count_P != 1)
    {
        free_map(map);
        exit(ft_print("Error\nin the position of player\n", 2));
    }
}

void    check_is_rectangular(char **map)
{
    int lenght;
    int i;

    i = 0;
    lenght = ft_len(map[i]);
    while (map[i])
    {
        if (map[i + 1] == NULL)
            lenght--;
        if (lenght != ft_len(map[i]))
        {
            free_map(map);
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
void    check_elemnts(char **map)
{
    int (count_E), (count_C), (count_P), (i), (j);
    i = 0;
    count_P = 0;
    count_E = 0;
    count_C = 0;
    while(map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if (map[i][j] == 'C')
                count_C++;
            else if (map[i][j] == 'E')
                count_E++;
            else if (map[i][j] == 'P')
                count_P++;
            else if (map[i][j] != '0' && map[i][j] != '1')
            {
                free_map(map);
                exit(ft_print("Error\nunknown elemnts\n", 2));
            }
            j++;
        }
        i++;
    }
    error_display(count_E, count_C, count_P, map);
}
void    check_the_state_of_wall(char **map, char *str)
{
    int (i), (j), (lenght), (total_lenght);
    total_lenght = lenght_of_map() - 1;
    lenght = ft_strlen(map[0]) - 1;
    i = 0;
    while(map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (!i || i == total_lenght)
            {
                if (map[i][j] != '1' && map[i][j] != '\n')
                {
                    free_map(map);
                    exit(ft_print("Error\nstate of wall\n", 2));
                }
            }
            else
            {
                if (map[i][0] == '1' && map[i][lenght - 1] == '1')
                    break;
                else
                {
                    free_map(map);
                    exit(ft_print("Error\nstate of wall\n", 2));
                }
            }
            j++;
        }
        i++;
    }
}
