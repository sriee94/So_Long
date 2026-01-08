/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sariee <sariee@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:42:14 by rsam94            #+#    #+#             */
/*   Updated: 2025/04/23 15:06:44 by sariee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsriee.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = dst;
	s = src;
	i = 0;
	if (!dst || !src)
		return (dst);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
/*
#include <stdio.h>
int	main()
{
	char dst[20];
	char src[] = "Salut ca va";
	char dst2[20];

	printf("%s\n", dst);
	memcpy(dst, src, 5);
	printf("%s\n", dst);
	printf("%s\n", dst2);
	ft_memcpy(dst2, src, 5);
	printf("%s\n", dst2);
}*/