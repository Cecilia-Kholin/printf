/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 10:21:21 by usuario           #+#    #+#             */
/*   Updated: 2025/11/03 10:23:51 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

int		ft_printf(char const *fm, ...);
void	ft_putchar(char c, size_t *counter);
void	ft_putstr(char *str, size_t *count);
void	ft_putnbr(int num, size_t *count);
void	ft_putunsigned(unsigned int num, size_t *count);
void	ft_hex(void *str, size_t *count);
void	ft_hex_min(unsigned int num, size_t *count, int var);

#endif