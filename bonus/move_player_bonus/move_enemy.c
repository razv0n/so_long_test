/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <mfahmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:45:28 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/22 20:34:36 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"
#include <stdlib.h> // Include for rand()

void    move_down_enemy(t_info *all, int i)
{
    if (all->map[all->position_o[i].x + 1][all->position_o[i].y] == '1' || all->map[all->position_o[i].x + 1][all->position_o[i].y] == 'O')
        return;
    if (all->prev_elemnt[i] == EXIT_E)
    {
        all->map[all->position_o[i].x][all->position_o[i].y] = 'E';
        mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_exit_close, all->position_o[i].y * IMG_WIDTH , all->position_o[i].x * IMG_HEIGHT);
        all->prev_elemnt[i] = 1337;
    }
    else if (all->prev_elemnt[i] == COINS_E)
    {
        all->map[all->position_o[i].x][all->position_o[i].y] = 'C';
        mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_coin, all->position_o[i].y * IMG_WIDTH , all->position_o[i].x * IMG_HEIGHT);
         all->prev_elemnt[i] = 1337;
    }
    else
    {
        all->map[all->position_o[i].x][all->position_o[i].y] = '0';
        mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_floor, all->position_o[i].y * IMG_WIDTH , all->position_o[i].x * IMG_HEIGHT);
    }
    if (all->map[all->position_o[i].x + 1][all->position_o[i].y] == 'C')
        all->prev_elemnt[i] = COINS_E;
    else if (all->map[all->position_o[i].x + 1][all->position_o[i].y] == 'E')
        all->prev_elemnt[i] = EXIT_E;
    else if (all->map[all->position_o[i].x + 1][all->position_o[i].y] == 'P')
        free_all_bonus(all, LOSE_GAME);
    // printf("the x %d")
    all->map[++all->position_o[i].x][all->position_o[i].y] = 'O';
    all->direction_o[i] = DOWN_D;
}

void    move_up_enemy(t_info *all, int i)
{
    if (all->map[all->position_o[i].x - 1][all->position_o[i].y] == '1' || all->map[all->position_o[i].x - 1][all->position_o[i].y] == 'O')
        return;
    if (all->prev_elemnt[i] == EXIT_E)
    {
        all->map[all->position_o[i].x][all->position_o[i].y] = 'E';
        mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_exit_close, all->position_o[i].y * IMG_WIDTH , all->position_o[i].x * IMG_HEIGHT);
         all->prev_elemnt[i] = 1337;
    }
    else if (all->prev_elemnt[i] == COINS_E)
    {
        all->map[all->position_o[i].x][all->position_o[i].y] = 'C';
        mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_coin, all->position_o[i].y * IMG_WIDTH , all->position_o[i].x * IMG_HEIGHT);
         all->prev_elemnt[i] = 1337;
    }
    else
    {
        all->map[all->position_o[i].x][all->position_o[i].y] = '0';
        mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_floor, all->position_o[i].y * IMG_WIDTH , all->position_o[i].x * IMG_HEIGHT);
    }
    if (all->map[all->position_o[i].x - 1][all->position_o[i].y] == 'C')
        all->prev_elemnt[i] = COINS_E;
    else if (all->map[all->position_o[i].x - 1][all->position_o[i].y] == 'E')
        all->prev_elemnt[i] = EXIT_E;
    else if (all->map[all->position_o[i].x - 1][all->position_o[i].y] == 'P')
        free_all_bonus(all, LOSE_GAME);
    all->map[--all->position_o[i].x][all->position_o[i].y] = 'O';
    all->direction_o[i] = UP_D;
}

