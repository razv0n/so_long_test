/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utilis_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:04:16 by mfahmi            #+#    #+#             */
/*   Updated: 2024/12/01 15:04:17 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	hexa_p(unsigned long nm)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789abcdef";
	if (nm < 16)
		count += ft_putchar(base[nm]);
	else
	{
		count += hexa_p(nm / 16);
		count += hexa_p(nm % 16);
	}
	return (count);
}
