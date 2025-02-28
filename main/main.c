/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <mfahmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:50:47 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/24 16:04:46 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int ac, char **av)
{
	t_info	*all;
	int		lenght_map;

	all = NULL;
	if (ac == 2)
	{
		check_extension(av[1]);
		lenght_map = lenght_of_map(av[1]);
		allocate_data(&all, lenght_map);
		all->name_of_map = av[1];
		submit_data_map(all);
		check_errors_of_map(all);
		count_hight_width(all);
		display_window(all);
	}
}
