#include "so_long.h"

enum e_map
{
    complete_wall,
    only_one_exit,
    atlist_one_collecter,
    starting_position
};
int    ft_len(char *str)
{
    int i;

    i = 0;
    if (!str)
        return (i);
    while (str[i])
        i++;
    return (i);
}
void check_errors_of_map(char **map)
{
    if (!map[0])
    {
        free_map(map);
        exit(1);
    }
    check_is_rectangular(map);
    check_elemnts(map);
    check_the_state_of_wall(map);
    flood_fill(map);
}

int main(int ac, char **av)
{
    char **map;

    int (fd), (i), (lenght);
    if (ac == 2)
    {
        check_extension(av);
        lenght = lenght_of_map();
        map = malloc((lenght + 1) * sizeof(char *));
        if (!map)
            return (-1);
        fd = open(av[1], O_RDWR);
        if (fd == -1)
            return (free(map), -1);
        i = 0;
        map[i] = get_next_line(fd);
        while(map[i])
        {
            i++;
            map[i] = get_next_line(fd);
        }
        map[i] = NULL;
        check_errors_of_map(map);
        close(fd);
        free_map(map);
    }
}
