/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_min.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:59:10 by usuario           #+#    #+#             */
/*   Updated: 2025/11/03 10:22:52 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_min(unsigned long long n, char *hexmin, size_t *count)
{
	char	buf[20];
	int		i;

	i = 0;
	while (n > 0)
	{
		buf[i++] = hexmin[n % 16];
		n /= 16;
		(*count)++;
	}
	while (i--)
		write(1, &buf[i], 1);
}

static void	ft_max(unsigned long long n, char *hexmax, size_t *count)
{
	char	buf[20];
	int		i;

	i = 0;
	while (n > 0)
	{
		buf[i++] = hexmax[n % 16];
		n /= 16;
		(*count)++;
	}
	while (i--)
		write(1, &buf[i], 1);
}

void	ft_hex_min(unsigned int num, size_t *count, int var)
{
	char				*hexmin;
	char				*hexmax;
	unsigned long long	n;

	n = (unsigned long long)num;
	hexmin = "0123456789abcdef";
	hexmax = "0123456789ABCDEF";
	if (n == 0)
	{
		write(1, "0", 1);
		(*count)++;
	}
	if (var == 1)
	{
		ft_min(n, hexmin, count);
	}
	else
	{
		ft_max(n, hexmax, count);
	}
}
