/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <mfahmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 23:21:39 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/27 15:57:54 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	error_display_bonus(int count_E, int count_C, int count_P, t_info *all)
{
	if (count_E != 1)
	{
		free_data_bonus(all);
		exit(ft_print("Error\nIn The Exit\n", 2));
	}
	else if (count_C == 0)
	{
		free_data_bonus(all);
		exit(ft_print("Error\nIn The Coin\n", 2));
	}
	else if (count_P != 1)
	{
		free_data_bonus(all);
		exit(ft_print("Error\nIn The Position Of Player\n", 2));
	}
	all->how_many_c = count_C;
}

void	check_is_rectangular_bonus(t_info *all)
{
	int	lenght;
	int	i;

	i = 0;
	lenght = ft_len(all->map[i]);
	while (all->map[i])
	{
		if (all->map[i + 1] == NULL)
			lenght--;
		if (lenght != ft_len(all->map[i]))
		{
			free_data_bonus(all);
			exit(ft_print("Error\nThe map is not rectanglar\n", 2));
		}
		i++;
	}
}

void	check_elemnts_bonus(t_info *all)
{
	int (count_E), (count_C), (count_P), (i), (j);
	(1) && (i = -1), count_E = 0, count_C = 0, count_P = 0;
	while (all->map[++i])
	{
		j = 0;
		while (all->map[i][j])
		{
			if (all->map[i][j] == 'C')
				count_C++;
			else if (all->map[i][j] == 'E')
				count_E++;
			else if (all->map[i][j] == 'P')
				count_P++;
			else if (all->map[i][j] == 'O')
				all->how_many_o++;
			else if (all->map[i][j] != '0' && all->map[i][j] != '1'
				&& all->map[i][j] != '\n')
			{
				free_data_bonus(all);
				exit(ft_print("Error\nUnknown Elemnts\n", 2));
			}
			j++;
		}
	}
	error_display_bonus(count_E, count_C, count_P, all);
}

void	check_the_state_of_wall_bonus(t_info *all)
{
	int (i), (j), (lenght), (total_lenght);
	total_lenght = lenght_of_map(all->name_of_map) - 1;
	lenght = ft_strlen(all->map[0]) - 1;
	i = 0;
	while (all->map[i])
	{
		j = 0;
		while (all->map[i][j])
		{
			if (!i || i == total_lenght)
				check_if_state_wall(i, j, all);
			else
			{
				if (all->map[i][0] == '1' && all->map[i][lenght - 1] == '1')
					break ;
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