void    move_left_enemy(t_info *all, int i)
{
    if (all->map[all->position_o[i].x][all->position_o[i].y - 1] == '1' || all->map[all->position_o[i].x][all->position_o[i].y - 1] == 'O')
        return;
    if (all->prev_elemnt[i] == EXIT_E)
    {
        all->map[all->position_o[i].x][all->position_o[i].y] = 'E';
        mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_exit_close, all->position_o[i].y * IMG_WIDTH , all->position_o[i].x * IMG_HEIGHT);
         all->prev_elemnt[i] = 1337;
    }
    else if (all->prev_elemnt[i] == COINS_E)
    {
        all->map[all->position_o[i].x][all->position_o[i].y] = 'C';
        mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_coin, all->position_o[i].y * IMG_WIDTH , all->position_o[i].x * IMG_HEIGHT);
         all->prev_elemnt[i] = 1337;
    }
    else
    {
        all->map[all->position_o[i].x][all->position_o[i].y] = '0';
        mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_floor, all->position_o[i].y * IMG_WIDTH , all->position_o[i].x * IMG_HEIGHT);
    }
    if (all->map[all->position_o[i].x][all->position_o[i].y - 1] == 'C')
        all->prev_elemnt[i] = COINS_E;
    else if (all->map[all->position_o[i].x][all->position_o[i].y - 1] == 'E')
        all->prev_elemnt[i] = EXIT_E;
    else if (all->map[all->position_o[i].x][all->position_o[i].y - 1] == 'P')
        free_all_bonus(all, LOSE_GAME);
    all->map[all->position_o[i].x][--all->position_o[i].y] = 'O';
    all->direction_o[i] = LEFT_D;
}

void    move_right_enemy(t_info *all, int i)
{
    if (all->map[all->position_o[i].x][all->position_o[i].y + 1] == '1' || all->map[all->position_o[i].x][all->position_o[i].y + 1] == 'O')
        return;
    if (all->prev_elemnt[i] == EXIT_E)
    {
        all->map[all->position_o[i].x][all->position_o[i].y] = 'E';
        mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_exit_close, all->position_o[i].y * IMG_WIDTH , all->position_o[i].x * IMG_HEIGHT);
        all->prev_elemnt[i] = 1337;
    }
    else if (all->prev_elemnt[i] == COINS_E)
    {
        all->map[all->position_o[i].x][all->position_o[i].y] = 'C';
        mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_coin, all->position_o[i].y * IMG_WIDTH , all->position_o[i].x * IMG_HEIGHT);
        all->prev_elemnt[i] = 1337;
    }
    else
    {
        all->map[all->position_o[i].x][all->position_o[i].y] = '0';
        mlx_put_image_to_window(all->mlx, all->mlx_new_win, all->image->img_floor, all->position_o[i].y * IMG_WIDTH , all->position_o[i].x * IMG_HEIGHT);
    }
    if (all->map[all->position_o[i].x][all->position_o[i].y + 1] == 'C')
        all->prev_elemnt[i] = COINS_E;
    else if (all->map[all->position_o[i].x][all->position_o[i].y + 1] == 'E')
        all->prev_elemnt[i] = EXIT_E;
    else if (all->map[all->position_o[i].x][all->position_o[i].y + 1] == 'P')
        free_all_bonus(all, LOSE_GAME);
    all->map[all->position_o[i].x][++all->position_o[i].y] = 'O';
    all->direction_o[i] = RIGHT_D;
}

int    move_enemy(t_info *all)
{
    static clock_t last_move_time = 0;
    clock_t current_time = clock();
    double elapsed_time = (double)(current_time - last_move_time) / CLOCKS_PER_SEC * 1000;

    if (elapsed_time < 200)
        return (0);

    last_move_time = current_time;

    int direction;
    int i;

    i = 0;
    while (i < all->how_many_O)
    {
        direction = rand() % 4;
        if (direction == 0)
            move_right_enemy(all, i);
        else if (direction == 1)
            move_left_enemy(all, i);
        else if (direction == 2)
            move_up_enemy(all, i);
        else if (direction == 3)
            move_down_enemy(all, i);
        i++;
    }

    return (0);
}

int animate_move(t_info *all)
{
    move_enemy(all);
    animate(all);
    return (0);
}
