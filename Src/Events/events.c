/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sariee <sariee@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 21:28:12 by sariee            #+#    #+#             */
/*   Updated: 2025/12/13 18:06:55 by sariee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_game *game)
{
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->floor)
		mlx_destroy_image(game->mlx, game->floor);
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->collectible)
		mlx_destroy_image(game->mlx, game->collectible);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	ft_free_map(game);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(0);
	return (0);
}

static int	is_valid_move(t_game *game, int new_x, int new_y)
{
	char	tile;

	tile = game->map.grid[new_y][new_x];
	if (tile == '1')
		return (0);
	return (1);
}

static void	move_player(t_game *game, int new_x, int new_y)
{
	char	tile;

	tile = game->map.grid[new_y][new_x];
	if (game->map.pos_player_x == game->map.pos_exit_x
		&& game->map.pos_player_y == game->map.pos_exit_y)
		game->map.grid[game->map.pos_player_y][game->map.pos_player_x] = 'E';
	else
		game->map.grid[game->map.pos_player_y][game->map.pos_player_x] = '0';
	game->map.grid[new_y][new_x] = 'P';
	if (tile == 'C')
		game->collected_c++;
	if (tile == 'E' && game->collected_c == game->map.collectible)
		close_game(game);
	game->map.pos_player_y = new_y;
	game->map.pos_player_x = new_x;
	game->moves++;
	render_map(game);
	display_moves(game);
}

int	handle_keypress(int keycode, void *param)
{
	t_game	*game;
	int		new_x;
	int		new_y;

	game = (t_game *)param;
	if (keycode == KEY_ESC)
		close_game(game);
	new_x = game->map.pos_player_x;
	new_y = game->map.pos_player_y;
	if (keycode == KEY_W)
		new_y--;
	else if (keycode == KEY_S)
		new_y++;
	else if (keycode == KEY_A)
		new_x--;
	else if (keycode == KEY_D)
		new_x++;
	else
		return (0);
	if (is_valid_move(game, new_x, new_y))
		move_player(game, new_x, new_y);
	return (0);
}
