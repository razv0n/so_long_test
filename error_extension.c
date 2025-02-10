
#include "so_long.h"
void    check_elemts(char **map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if(map[i][j] == 'C' || map[i][j] == 'E' || map[i][j] == 'P')
            {
                free_map(map);
                perror("Error\n");
                exit(1);                
            }
            j++;
        }
        i++;
    }   
}
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

void    flood_fill_aux(char **map, int i, int j)
{
    if (i < 0 || j < 0  || !map[i] || !map[i][j] || map[i][j] == '1' || map[i][j] == 'F')
        return;
    map[i][j] = 'F';
    flood_fill_aux(map, i + 1, j);
    flood_fill_aux(map, i - 1, j);
    flood_fill_aux(map, i, j + 1);
    flood_fill_aux(map, i, j - 1);

}

void    flood_fill(char **map)
{
    
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if(map[i][j] == 'P')
                break;
            j++;
        }
        if(map[i][j] == 'P')
            break;        
        i++;
    }
    flood_fill_aux(map, i, j);
    check_elemts(map);
}
