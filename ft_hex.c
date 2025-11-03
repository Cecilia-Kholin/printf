/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:47:47 by usuario           #+#    #+#             */
/*   Updated: 2025/11/03 12:05:53 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hex(void *str, size_t *count)
{
	char	*hex;
	char	buf[20];
	int		i;
	unsigned long long	n;

	i = 0;
	n = (unsigned long long)str;
	hex = "0123456789abcdef";
	write(1, "0x", 2);
	*count += 2;
	if (str == 0)
	{
		write(1, "(nil)", 5);
		(*count) += 5;
		return ;
	}
	while (n > 0)
	{
		buf[i++] = hex[n % 16];
		n /= 16;
		(*count)++;
	}
	while (i--)
		write(1, &buf[i], 1);
}
