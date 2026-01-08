/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sariee <sariee@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:23:56 by rsam94            #+#    #+#             */
/*   Updated: 2025/04/23 15:35:37 by sariee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsriee.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = ft_strlen(src);
	if (i + 1 < dstsize)
		ft_memcpy(dst, src, i + 1);
	else if (dstsize != 0)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = 0;
	}
	return (i);
}
/*
#include <stdio.h>
int	main()
{
	char	src[] = "Jean Kevinrfgewgws";
	char	dst[10];

	printf("%zu\n", strlcpy(dst, src, 2));
	printf("%zu\n", ft_strlcpy(dst, src, 9));
	return (0);
}*/
