/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:47:47 by usuario           #+#    #+#             */
/*   Updated: 2025/10/30 12:37:27 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunsigned(unsigned int num, size_t *count)
{
	if (num >= 10)
		ft_putunsigned(num / 10, count);
	ft_putchar((num % 10) + '0', count);
}
