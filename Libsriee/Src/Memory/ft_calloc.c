/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sariee <sariee@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:56:30 by samuelriee        #+#    #+#             */
/*   Updated: 2025/04/25 16:23:41 by sariee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsriee.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tab;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	tab = malloc(count * size);
	if (tab == NULL)
	{
		return (NULL);
	}
	ft_memset(tab, 0, count * size);
	return (tab);
}
/* #include <stdio.h>

int main(void)
{
	int		*arr;
	size_t	i = 0;
	size_t	count = 10;

	arr = (int *)ft_calloc(count, sizeof(int));
	if (arr == NULL)
	{
		printf("Échec de l'allocation mémoire\n");
		return (1);
	}

	printf("Valeurs du tableau après ft_calloc :\n");
	while (i < count)
	{
		printf("%d\n", arr[i]);
		i++;
	}
	free(arr);
	return 0;
} */
