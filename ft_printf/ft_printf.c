/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:04:04 by mfahmi            #+#    #+#             */
/*   Updated: 2024/12/01 15:04:07 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	specifier(char c, va_list arg)
{
	int	count;

	count = 0;
	if (c == 'p')
		count += hexa_ptr(va_arg(arg, void *));
	else if (c == 'c')
		count += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		count += ft_putstr(va_arg(arg, char *));
	else if (c == 'x')
		count += hexa(va_arg(arg, unsigned int), 0);
	else if (c == 'X')
		count += hexa(va_arg(arg, unsigned int), 1);
	else if (c == 'u')
		count += unsi_putnbr(va_arg(arg, unsigned int));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(arg, int));
	else if (c == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	arg;

	if (!format)
		return (-1);
	count = 0;
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!*format)
				return (-1);
			count += specifier(*format, arg);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(arg);
	return (count);
}
// #include <stdio.h>
// int main()
// {
//     //int a = 20123;
//     // int *b =  &a;
//     //int *b = &a;
//     // void * = 32bit && 64bit   32bit -> 4byte , 64bit -> 8byte
// 	//unsigned long == size memory in any arch // __uintptr_t
//     //printf("%d\n",(uintptr_t) b);
//    // printf("%x\n",(uintptr_t) b);
//     //printf("%p\n",b);
//     // printf("%d\n",printf
// 	ft_printf ("%d",ft_printf("%%%%"));
//     //    ft_printf("%p\n %s\n %d\n %u\n %%",0, NULL, 2147483647, -1);
//        //ft_printf("\n%p\n",&a);
//     //    printf ("%u\n",b);
// }
