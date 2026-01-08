/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sariee <sariee@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:18:15 by sariee            #+#    #+#             */
/*   Updated: 2025/04/23 12:28:12 by sariee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsriee.h"

static char	*check_tab(void)
{
	char	*tab;

	tab = malloc(sizeof(char) * 1);
	if (!tab)
		return (NULL);
	tab[0] = '\0';
	return (tab);
}

static int	is_in_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tab;
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	j = 0;
	k = ft_strlen(s1) - 1;
	if (s1[0] == '\0')
		return (check_tab());
	while (s1[j] && is_in_set(s1[j], set))
		j++;
	while (k >= j && is_in_set(s1[k], set))
		k--;
	len = (k - j) + 1;
	tab = malloc(sizeof(char) * (len + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (j <= k)
		tab[i++] = s1[j++];
	tab[i] = '\0';
	return (tab);
}
/*int main()
{
	char *s1 = "";
	char *set = "Bonjour";

	printf("%s\n", ft_strtrim(s1, set));
}*/