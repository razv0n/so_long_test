
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <mfahmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:47:10 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/21 21:54:53 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

// ...existing code...

int main(int argc, char **argv)
{
    t_info all;

    // ...existing code to initialize all...

    move_player_bonus(&all); // Ensure move_player_bonus is called to set up hooks
    mlx_loop(all.mlx); // Start the event loop

    return (0);
}