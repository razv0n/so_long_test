#include "so_long.h"

void    check_extension(char **str)
{
    int i;

    i = 0;
    while (str[1][i])
    {
        if(str[1][i] == '.')
            break;
        i++;
    }
    if(!str[1][i] || !i || ft_strcmp(".ber", str[1] + i))
        exit(ft_print("Error\n", 2));
}

void    flood_fill(char **map)
{
    
}