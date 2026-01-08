/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sariee <sariee@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:06:39 by rsam94            #+#    #+#             */
/*   Updated: 2025/04/23 10:47:18 by sariee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsriee.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}
/* #include <stdio.h>
#include <ctype.h>
int	main()
{
	printf("%d\n", ft_toupper(-1));
	printf("%d\n", toupper(-1));
	return (0);
} */