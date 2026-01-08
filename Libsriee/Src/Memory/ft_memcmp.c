/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sariee <sariee@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 08:09:26 by rsam94            #+#    #+#             */
/*   Updated: 2025/04/23 15:06:20 by sariee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsriee.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*tmp1;
	unsigned const char	*tmp2;
	size_t				i;

	if (!s1 || !s2 || n == 0)
		return (0);
	tmp1 = s1;
	tmp2 = s2;
	i = 0;
	while (i < n)
	{
		if (tmp1[i] != tmp2[i])
			return (tmp1[i] - tmp2[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
int	main()
{
	char s1[] = "Bonjour";
	char s2[] = "Bonpour";

	int	result = ft_memcmp(s1, s2, 4);
	int resultat = memcmp(s1, s2, 4);
	printf("%d\n", result);
	printf("%d\n", resultat);
}*/