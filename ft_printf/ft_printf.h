/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:04:30 by mfahmi            #+#    #+#             */
/*   Updated: 2024/12/01 15:04:32 by mfahmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int n);
int	unsi_putnbr(unsigned int n);
int	hexa(unsigned int nm, int bol);
int	hexa_ptr(void *ptr);
int	ft_printf(const char *format, ...);
int	hexa_p(unsigned long nm);
int	specifier(char c, va_list arg);
#endif
