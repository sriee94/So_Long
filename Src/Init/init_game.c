/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sariee <sariee@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 17:51:37 by sariee            #+#    #+#             */
/*   Updated: 2025/12/13 15:45:45 by sariee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_mlx(t_game *game)
{
	int	win_width;
	int	win_height;

	game->mlx = mlx_init();
	if (!game->mlx)
		ft_error_exit("Probleme d'initalisation de la mlx.", game);
	win_width = game->map.width * TILE_SIZE;
	win_height = game->map.height * TILE_SIZE;
	game->window = mlx_new_window(game->mlx, win_width, win_height, "so_long");
	if (!game->window)
		ft_error_exit("Erreur de creation de la fenetre.", game);
}

void	load_textures(t_game *game)
{
	int	img_width;
	int	img_height;

	game->wall = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &img_width, &img_height);
	if (!game->wall)
		ft_error_exit("Erreur de chargement de la texture du mur.", game);
	game->floor = mlx_xpm_file_to_image(game->mlx,
			"textures/floor.xpm", &img_width, &img_height);
	if (!game->floor)
		ft_error_exit("Erreur de chargement de la texture du sol.", game);
	game->player = mlx_xpm_file_to_image(game->mlx,
			"textures/player.xpm", &img_width, &img_height);
	if (!game->player)
		ft_error_exit("Erreur de chargement de la texture du joueur.", game);
	game->collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &img_width, &img_height);
	if (!game->collectible)
		ft_error_exit("Erreur de chargement de la texture des collectibles.",
			game);
	game->exit = mlx_xpm_file_to_image(game->mlx,
			"textures/exit.xpm", &img_width, &img_height);
	if (!game->exit)
		ft_error_exit("Erreur de chargement de la texture de la sortie.", game);
}
