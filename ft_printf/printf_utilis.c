/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utilis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:04:22 by mfahmi            #+#    #+#             */
/*   Updated: 2024/12/01 15:04:24 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		i += ft_putstr("(null)");
		return (i);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	else if (n < 0)
	{
		n = -n;
		count += ft_putchar('-');
		count += ft_putnbr(n);
	}
	else if (n < 10)
		count += ft_putchar(n + '0');
	else
	{
		count += ft_putnbr(n / 10);
		count += ft_putnbr(n % 10);
	}
	return (count);
}

int	unsi_putnbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n < 10)
		count += ft_putchar(n + '0');
	else
	{
		count += unsi_putnbr(n / 10);
		count += unsi_putnbr(n % 10);
	}
	return (count);
}

int	hexa(unsigned int nm, int bol)
{
	int		count;
	char	*base_upper;
	char	*base_lower;

	count = 0;
	base_upper = "0123456789ABCDEF";
	base_lower = "0123456789abcdef";
	if (nm < 16)
	{
		if (bol)
			count += ft_putchar(base_upper[nm]);
		else if (!bol)
			count += ft_putchar(base_lower[nm]);
	}
	else
	{
		count += hexa(nm / 16, bol);
		count += hexa(nm % 16, bol);
	}
	return (count);
}

int	hexa_ptr(void *ptr)
{
	int				count;
	unsigned long	pt;

	count = 0;
	pt = (unsigned long)ptr;
	if (!ptr)
	{
		count += ft_putstr("(nil)");
		return (count);
	}
	count += ft_putstr("0x");
	count += hexa_p(pt);
	return (count);
}
