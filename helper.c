/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <mfahmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:50:50 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/11 16:04:33 by mfahmi           ###   ########.fr       */
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
void    count_hight_width(char **map, t_info *all)
{
    int i;

    all->dimensions = malloc (sizeof(t_wihe));
    if (!all->dimensions)
    {
        free_map(map);  //! u should using free here or find a solution to use struct
        exit(1);
    }
    i = 0;
    while (map[i])
        i++;
    all->dimensions->width = i;
    all->dimensions->height = ft_len(map[0]);
}