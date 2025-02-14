/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <mfahmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:50:50 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/14 10:03:58 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_print(char *str, int std)
{
    int i;

    i = 0;
    if (!str)
        return (0);
    while (str[i])
    {
        write(std, &str[i], 1);
        i++;
    }
    return (1);
}

int	ft_strcmp(const char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
int    ft_len(char *str)
{
    int i;

    i = 0;
    if (!str)
        return (i);
    while (str[i])
        i++;
    return (i);
}
void    count_hight_width(t_info *all)
{
    int i;

    i = 0;
    while (all->map[i])
        i++;
    all->dimensions->width = i;
    all->dimensions->height = ft_len(all->map[0]) - 1; //* -1 for the new line
}
void    submit_data_mapp(t_info *all)
{
        int fd, i;

        fd = open(all->name_of_map, O_RDWR);
        if (fd == -1)
        {
            free_data(all);
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
