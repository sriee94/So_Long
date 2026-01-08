/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sariee <sariee@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 08:55:53 by rsam94            #+#    #+#             */
/*   Updated: 2025/04/25 17:24:51 by sariee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsriee.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		while (haystack[i + j] == needle[j] && haystack[i + j] && (i + j) < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *)haystack + i);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}
/* 
#include <stdio.h>
int	main()
{
	const char haystack[] = "Bonjour tout le monde";
	const char needle[] = " ";
	size_t len = 15;

	char *result = ft_strnstr(haystack, needle, len);
	//char *resultat = strnstr(haystack, needle, len);
	printf("%s\n", result);
	//printf("%s\n", resultat);
}
 */