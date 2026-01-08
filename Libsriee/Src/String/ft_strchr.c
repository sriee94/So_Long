/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sariee <sariee@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:35:55 by rsam94            #+#    #+#             */
/*   Updated: 2025/05/15 11:54:13 by sariee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsriee.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == (char)c)
			return ((char *) &s[i]);
		i++;
	}
	if (s && s[i] == (char)c)
		return ((char *) &s[i]);
	return (NULL);
}
/* #include <string.h>
#include <stdio.h>
int	main()
{
	const char *s = "Hello Wrold";
	char c = '\0';
	char *result = strchr(s, c);
	char *res = ft_strchr(s, c);

	printf("%s\n", result);
	printf("%s\n", res);
	return (0);
} */