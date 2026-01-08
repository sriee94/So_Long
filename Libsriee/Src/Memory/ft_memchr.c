/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sariee <sariee@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:47:06 by rsam94            #+#    #+#             */
/*   Updated: 2025/04/25 17:04:26 by sariee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsriee.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		tmp;
	unsigned const char	*tmps;
	size_t				i;

	tmp = c;
	tmps = s;
	i = 0;
	while (i < n)
	{
		if (tmps[i] == tmp)
			return ((void *)tmps + i);
		i++;
	}
	return (NULL);
}
/* #include <stdio.h>
int	main()
{
	char *str = "salut jonathan ";
	char ch = 'o';
	char *res = ft_memchr(str, ch, sizeof(str));
	char *resultat = memchr(str, ch, sizeof(str));

	printf("%s\n", res);
	printf("%s\n", resultat);
	return (0);
} */