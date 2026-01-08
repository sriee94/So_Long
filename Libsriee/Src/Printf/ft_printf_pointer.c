/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sariee <sariee@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 20:23:51 by samuelriee        #+#    #+#             */
/*   Updated: 2025/12/31 17:08:06 by sariee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsriee.h"

static int	ft_putptr_hex(unsigned long n)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_putptr_hex(n / 16);
	len += ft_putchar("0123456789abcdef"[n % 16]);
	return (len);
}

int	ft_putptr(void *ptr)
{
	int				len;
	unsigned long	n;

	len = 0;
	n = (unsigned long)ptr;
	if (n == 0)
		len += ft_putstr("(nil)");
	else
	{
		len += ft_putstr("0x");
		len += ft_putptr_hex(n);
	}
	return (len);
}
