/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sariee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:46:00 by sariee            #+#    #+#             */
/*   Updated: 2025/12/15 22:33:07 by sariee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		ft_error_exit("Usage: ./so_long <map.ber>", NULL);
		return (1);
	}
	check_file_extension(av[1]);
	ft_init_game(&game);
	ft_read_map_file(av[1], &game);
	validate_map(&game);
	init_mlx(&game);
	load_textures(&game);
	render_map(&game);
	mlx_hook(game.window, 2, 1L << 0, handle_keypress, &game);
	mlx_hook(game.window, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
