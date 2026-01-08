/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sariee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 19:56:37 by sariee            #+#    #+#             */
/*   Updated: 2025/12/12 23:46:29 by sariee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_count_lines(char *filename)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error_exit("Impossible d'ouvrir le fichier.", NULL);
	count = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

void	ft_read_map_file(char *filename, t_game *game)
{
	int		i;
	int		fd;
	int		len;
	char	*line;

	game->map.height = ft_count_lines(filename);
	game->map.grid = ft_calloc(game->map.height + 1, sizeof(char *));
	if (!game->map.grid)
		ft_error_exit("Probleme d'allocation de memoire.", game);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error_exit("Probleme d'ouverture du fichier.", game);
	i = -1;
	while (++i < game->map.height)
	{
		line = get_next_line(fd);
		if (!line)
			ft_error_exit("Erreur de lecture.", game);
		len = ft_strlen(line);
		if (line[len - 1] == '\n')
			line[len - 1] = '\0';
		game->map.grid[i] = line;
	}
	game->map.width = ft_strlen(game->map.grid[0]);
	close(fd);
}
