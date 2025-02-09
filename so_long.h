#ifndef SO_LONG_H
#define SO_LONG_H

#include "mlx.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <math.h>

#include <stdio.h>


int lenght_of_map();

void    check_is_rectangular(char **map);
void    flood_fill(char **map);
int ft_print(char   *str, int std);
int    ft_len(char *str);
void    display_error(int count_E, int count_C, int count_P);
void    check_elemnts(char **map);
void    check_the_state_of_wall(char **map);
void    check_extension(char **str);
int	ft_strcmp(const char *s1, char *s2);




#endif