/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sariee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 19:25:57 by sariee            #+#    #+#             */
/*   Updated: 2025/12/13 17:32:22 by sariee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_exit(char *message, t_game *game)
{
	ft_putendl_fd("Error", 2);
	if (message)
		ft_putendl_fd(message, 2);
	if (game && game->map.grid)
		ft_free_map(game);
	exit(1);
}

void	ft_init_game(t_game *game)
{
	game->mlx = NULL;
	game->window = NULL;
	game->wall = NULL;
	game->floor = NULL;
	game->player = NULL;
	game->collectible = NULL;
	game->exit = NULL;
	game->moves = 0;
	game->collected_c = 0;
	game->map.grid = NULL;
	game->map.width = 0;
	game->map.height = 0;
	game->map.pos_player_x = 0;
	game->map.pos_player_y = 0;
	game->map.pos_exit_x = 0;
	game->map.pos_exit_y = 0;
	game->map.collectible = 0;
}

void	ft_free_map(t_game *game)
{
	int	i;

	if (!game->map.grid)
		return ;
	i = 0;
	while (i < game->map.height)
	{
		if (game->map.grid[i] != NULL)
			free (game->map.grid[i]);
		i++;
	}
	free(game->map.grid);
	game->map.grid = NULL;
}

void	check_file_extension(char *filename)
{
	int		len;
	char	*extension;

	len = ft_strlen(filename);
	if (len < 5)
		ft_error_exit("Le fichier est trop court.", NULL);
	extension = &filename[len - 4];
	if (ft_strncmp(extension, ".ber", 4) != 0)
		ft_error_exit("Le fichier n'a pas l'extension .ber.", NULL);
}
