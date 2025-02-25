/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <mfahmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:10:37 by mfahmi            #+#    #+#             */
/*   Updated: 2025/02/25 15:32:58 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void    submit_data_map_bonus(t_info *all)
{
        int fd, i;

        fd = open(all->name_of_map, O_RDWR);
        if (fd == -1)
        {
            free_data_bonus(all);
            exit(1);
        }
        i = 0;
        all->map[i] = get_next_line(fd);
        while(all->map[i])
        {
            i++;
            all->map[i] = get_next_line(fd);
        }
        all->map[i] = NULL;
        close(fd);
}

void    count_hight_width_bonus(t_info *all)
{
    all->dimensions->width = all->lenght_of_map;
    all->dimensions->height = ft_len(all->map[0]) - 1; //* -1 for the new line
}
static int	count_nm(long n)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n > 9)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int nm)
{
	char	*str;
	int		i;
	int		is_neg;
	long	n;

	n = nm;
	i = count_nm(n) - 1;
	is_neg = 0;
	str = malloc((i + 2) * sizeof(char));
	if (!str)
		return (NULL);
	str[i + 1] = '\0';
	if (n < 0)
	{
		str[is_neg++] = '-';
		n = -n;
	}
	while (i >= is_neg)
	{
		str[i] = (n % 10) + 48;
		n /= 10;
		i--;
	}
	return (str);
}

void    str_window(t_info *all)
{
    char *str;
    str = ft_itoa(++all->moves_count);
    mlx_put_image_to_window(all->mlx,  all->mlx_new_win, all->image->img_str, 0 , 0);
    mlx_string_put (all->mlx, all->mlx_new_win, 20, 15, 0x000000, str);
    free(str);
}
