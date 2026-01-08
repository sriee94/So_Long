/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sariee <sariee@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 01:20:08 by rsam94            #+#    #+#             */
/*   Updated: 2025/04/23 15:33:31 by sariee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsriee.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*tmpdst;
	const unsigned char	*tmpsrc;
	size_t				i;

	if (!dst || !src)
		return (0);
	tmpdst = dst;
	tmpsrc = src;
	if (tmpdst > tmpsrc && tmpdst < tmpsrc + len)
	{
		while (len--)
		{
			tmpdst[len] = tmpsrc[len];
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			tmpdst[i] = tmpsrc[i];
			i++;
		}
	}
	return (dst);
}
/* #include <stdio.h>
int	main()
{
	char str1[50] = "Hello, World!";
	char str2[50] = "Hello, World!";
	
	printf("Avant ft_memmove : %s\n", str1);
	ft_memmove(str1 + 7, str1, 5);
	printf("Après ft_memmove : %s\n", str1);

	printf("\nAvant memmove : %s\n", str2);
	memmove(str2 + 7, str2, 5);
	printf("Après memmove : %s\n", str2);

	return 0;
} */