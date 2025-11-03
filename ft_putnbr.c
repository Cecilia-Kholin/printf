/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 10:52:49 by usuario           #+#    #+#             */
/*   Updated: 2025/11/03 10:08:45 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int num, size_t *count)
{
	if (num == -2147483648)
	{
		ft_putnbr((num / 10), count);
		ft_putchar('8', count);
	}
	else if (num < 0)
	{
		ft_putchar('-', count);
		ft_putnbr(-num, count);
	}
	else
	{
		if (num > 9)
			ft_putnbr((num / 10), count);
		ft_putchar(('0' + num % 10), count);
	}
}
