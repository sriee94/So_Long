/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sariee <sariee@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 22:50:13 by sariee            #+#    #+#             */
/*   Updated: 2025/12/12 01:24:28 by sariee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_free_map_copy(char **map_copy)
{
	int	i;

	if (!map_copy)
		return ;
	i = -1;
	while (map_copy[++i])
		free(map_copy[i]);
	free(map_copy);
}

static char	**copy_map(t_game *game)
{
	char	**copy;
	int		i;

	copy = ft_calloc(game->map.height + 1, sizeof(char *));
	if (!copy)
		return (NULL);
	i = -1;
	while (++i < game->map.height)
	{
		copy[i] = ft_strdup(game->map.grid[i]);
		if (!copy[i])
		{
			ft_free_map_copy(copy);
			return (NULL);
		}
	}
	return (copy);
}

static void	flood_fill(char **map, int x, int y, t_game *game)
{
	if (x < 0 || x >= game->map.width || y < 0 || y >= game->map.height)
		return ;
	if (map[y][x] == '1')
		return ;
	if (map[y][x] == 'v' || map[y][x] == 'c' || map[y][x] == 'e')
		return ;
	if (map[y][x] == 'C')
		map[y][x] = 'c';
	else if (map[y][x] == 'E')
		map[y][x] = 'e';
	else
		map[y][x] = 'v';
	flood_fill(map, x, y - 1, game);
	flood_fill(map, x, y + 1, game);
	flood_fill(map, x - 1, y, game);
	flood_fill(map, x + 1, y, game);
}

int	check_path(t_game *game)
{
	char	**map_copy;
	int		x;
	int		y;

	map_copy = copy_map(game);
	if (!map_copy)
		return (0);
	flood_fill(map_copy, game->map.pos_player_x, game->map.pos_player_y, game);
	y = -1;
	while (++y < game->map.height)
	{
		x = -1;
		while (++x < game->map.width)
		{
			if (map_copy[y][x] == 'C' || map_copy[y][x] == 'E')
			{
				ft_free_map_copy(map_copy);
				return (0);
			}
		}
	}
	ft_free_map_copy(map_copy);
	return (1);
}
