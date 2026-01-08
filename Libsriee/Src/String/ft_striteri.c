/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sariee <sariee@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:07:56 by sariee            #+#    #+#             */
/*   Updated: 2025/04/23 15:34:52 by sariee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsriee.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
/*void	to_upper(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 97 && *c <= 122)
		*c -= 32;
}
#include <stdio.h>
int	main()
{
	char str[] = "Bonjour les amis!";

	printf("Avant : %s\n", str);
	ft_striteri(str, to_upper);
	printf("Apres : %s\n", str);
}*/