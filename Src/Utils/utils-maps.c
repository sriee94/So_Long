/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils-maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sariee <sariee@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:55:50 by sariee            #+#    #+#             */
/*   Updated: 2025/12/12 23:31:12 by sariee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_char(char c)
{
	if (c == 'P' || c == 'E' || c == 'C' || c == '0' || c == '1')
		return (1);
	return (0);
}

void	process_char(char c, t_counts *counts)
{
	if (c == 'P')
		counts->p++;
	else if (c == 'E')
		counts->e++;
	else if (c == 'C')
		counts->c++;
}

int	validate_counts(t_counts *counts, t_game *game)
{
	if (counts->p != 1)
		return (0);
	if (counts->e != 1)
		return (0);
	if (counts->c < 1)
		return (0);
	game->map.collectible = counts->c;
	return (1);
}
