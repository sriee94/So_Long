/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sariee <sariee@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:11:37 by sariee            #+#    #+#             */
/*   Updated: 2025/12/31 17:07:55 by sariee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsriee.h"

int	ft_putnbr(int n)
{
	long	i;
	int		len;

	len = 0;
	i = n;
	if (i < 0)
	{
		len += ft_putchar('-');
		i = -i;
	}
	if (i > 9)
		len += ft_putnbr(i / 10);
	len += ft_putchar((i % 10) + 48);
	return (len);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int	len;

	len = 0;
	if (n > 9)
		len += ft_putnbr_unsigned(n / 10);
	len += ft_putchar((n % 10) + 48);
	return (len);
}
