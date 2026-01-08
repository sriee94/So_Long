/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sariee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:55:37 by sariee            #+#    #+#             */
/*   Updated: 2025/12/13 17:02:00 by sariee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_rectangular(t_game *game)
{
	int	i;
	int	len;

	i = 0;
	while (i < game->map.height)
	{
		len = ft_strlen(game->map.grid[i]);
		if (len != game->map.width)
			return (0);
		i++;
	}
	return (1);
}

int	check_walls(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	while (++x < game->map.width)
	{
		if ((game->map.grid[0][x] != '1')
		|| (game->map.grid[game->map.height - 1][x] != '1'))
			return (0);
	}
	y = -1;
	while (++y < game->map.height)
	{
		if ((game->map.grid[y][0] != '1')
		|| (game->map.grid[y][game->map.width - 1] != '1'))
			return (0);
	}
	return (1);
}

static void	save_position(char c, int x, int y, t_game *game)
{
	if (c == 'P')
	{
		game->map.pos_player_x = x;
		game->map.pos_player_y = y;
	}
	else if (c == 'E')
	{
		game->map.pos_exit_x = x;
		game->map.pos_exit_y = y;
	}
}

int	check_elements(t_game *game)
{
	int			x;
	int			y;
	t_counts	counts;
	char		c;

	counts.p = 0;
	counts.e = 0;
	counts.c = 0;
	x = -1;
	while (++x < game->map.width)
	{
		y = -1;
		while (++y < game->map.height)
		{
			c = game->map.grid[y][x];
			if (!is_valid_char(c))
				return (0);
			process_char(c, &counts);
			save_position(c, x, y, game);
		}
	}
	return (validate_counts(&counts, game));
}

int	validate_map(t_game *game)
{
	if (game->map.height == 0 || game->map.width == 0)
		ft_error_exit("La carte est vide.", game);
	if (!check_rectangular(game))
		ft_error_exit("La carte n'est pas rectangulaire.", game);
	if (!check_walls(game))
		ft_error_exit("La carte n'est pas entouree de murs.", game);
	if (!check_elements(game))
		ft_error_exit("Elements invalides (P, E, C).", game);
	if (!check_path(game))
		ft_error_exit("Le chemin n'est pas valide.", game);
	return (1);
}
