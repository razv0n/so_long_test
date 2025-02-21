/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <mfahmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 11:58:01 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/21 16:41:15 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int main(int ac, char **av)
{
     t_info *all;
    int lenght_map;

    all = NULL;
    if (ac == 2)
    {
        check_extension(av[1]);
        lenght_map = lenght_of_map(av[1]);
        allocate_data_bonus(&all, lenght_map);
        all->name_of_map = av[1];
        all->lenght_of_map = lenght_map;
        submit_data_map_bonus(all);
        check_errors_of_map_bonus(all);
        count_hight_width_bonus(all);
        allocation_enemy (all);
        display_window_bonus(all);
        free_mlx_bonus(all);
        free_data_bonus(all);
    }
}