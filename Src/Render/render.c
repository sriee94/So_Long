/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sariee <sariee@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 20:11:23 by sariee            #+#    #+#             */
/*   Updated: 2025/12/12 22:59:26 by sariee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	render_tile(t_game *game, int x, int y)
{
	char	tile;
	int		px;
	int		py;

	tile = game->map.grid[y][x];
	px = x * TILE_SIZE;
	py = y * TILE_SIZE;
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->window, game->wall, px, py);
	else
	{
		mlx_put_image_to_window(game->mlx, game->window, game->floor, px, py);
		if (tile == 'P')
			mlx_put_image_to_window
				(game->mlx, game->window, game->player, px, py);
		else if (tile == 'C')
			mlx_put_image_to_window
				(game->mlx, game->window, game->collectible, px, py);
		else if (tile == 'E')
			mlx_put_image_to_window
				(game->mlx, game->window, game->exit, px, py);
	}
}

void	render_map(t_game *game)
{
	int		x;
	int		y;

	y = -1;
	while (++y < game->map.height)
	{
		x = -1;
		while (++x < game->map.width)
			render_tile(game, x, y);
	}
}

void	display_moves(t_game *game)
{
	char	*msg;

	msg = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->window, 10, 20, 0xFF0000, "Moves:");
	mlx_string_put(game->mlx, game->window, 70, 20, 0xFF0000, msg);
	free(msg);
}
