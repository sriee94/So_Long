/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sariee <sariee@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:05:46 by sariee            #+#    #+#             */
/*   Updated: 2025/12/31 15:01:45 by sariee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsriee.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*tab;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	tab = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
		tab[i++] = s2[j++];
	tab[i] = '\0';
	return (tab);
}
/*
#include <stdio.h>
int	main()
{
	char *tab;
	char *s1 = NULL;
	char *s2 = NULL;
	tab = ft_strjoin(s1, s2);
	printf("%s\n", tab);
	free(tab);
}*/
