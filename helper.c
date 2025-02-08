#include "so_long.h"

int ft_print(char *str, int std)
{
    int i;

    i = 0;
    if (!str)
        return (0);
    while (str[i])
    {
        write(std, &str[i], 1);
        i++;
    }
    return (1);
}

int	ft_strcmp(const char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}