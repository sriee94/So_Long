/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sariee <sariee@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:03:01 by rsam94            #+#    #+#             */
/*   Updated: 2025/04/23 15:35:27 by sariee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsriee.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dst);
	j = ft_strlen(src);
	if (i >= dstsize)
		i = dstsize;
	if (i == dstsize)
		return (dstsize + j);
	if (j < dstsize - i)
		ft_memcpy(dst + i, src, j + 1);
	else
	{
		ft_memcpy(dst + i, src, dstsize - i - 1);
		dst[dstsize - 1] = '\0';
	}
	return (i + j);
}
/*
#include <stdio.h>
int	main()
{
	char dst[50] = "Hello";
	char src[50] = "Ca va ?";

	//printf("%d\n", strlcat(dst, src, 12));
	printf("%zu\n", ft_strlcat(dst, src, 12));
	return (0);
}*/