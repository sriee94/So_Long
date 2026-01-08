/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sariee <sariee@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:13:44 by sariee            #+#    #+#             */
/*   Updated: 2025/04/23 10:50:00 by sariee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsriee.h"

static char	*ft_tab(char *tab, int len, int nombre)
{
	while (nombre > 0)
	{
		len--;
		tab[len] = ((nombre % 10) + 48);
		nombre = nombre / 10;
	}
	return (tab);
}

static int	len_n(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != '\0')
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*tab;
	long	nombre;

	len = len_n(n);
	nombre = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	tab = malloc(sizeof(char) * (len + 1));
	if (!tab)
		return (NULL);
	tab[len] = '\0';
	if (nombre == 0)
	{
		tab[0] = '0';
		return (tab);
	}
	if (nombre < 0)
	{
		tab[0] = '-';
		nombre = -nombre;
	}
	if (nombre > 0)
		return (ft_tab(tab, len, nombre));
	return (tab);
}
/*int	main()
{
	int n = -24547629;

	printf("%s\n", ft_itoa(n));
}*/