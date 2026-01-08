/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sariee <sariee@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:28:57 by samuelriee        #+#    #+#             */
/*   Updated: 2025/12/31 17:08:30 by sariee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsriee.h"

static int	ft_format(va_list args, char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (format == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		len += ft_putptr(va_arg(args, void *));
	else if (format == 'i' || format == 'd')
		len += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		len += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (format == 'x')
		len += ft_puthex(va_arg(args, unsigned int), 0);
	else if (format == 'X')
		len += ft_puthex(va_arg(args, unsigned int), 1);
	else if (format == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, format);
	len = 0;
	i = 0;
	if (format == NULL)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			len += ft_format(args, format[i + 1]);
			i++;
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
/*#include <stdio.h>

int main(void)
{
	int	r1;
	int	r2;
	int a;

	r1 = printf("%c\n", 'a');
	r2 = ft_printf("%c\n", 'a');
	printf("Retour printf: %d | Retour ft_printf: %d\n\n", r1, r2);
	
	r1 = printf("printf   : Char: [%c]\n", 'A');
	r2 = ft_printf("ft_printf: Char: [%c]\n", 'A');
	printf("Retour printf: %d | Retour ft_printf: %d\n\n", r1, r2);

	r1 = printf("printf   : String: [%s]\n", "Bonjour");
	r2 = ft_printf("ft_printf: String: [%s]\n", "Bonjour");
	printf("Retour printf: %d | Retour ft_printf: %d\n\n", r1, r2);

	r1 = printf(NULL);
	r2 = ft_printf(NULL);
	printf("Retour printf: %d | Retour ft_printf: %d\n\n", r1, r2);

	r1 = printf("printf   : Int: [%d] [%i]\n", 42, -42);
	r2 = ft_printf("ft_printf: Int: [%d] [%i]\n", 42, -42);
	printf("Retour printf: %d | Retour ft_printf: %d\n\n", r1, r2);

	r1 = printf("printf   : Unsigned: [%u]\n", 4294967295U);
	r2 = ft_printf("ft_printf: Unsigned: [%u]\n", 4294967295U);
	printf("Retour printf: %d | Retour ft_printf: %d\n\n", r1, r2);

	r1 = printf("printf   : Hex lower: [%x]\n", 305441741);
	r2 = ft_printf("ft_printf: Hex lower: [%x]\n", 305441741);
	printf("Retour printf: %d | Retour ft_printf: %d\n\n", r1, r2);

	r1 = printf("printf   : Hex upper: [%X]\n", 305441741);
	r2 = ft_printf("ft_printf: Hex upper: [%X]\n", 305441741);
	printf("Retour printf: %d | Retour ft_printf: %d\n\n", r1, r2);

	r1 = printf("printf   : Percent: [%%]\n");
	r2 = ft_printf("ft_printf: Percent: [%%]\n");
	printf("Retour printf: %d | Retour ft_printf: %d\n\n", r1, r2);

	a = 42;
	r1 = printf("printf   : Pointer: [%p]\n", a);
	r2 = ft_printf("ft_printf: Pointer: [%p]\n", a);
	printf("Retour printf: %d | Retour ft_printf: %d\n\n", r1, r2);

	return 0;
}*/
