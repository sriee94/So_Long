/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sariee <sariee@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:47:31 by rsam94            #+#    #+#             */
/*   Updated: 2025/04/23 15:36:08 by sariee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsriee.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*res;
	char			cc;

	cc = (char)c;
	res = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
			res = (char *)&s[i];
		i++;
	}
	if (s[i] == cc)
		res = (char *)&s[i];
	return (res);
}
/*
#include <stdio.h>
int	main()
{ 
	const char *s = "bite";
	char c = '\0';
	char *result = strrchr(s, c);
	char *res = ft_strrchr(s, c);

	printf("%s\n", result);
	printf("%s\n", res);
	return (0);
}*/