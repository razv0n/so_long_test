/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <mfahmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:50:47 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/14 16:50:54 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int main(int ac, char **av)
{
    t_info *all;
    int lenght_map;

    all = NULL;
    if (ac == 2)
    {
        check_extension(av[1]);
        lenght_map = lenght_of_map(av[1]);
        allocate_data(&all, lenght_map);
        all->name_of_map = av[1];
        all->lenght_of_map = lenght_map;
        submit_data_mapp(all);
        check_errors_of_map(all);
        count_hight_width(all);
        display_window(all);
        free_mlx(all);
        free_data(all);
    }
}
