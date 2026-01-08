/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sariee <sariee@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:55:53 by sariee            #+#    #+#             */
/*   Updated: 2025/04/25 14:41:52 by sariee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsriee.h"

static char	**ft_free(char **tab, int i)
{
	while (i-- > 0)
		free(tab[i]);
	free(tab);
	return (NULL);
}

static char	*ft_stredup(const char *s, size_t size)
{
	char	*dest;
	size_t	i;

	if (size == 0)
	{
		dest = malloc(sizeof(char));
		if (!dest)
			return (NULL);
		dest[0] = '\0';
		return (dest);
	}
	dest = malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < size && s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static size_t	ft_words(const char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;
	size_t	start;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (ft_words(s, c) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] && j < ft_words(s, c))
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		tab[j] = ft_stredup(&s[start], i - start);
		if (!tab[j++])
			return (ft_free(tab, j--));
	}
	tab[j] = NULL;
	return (tab);
}
/* 
#include <stdio.h>

int	main()
{
	char *str = "          Bonjour comment vous allez les enfants ";
	char c = ' ';
	size_t i = 0;
	size_t j = 0;
	char **tab = ft_split(str, c);

	while (tab[i] != NULL)
	{
		printf("\n%s", tab[i]);
		i++;
	}
	while (tab[j])
	{
		free(tab[j]);
		j++;
	}
	free(tab);
	return (0);
}
 */