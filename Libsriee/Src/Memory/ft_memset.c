/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sariee <sariee@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:54:06 by samuelriee        #+#    #+#             */
/*   Updated: 2025/04/25 16:58:25 by sariee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsriee.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	tmp;
	unsigned char	*tmpb;
	size_t			i;

	tmp = c;
	tmpb = b;
	i = 0;
	if (!b)
		return (NULL);
	while (i < len)
	{
		tmpb[i] = tmp;
		i++;
	}
	b = tmpb;
	return (b);
}
/* #include <stdio.h>
int	main()
{
	char buffer[] = "gsdergrgeas6543gfd";

	ft_memset(buffer, 'b', sizeof(buffer));
	printf("%s\n", buffer);
	memset(buffer, 'b', sizeof(buffer));
	printf("%s\n", buffer);
	return (0);
} */