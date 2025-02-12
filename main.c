/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <mfahmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:50:47 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/12 19:11:57 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_errors_of_map(t_info *all)
{
    if (!all->map[0])
    {
        free_data(all);
        exit(1);
    }
    check_is_rectangular(all);
    check_elemnts(all);
    check_the_state_of_wall(all);
    flood_fill(all);
    free_map(all->map);
    all->map = malloc((all->lenght_of_map + 1) * sizeof(char *));
    submit_data_mapp(all);
}

int main(int ac, char **av)
{
    t_info *all;

    all = NULL;
    if (ac == 2)
    {
        check_extension(av);
        allocate_data(&all, lenght_of_map(av[1]));
        all->name_of_map = av[1];
        all->lenght_of_map = lenght_of_map(av[1]);
        submit_data_mapp(all);
        check_errors_of_map(all);
        // count_hight_width(all);
        display_window(all);
        free_data(all);
    }
}
