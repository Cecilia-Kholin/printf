/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:48:10 by usuario           #+#    #+#             */
/*   Updated: 2025/11/03 11:45:08 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// prinf("hola %s\n", var);
#include "ft_printf.h"

void	check_format(va_list va, char *str, size_t *count)
{
	if (*str == 'c')
		ft_putchar(va_arg(va, int), count);
	else if (*str == 's')
		ft_putstr(va_arg(va, char *), count);
	else if (*str == 'd' || *str == 'i')
		ft_putnbr(va_arg(va, int), count);
	else if (*str == 'u')
		ft_putunsigned(va_arg(va, unsigned int), count);
	else if (*str == 'p')
		ft_hex(va_arg(va, char *), count);
	else if (*str == 'x')
		ft_hex_min(va_arg(va, unsigned int), count, 1);
	else if (*str == 'X')
		ft_hex_min(va_arg(va, unsigned int), count, 0);
	else
		ft_putchar('%', count);
}

int	ft_printf(char const *fm, ...)
{
	size_t	count;
	va_list	args;

	if (!fm)
		return (0);
	va_start(args, fm);
	count = 0;
	while (*fm)
	{
		if (*fm == '%')
		{
			fm++;
			check_format(args, (char *)fm, &count);
			fm++;
		}
		else
		{
			count++;
			write(1, fm, 1);
			fm++;
		}
	}
	va_end(args);
	return (count);
}
