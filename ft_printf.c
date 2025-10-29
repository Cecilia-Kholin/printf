/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:48:10 by usuario           #+#    #+#             */
/*   Updated: 2025/10/29 23:11:52 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// prinf("hola %s\n", var);
#include <stdarg.h> // para usar va_list
#include <unistd.h> // para usar write

void	check_format(va_list va, char *str, size_t *count)
{
	char	*s;
	char	c;
	int		i;

	i = 0;
	if (*str == 'c')
	{
		c = va_arg(va, int);
		write(1, &c, 1);
		(*count)++;
	}
	if (*str == '%')
	{
		write(1, str, 1);
		(*count)++;
	}
	s = va_arg(va, char *);
	if (s == NULL)
        s = "(null)"; 
	if (*str == 's')
	{
		while (s[i])
		{
			write(1, &s[i], 1);
			(*count)++;
			i++;
		}
	}
}

int	ft_printf(char const *fm, ...)
{
	size_t	count;
	int		j;
	va_list	args;

	if (!fm)
		return (0);
	va_start(args, fm);
	count = 0;
	j = 0;
	while (*fm)
	{
		if (*fm == '%')
		{
			fm++;
			check_format(args, (char *)fm, &count);
			fm++;
		}
		count++;
		write(1, fm, 1);
		fm++;

	}
	va_end(args);
	return (count);
}
#include <stdio.h>  
int main(void)
{
	int total1, total2;
	char c = 'A';
	char *str = "42Madrid";
	int num = -12345;
	unsigned int unum = 4294967295u;
	void *ptr = str;

   // 1️⃣ Básicos
	//total1 = ft_printf("Hola Mundo\n");
	//total2 = printf("Hola Mundo\n");
   // printf("Retornos: ft=%d  printf=%d\n\n", total1, total2);

	// 2️⃣ %c y %%
	total1 = ft_printf("Caracter: %c y porcentaje: %%\n", c);
	total2 = printf("Caracter: %c y porcentaje: %%\n", c);
	printf("Retornos: ft=%d  printf=%d\n\n", total1, total2);

	// 3️⃣ %s
	total1 = ft_printf("Cadena: %s y NULL: %s\n", str, (char *)NULL);
	total2 = printf("Cadena: %s y NULL: %s\n", str, (char *)NULL);
	printf("Retornos: ft=%d  printf=%d\n\n", total1, total2);

	// 4️⃣ %d y %i
	total1 = ft_printf("Enteros: %d y %i\n", num, 42);
	total2 = printf("Enteros: %d y %i\n", num, 42);
	printf("Retornos: ft=%d  printf=%d\n\n", total1, total2);

	// 5️⃣ %u
	//total1 = ft_printf("Unsigned: %u\n", unum);
	//total2 = printf("Unsigned: %u\n", unum);
	//printf("Retornos: ft=%d  printf=%d\n\n", total1, total2);

	// 6️⃣ %x y %X
	//total1 = ft_printf("Hexa min: %x - MAYUS: %X\n", 3735928559u, 3735928559u);
	//total2 = printf("Hexa min: %x - MAYUS: %X\n", 3735928559u, 3735928559u);
	//printf("Retornos: ft=%d  printf=%d\n\n", total1, total2);

	// 7️⃣ %p
	//total1 = ft_printf("Puntero: %p y NULL: %p\n", ptr, (void*)0);
	//total2 = printf("Puntero: %p y NULL: %p\n", ptr, (void*)0);
	//printf("Retornos: ft=%d  printf=%d\n\n", total1, total2);

	return 0;
}
