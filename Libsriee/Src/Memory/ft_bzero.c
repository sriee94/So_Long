/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sariee <sariee@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 00:20:31 by rsam94            #+#    #+#             */
/*   Updated: 2025/04/23 10:50:29 by sariee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsriee.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*tmps;
	size_t			i;

	if (n == 0)
		return ;
	tmps = s;
	i = 0;
	while (i < n)
	{
		tmps[i] = 0;
		i++;
	}
	s = tmps;
}
/*int	main()
{
	char *buffer = NULL;
	//char *buffer2 = NULL;

	ft_bzero(buffer, 4);
	printf("%s\n", buffer);
	//bzero(buffer2, 4);
	//printf("%s\n", buffer2);
	return (0);
}*/